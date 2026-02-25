#include <iostream>
using namespace std;

#include "search.h"

int busquedaSecuencial(int arreglo[], int n, int valor, bool mostrarProceso)
{
    for (int i = 0; i < n; i++)
    {
        if (mostrarProceso)
            cout << "Comparando indice " << i << " -> " << arreglo[i] << endl;

        if (arreglo[i] == valor)
            return i;
    }
    return -1;
}

int busquedaBinaria(int arreglo[], int n, int valor, bool mostrarProceso)
{
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha)
    {
        int medio = (izquierda + derecha) / 2;

        if (mostrarProceso)
            cout << "Medio=" << medio << " Valor=" << arreglo[medio] << endl;

        if (arreglo[medio] == valor)
            return medio;
        else if (arreglo[medio] < valor)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return -1;
}