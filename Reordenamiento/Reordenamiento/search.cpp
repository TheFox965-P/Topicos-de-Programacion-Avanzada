#include "search.h"

int busquedaSecuencial(int arreglo[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (arreglo[i] == valor)
            return i;
    }
    return -1;
}

int busquedaBinaria(int arreglo[], int n, int valor)
{
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha)
    {
        int medio = (izquierda + derecha) / 2;

        if (arreglo[medio] == valor)
            return medio;
        else if (arreglo[medio] < valor)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return -1;
}