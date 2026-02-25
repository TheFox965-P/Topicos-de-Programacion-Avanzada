#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <set>

#include "Busqueda.h"
#include "Ordenamiento.h"

using namespace std;

// 🔹 Llenar con repetidos
void llenarConRepetidos(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 5000);
    }
}

// 🔹 Llenar sin repetidos
void llenarSinRepetidos(int arr[], int n) {
    set<int> numeros;

    while (numeros.size() < n) {
        numeros.insert(rand() % (n * 20));
    }

    int i = 0;
    for (int num : numeros) {
        arr[i++] = num;
    }
}

int main() {

    srand(time(0));

    int N = 1000;       // Tamaño base
    int M = 5;

    int opcionRepetidos;
    int opcionTamano;
    int opcionMostrar;
    int opcionAlgoritmo;

    cout << "1. Con repetidos\n2. Sin repetidos\n";
    cin >> opcionRepetidos;

    cout << "Tamano:\n1. N\n2. N*N\n3. N*M\n";
    cin >> opcionTamano;

    cout << "Mostrar proceso?\n1. Si\n2. No\n";
    cin >> opcionMostrar;

    cout << "Algoritmo:\n1. Burbuja\n2. Seleccion\n3. Insercion\n";
    cin >> opcionAlgoritmo;

    int n;

    if (opcionTamano == 1)
        n = N;
    else if (opcionTamano == 2)
        n = N * N;
    else
        n = N * M;

    int* arr = new int[n];

    if (opcionRepetidos == 1)
        llenarConRepetidos(arr, n);
    else
        llenarSinRepetidos(arr, n);

    Ordenamiento o;
    Busqueda b;

    bool mostrar = (opcionMostrar == 1);

    auto inicioOrden = chrono::high_resolution_clock::now();

    if (opcionAlgoritmo == 1)
        o.burbuja(arr, n, mostrar);
    else if (opcionAlgoritmo == 2)
        o.seleccion(arr, n, mostrar);
    else
        o.insercion(arr, n, mostrar);

    auto finOrden = chrono::high_resolution_clock::now();

    auto duracionOrden = chrono::duration_cast<chrono::milliseconds>(finOrden - inicioOrden);

    cout << "\nTiempo Ordenamiento: " << duracionOrden.count() << " ms" << endl;

    auto inicioBusqueda = chrono::high_resolution_clock::now();

    b.busquedaBinaria(arr, n, arr[n / 2]);

    auto finBusqueda = chrono::high_resolution_clock::now();

    auto duracionBusqueda = chrono::duration_cast<chrono::microseconds>(finBusqueda - inicioBusqueda);

    cout << "Tiempo Busqueda Binaria: " << duracionBusqueda.count() << " microsegundos" << endl;

    delete[] arr;

    return 0;
}