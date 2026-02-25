#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "Busqueda.h"
#include "Ordenamiento.h"

using namespace std;

int main() {

    const int n = 10000;
    int arr[n];

    srand(time(0));

    // Llenar arreglo con números aleatorios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    Ordenamiento o;
    Busqueda b;

    // Medir tiempo de ordenamiento burbuja
    auto inicioOrden = chrono::high_resolution_clock::now();

    o.insercion(arr, n);

    auto finOrden = chrono::high_resolution_clock::now();

    auto duracionOrden = chrono::duration_cast<chrono::milliseconds>(finOrden - inicioOrden);

    cout << "Tiempo insercion: " << duracionOrden.count() << " ms" << endl;

    // Medir tiempo de búsqueda binaria
    auto inicioBusqueda = chrono::high_resolution_clock::now();

    b.busquedaBinaria(arr, n, arr[n / 2]);

    auto finBusqueda = chrono::high_resolution_clock::now();

    auto duracionBusqueda = chrono::duration_cast<chrono::microseconds>(finBusqueda - inicioBusqueda);

    cout << "Tiempo Busqueda Binaria: " << duracionBusqueda.count() << " microsegundos" << endl;

    return 0;
}