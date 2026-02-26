#include <iostream>
#include "view.h"

void mostrarMenu()
{
    std::cout << "\n=== MENU ===\n";
    std::cout << "1. Busqueda Secuencial\n";
    std::cout << "2. Busqueda Binaria\n";
    std::cout << "3. Ordenar Arreglo\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione opcion: ";
}

void mostrarArreglo(int arreglo[], int n)
{
    std::cout << "\nArreglo: ";
    for (int i = 0; i < n; i++)
        std::cout << arreglo[i] << " ";
    std::cout << "\n";
}

int pedirValor()
{
    int valor;
    std::cout << "Ingrese valor a buscar: ";
    std::cin >> valor;
    return valor;
}

int mostrarMenuOrdenamiento()
{
    int opcion;
    std::cout << "\n=== METODOS DE ORDENAMIENTO ===\n";
    std::cout << "1. Burbuja\n";
    std::cout << "2. Seleccion\n";
    std::cout << "3. Insercion\n";
    std::cout << "4. QuickSort\n";
    std::cout << "5. MergeSort\n";
    std::cout << "Seleccione metodo: ";
    std::cin >> opcion;
    return opcion;
}