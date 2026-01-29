#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat img = imread("C:/Users/angel/source/repos/opencv-prueba/img/IMG_1263.jpg");
    if (img.empty()) {
        cerr << "Failed to load image: check path and working directory\n";
        return -1;
    }

    // Redimensionar imagen
    Mat img_resized;
    resize(img, img_resized, Size(636, 316));

    // Convertir a blanco y negro (escala de grises)
    Mat img_gray;
    cvtColor(img_resized, img_gray, COLOR_BGR2GRAY);

    // Mostrar imágenes
    imshow("Imagen Original", img);
    imshow("Imagen Redimensionada", img_resized);
    imshow("Imagen Blanco y Negro", img_gray);

    waitKey(0);
    return 0;
}


/*
* 27-January-2026 IvanPintor Creacion de repositorio en GitHub
* 27-January-2026 Creacion de Setup para OpenCV
*/
