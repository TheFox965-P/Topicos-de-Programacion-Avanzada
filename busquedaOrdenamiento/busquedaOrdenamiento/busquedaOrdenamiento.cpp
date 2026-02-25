#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "search.h"
#include "sort.h"
#include "view.h"
#include "numerosRandom.h"   

int main()
{
    int opcion;
    int metodo;

    // Arreglo principal (capacidad máxima)
    int arreglo[100000];
    int n = 0;

    int posicion;
    int valor;
    int comparaciones = 0;
    int intercambios = 0;

    bool mostrarProceso;

    // Configuración inicial
    cout << "=== CONFIGURACION INICIAL ===\n";

    int opGen = menuGeneracion();   // repetidos o no
    bool repetir = (opGen == 1);

    int tipo = submenuComplejidad(); // n, n*n, n*m

    generarNumeros(arreglo, n, repetir, tipo);

    if (n <= 0)
    {
        cout << "Error al generar datos. Finalizando.\n";
        return 0;
    }

    cout << "\nNumeros generados:\n";
    mostrarArreglo(arreglo, n);

    cout << "\n¿Deseas ver el proceso de los algoritmos? (1=Si, 0=No): ";
    cin >> mostrarProceso;

    // MENU PRINCIPAL
    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1: // Busqueda Secuencial
        {
            mostrarArreglo(arreglo, n);
            valor = pedirValor();

            cout << "Cronometro iniciado (Busqueda Secuencial)...\n";
            auto inicio = high_resolution_clock::now();

            posicion = busquedaSecuencial(arreglo, n, valor, mostrarProceso);

            auto fin = high_resolution_clock::now();
            duration<double, milli> tiempo = fin - inicio;

            if (posicion != -1)
                cout << "Valor encontrado en posicion: " << posicion << endl;
            else
                cout << "Valor no encontrado.\n";

            cout << "Tiempo de ejecucion: " << tiempo.count() << " ms\n";
            break;
        }

        case 2: // Busqueda Binaria
        {
            cout << "\nOrdenando arreglo con Burbuja...\n";

            cout << "Cronometro iniciado (Ordenamiento Burbuja)...\n";
            auto inicioOrden = high_resolution_clock::now();

            ordenarBurbuja(arreglo, n, mostrarProceso);

            auto finOrden = high_resolution_clock::now();
            duration<double, milli> tiempoOrden = finOrden - inicioOrden;

            cout << "Tiempo Burbuja: " << tiempoOrden.count() << " ms\n";

            mostrarArreglo(arreglo, n);

            valor = pedirValor();

            cout << "Cronometro iniciado (Busqueda Binaria)...\n";
            auto inicioBusq = high_resolution_clock::now();

            posicion = busquedaBinaria(arreglo, n, valor, mostrarProceso);

            auto finBusq = high_resolution_clock::now();
            duration<double, milli> tiempoBusq = finBusq - inicioBusq;

            if (posicion != -1)
                cout << "Valor encontrado en posicion: " << posicion << endl;
            else
                cout << "Valor no encontrado.\n";

            cout << "Tiempo Busqueda Binaria: " << tiempoBusq.count() << " ms\n";
            break;
        }

        case 3: // Ordenar arreglo
        {
            metodo = mostrarMenuOrdenamiento();

            comparaciones = 0;
            intercambios = 0;

            cout << "Cronometro iniciado (Ordenamiento)...\n";
            auto inicio = high_resolution_clock::now();

            if (metodo == 1)
            {
                ordenarBurbuja(arreglo, n, mostrarProceso);
            }
            else if (metodo == 2)
            {
                ordenarSeleccion(arreglo, n, mostrarProceso);
            }
            else if (metodo == 3)
            {
                ordenarInsercion(arreglo, n, mostrarProceso);
            }
            else if (metodo == 4)
            {
                quickSort(arreglo, 0, n - 1, comparaciones, intercambios, mostrarProceso);
                cout << "Comparaciones: " << comparaciones << endl;
                cout << "Intercambios: " << intercambios << endl;
            }
            else if (metodo == 5)
            {
                mergeSort(arreglo, 0, n - 1, comparaciones, mostrarProceso);
                cout << "Comparaciones: " << comparaciones << endl;
            }
            else
            {
                cout << "Metodo invalido.\n";
            }

            auto fin = high_resolution_clock::now();
            duration<double, milli> tiempo = fin - inicio;

            cout << "\nTiempo de ejecucion: " << tiempo.count() << " ms\n";

            cout << "\nArreglo ordenado:\n";
            mostrarArreglo(arreglo, n);
            break;
        }

        case 4:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}