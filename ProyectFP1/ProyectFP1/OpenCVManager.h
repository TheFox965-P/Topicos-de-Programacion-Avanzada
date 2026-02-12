#pragma once
#include <opencv2/opencv.hpp>

enum class TipoFiltro {
    SinFiltro,
    Grises,
    BinarioBN,
    BinarioNB,
    Canny,
    Sobel,
    CanalR,   // 🔴 ch[2]
    CanalG,   // 🟢 ch[1]
    CanalB,   // 🔵 ch[0]
    Rotacion,
    Zoom
};

class OpenCVManager {
public:
    OpenCVManager();
    ~OpenCVManager();

    void reprocesarImagen();
    void aplicarFiltro();

    cv::Mat imagenOriginal;
    cv::Mat imagenProcesada;
    cv::VideoCapture cap;

    bool camaraActiva;

    TipoFiltro filtroActual;
    int umbral;
    int angulo;
    double zoom;
    double intensidad; // Nueva variable para la intensidad general
};