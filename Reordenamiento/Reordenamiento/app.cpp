#include <iostream>
#include "app.h"
#include "search.h"
#include "sort.h"
#include "view.h"

void ejecutarPrograma()
{
    int arreglo[10] = { 33, 5, 90, 12, 41, 8, 77, 20, 50, 62 };
    int n = 10;
    int opcion;

    do
    {
        mostrarMenu();
        std::cin >> opcion;

        if (opcion == 1)
        {
            mostrarArreglo(arreglo, n);
            int valor = pedirValor();
            int pos = busquedaSecuencial(arreglo, n, valor);

            if (pos != -1)
                std::cout << "Valor encontrado\n";
            else
                std::cout << "Valor no encontrado\n";
        }
        else if (opcion == 2)
        {
            ordenarBurbuja(arreglo, n);
            mostrarArreglo(arreglo, n);

            int valor = pedirValor();
            int pos = busquedaBinaria(arreglo, n, valor);

            if (pos != -1)
                std::cout << "Valor encontrado\n";
            else
                std::cout << "Valor no encontrado\n";
        }
        else if (opcion == 3)
        {
            int metodo = mostrarMenuOrdenamiento();
            int comp = 0;
            int interc = 0;

            if (metodo == 1) ordenarBurbuja(arreglo, n);
            else if (metodo == 2) ordenarSeleccion(arreglo, n);
            else if (metodo == 3) ordenarInsercion(arreglo, n);
            else if (metodo == 4) quickSort(arreglo, 0, n - 1, comp, interc);
            else if (metodo == 5) mergeSort(arreglo, 0, n - 1, comp);

            mostrarArreglo(arreglo, n);
        }

    } while (opcion != 4);
}