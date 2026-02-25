#include "Busqueda.h"

int Busqueda::busquedaBinaria(int arr[], int n, int objetivo) {

    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {

        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == objetivo) {
            return medio;
        }
        else if (arr[medio] < objetivo) {
            inicio = medio + 1;
        }
        else {
            fin = medio - 1;
        }
    }

    return -1;
}