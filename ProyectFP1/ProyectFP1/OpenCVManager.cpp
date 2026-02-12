#include "OpenCVManager.h"

OpenCVManager::OpenCVManager() {
    camaraActiva = false;
    filtroActual = TipoFiltro::SinFiltro;
    umbral = 128;
    angulo = 0;
    zoom = 1.0;
    intensidad = 1.0; // 100% por defecto para máxima intensidad
}

OpenCVManager::~OpenCVManager() {
    if (cap.isOpened())
        cap.release();
}

void OpenCVManager::reprocesarImagen() {
    if (imagenOriginal.empty())
        return;

    imagenProcesada = imagenOriginal.clone();
    aplicarFiltro();
}

void OpenCVManager::aplicarFiltro() {
    // Si la intensidad es 0, mostrar imagen original sin importar el filtro
    if (intensidad <= 0.01 && filtroActual != TipoFiltro::Rotacion && filtroActual != TipoFiltro::Zoom)
    {
        imagenProcesada = imagenOriginal.clone();
        return;
    }

    switch (filtroActual)
    {
    case TipoFiltro::SinFiltro:
        // No hacer nada, mantener imagen original tal cual
        break;

    case TipoFiltro::Grises:
    {
        cv::Mat gris;
        cv::cvtColor(imagenProcesada, gris, cv::COLOR_BGR2GRAY);
        cv::cvtColor(gris, gris, cv::COLOR_GRAY2BGR);

        // Mezclar con original según intensidad (con factor de amplificación)
        double factor = intensidad * 1.5; // Aumentar intensidad 50%
        if (factor > 1.0) factor = 1.0;
        cv::addWeighted(imagenOriginal, 1.0 - factor, gris, factor, 0, imagenProcesada);
        break;
    }

    case TipoFiltro::BinarioBN:
    {
        cv::Mat g, bin;
        cv::cvtColor(imagenProcesada, g, cv::COLOR_BGR2GRAY);
        cv::threshold(g, bin, umbral, 255, cv::THRESH_BINARY);
        cv::cvtColor(bin, bin, cv::COLOR_GRAY2BGR);

        // Mezclar con original según intensidad (con factor de amplificación)
        double factor = intensidad * 1.5; // Aumentar intensidad 50%
        if (factor > 1.0) factor = 1.0;
        cv::addWeighted(imagenOriginal, 1.0 - factor, bin, factor, 0, imagenProcesada);
        break;
    }

    case TipoFiltro::BinarioNB:
    {
        cv::Mat g, bin;
        cv::cvtColor(imagenProcesada, g, cv::COLOR_BGR2GRAY);
        cv::threshold(g, bin, umbral, 255, cv::THRESH_BINARY_INV);
        cv::cvtColor(bin, bin, cv::COLOR_GRAY2BGR);

        // Mezclar con original según intensidad (con factor de amplificación)
        double factor = intensidad * 1.5; // Aumentar intensidad 50%
        if (factor > 1.0) factor = 1.0;
        cv::addWeighted(imagenOriginal, 1.0 - factor, bin, factor, 0, imagenProcesada);
        break;
    }

    case TipoFiltro::Canny:
    {
        cv::Mat g, e;
        cv::cvtColor(imagenProcesada, g, cv::COLOR_BGR2GRAY);

        // Aplicar desenfoque gaussiano para reducir ruido y mejorar detección
        cv::GaussianBlur(g, g, cv::Size(5, 5), 1.4);

        // Mejorar umbrales para mejor detección de bordes
        int umbralBajo = umbral / 2;  // Umbral bajo
        int umbralAlto = umbral * 2;   // Umbral alto

        // Asegurar que los umbrales estén en rango válido
        if (umbralBajo < 30) umbralBajo = 30;
        if (umbralAlto > 200) umbralAlto = 200;

        cv::Canny(g, e, umbralBajo, umbralAlto);
        cv::cvtColor(e, e, cv::COLOR_GRAY2BGR);

        // Mezclar con original según intensidad (con factor de amplificación)
        double factor = intensidad * 1.5; // Aumentar intensidad 50%
        if (factor > 1.0) factor = 1.0;
        cv::addWeighted(imagenOriginal, 1.0 - factor, e, factor, 0, imagenProcesada);
        break;
    }

    case TipoFiltro::Sobel:
    {
        cv::Mat g, sx, sy, absx, absy, sobel;
        cv::cvtColor(imagenProcesada, g, cv::COLOR_BGR2GRAY);
        cv::Sobel(g, sx, CV_16S, 1, 0);
        cv::Sobel(g, sy, CV_16S, 0, 1);
        cv::convertScaleAbs(sx, absx);
        cv::convertScaleAbs(sy, absy);
        cv::addWeighted(absx, 0.5, absy, 0.5, 0, g);
        cv::cvtColor(g, sobel, cv::COLOR_GRAY2BGR);

        // Mezclar con original según intensidad (con factor de amplificación)
        double factor = intensidad * 1.5; // Aumentar intensidad 50%
        if (factor > 1.0) factor = 1.0;
        cv::addWeighted(imagenOriginal, 1.0 - factor, sobel, factor, 0, imagenProcesada);
        break;
    }

    case TipoFiltro::CanalR:
    case TipoFiltro::CanalG:
    case TipoFiltro::CanalB:
    {
        std::vector<cv::Mat> ch;
        cv::split(imagenProcesada, ch);

        cv::Mat canalFiltrado = imagenProcesada.clone();
        std::vector<cv::Mat> chFiltro;
        cv::split(canalFiltrado, chFiltro);

        if (filtroActual != TipoFiltro::CanalB) chFiltro[0] = cv::Mat::zeros(chFiltro[0].size(), chFiltro[0].type());
        if (filtroActual != TipoFiltro::CanalG) chFiltro[1] = cv::Mat::zeros(chFiltro[1].size(), chFiltro[1].type());
        if (filtroActual != TipoFiltro::CanalR) chFiltro[2] = cv::Mat::zeros(chFiltro[2].size(), chFiltro[2].type());

        cv::merge(chFiltro, canalFiltrado);

        // Mezclar con original según intensidad (con factor de amplificación)
        double factor = intensidad * 1.5; // Aumentar intensidad 50%
        if (factor > 1.0) factor = 1.0;
        cv::addWeighted(imagenOriginal, 1.0 - factor, canalFiltrado, factor, 0, imagenProcesada);
        break;
    }

    case TipoFiltro::Rotacion:
    {
        cv::Point2f c(imagenProcesada.cols / 2.0f, imagenProcesada.rows / 2.0f);
        cv::Mat m = cv::getRotationMatrix2D(c, angulo, 1.0);
        cv::warpAffine(imagenProcesada, imagenProcesada, m, imagenProcesada.size());
        break;
    }

    case TipoFiltro::Zoom:
    {
        if (zoom <= 1.0)
            break;

        cv::Mat tmp;
        cv::resize(imagenProcesada, tmp, cv::Size(), zoom, zoom);

        int x = (tmp.cols - imagenProcesada.cols) / 2;
        int y = (tmp.rows - imagenProcesada.rows) / 2;

        cv::Rect roi(x, y,
            imagenProcesada.cols,
            imagenProcesada.rows);

        imagenProcesada = tmp(roi).clone();
        break;
    }

    }
}