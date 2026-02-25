
#include <iostream>
using namespace std;

#include "search.h"
/**
 * @brief Realiza una búsqueda secuencial.
 *
 * Recorre el arreglo comparando elemento por elemento.
 *
 * @param arreglo Arreglo de datos.
 * @param n Tamaño del arreglo.
 * @param valor Valor a buscar.
 * @param mostrarProceso Muestra las comparaciones si es true.
 * @return int Posición encontrada o -1 si no existe.
 */
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
/**
 * @brief Realiza una búsqueda binaria.
 *
 * El arreglo debe estar previamente ordenado.
 *
 * @param arreglo Arreglo ordenado.
 * @param n Tamaño del arreglo.
 * @param valor Valor a buscar.
 * @param mostrarProceso Muestra pasos intermedios.
 * @return int Posición encontrada o -1 si no existe.
 */
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