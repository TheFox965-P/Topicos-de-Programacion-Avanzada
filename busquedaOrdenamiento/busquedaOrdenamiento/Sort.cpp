#include <iostream>
using namespace std;

#include "sort.h"

void imprimirPaso(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

void ordenarBurbuja(int arreglo[], int n, bool mostrarProceso)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (mostrarProceso)
                cout << "Comparando " << arreglo[j]
                << " y " << arreglo[j + 1] << endl;

            if (arreglo[j] > arreglo[j + 1])
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;

                if (mostrarProceso)
                {
                    cout << "Intercambio -> ";
                    imprimirPaso(arreglo, n);
                }
            }
        }
    }
}

void ordenarSeleccion(int arreglo[], int n, bool mostrarProceso)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (mostrarProceso)
                cout << "Comparando " << arreglo[j]
                << " con minimo actual " << arreglo[min] << endl;

            if (arreglo[j] < arreglo[min])
                min = j;
        }

        temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;

        if (mostrarProceso)
        {
            cout << "Colocando minimo -> ";
            imprimirPaso(arreglo, n);
        }
    }
}

void ordenarInsercion(int arreglo[], int n, bool mostrarProceso)
{
    int i, j, clave;

    for (i = 1; i < n; i++)
    {
        clave = arreglo[i];
        j = i - 1;

        if (mostrarProceso)
            cout << "Insertando " << clave << endl;

        while (j >= 0 && arreglo[j] > clave)
        {
            arreglo[j + 1] = arreglo[j];
            j--;

            if (mostrarProceso)
            {
                imprimirPaso(arreglo, n);
            }
        }

        arreglo[j + 1] = clave;

        if (mostrarProceso)
        {
            cout << "Estado -> "<<endl;
            imprimirPaso(arreglo, n);
        }
    }
}

void quickSort(int arreglo[], int izquierda, int derecha,
    int& comparaciones, int& intercambios, bool mostrarProceso)
{
    int i = izquierda;
    int j = derecha;
    int pivote = arreglo[(izquierda + derecha) / 2];
    int temp;

    if (mostrarProceso)
        cout << "\nQuickSort con pivote: " << pivote << endl;

    while (i <= j)
    {
        while (arreglo[i] < pivote)
        {
            i++;
            comparaciones++;
        }

        while (arreglo[j] > pivote)
        {
            j--;
            comparaciones++;
        }

        if (i <= j)
        {
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
            intercambios++;

            if (mostrarProceso)
            {
                cout << "Intercambio -> ";
                imprimirPaso(arreglo, derecha + 1);
            }

            i++;
            j--;
        }
    }

    if (izquierda < j)
        quickSort(arreglo, izquierda, j, comparaciones, intercambios, mostrarProceso);

    if (i < derecha)
        quickSort(arreglo, i, derecha, comparaciones, intercambios, mostrarProceso);
}

void merge(int arreglo[], int izquierda, int medio, int derecha,
    int& comparaciones, bool mostrarProceso)
{
    int i = izquierda;
    int j = medio + 1;
    int k = 0;
    int temp[100];

    if (mostrarProceso)
        cout << "\nFusionando subarreglos...\n";

    while (i <= medio && j <= derecha)
    {
        comparaciones++;

        if (arreglo[i] <= arreglo[j])
            temp[k++] = arreglo[i++];
        else
            temp[k++] = arreglo[j++];
    }

    while (i <= medio)
        temp[k++] = arreglo[i++];

    while (j <= derecha)
        temp[k++] = arreglo[j++];

    for (i = izquierda, k = 0; i <= derecha; i++, k++)
        arreglo[i] = temp[k];

    if (mostrarProceso)
    {
        cout << "Resultado parcial -> ";
        imprimirPaso(arreglo, derecha + 1);
    }
}

void mergeSort(int arreglo[], int izquierda, int derecha,
    int& comparaciones, bool mostrarProceso)
{
    int medio;

    if (izquierda < derecha)
    {
        medio = (izquierda + derecha) / 2;

        mergeSort(arreglo, izquierda, medio, comparaciones, mostrarProceso);
        mergeSort(arreglo, medio + 1, derecha, comparaciones, mostrarProceso);
        merge(arreglo, izquierda, medio, derecha, comparaciones, mostrarProceso);
    }
}