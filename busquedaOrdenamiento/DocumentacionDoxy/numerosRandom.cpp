#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "numerosRandom.h"

using namespace std;

// meenu para decidir si se permiten numeros repetidos o no
/**
 * @brief Muestra el menú para elegir si se permiten números repetidos.
 *
 * @return int Opción seleccionada por el usuario.
 */
int menuGeneracion()
{
    int opcion;

    cout << "\n--- GENERADOR DE NUMEROS ---\n";
    cout << "1. Permitir repetidos\n";
    cout << "2. No permitir repetidos\n";
    cout << "Seleccione: ";
    cin >> opcion;

    return opcion;
}

// menu para elegir tipo de complejidad (n, n*n, n*m)
/**
 * @brief Permite seleccionar el tipo de tamaño del arreglo.
 *
 * Opciones: n, n*n o n*m.
 *
 * @return int Tipo seleccionado.
 */
int submenuComplejidad()
{
    int tipo;

    cout << "\n--- TIPO DE TAMANO ---\n";
    cout << "1. n\n";
    cout << "2. n*n\n";
    cout << "3. n*m\n";
    cout << "Seleccione: ";
    cin >> tipo;

    return tipo;
}

// se generan los numeros segun las opciones elegidas y se llenan en el arreglo
/**
 * @brief Genera números aleatorios según la configuración seleccionada.
 *
 * Puede generar números con repetición o sin repetición.
 *
 * @param arreglo Arreglo donde se almacenan los números generados.
 * @param n Referencia al tamaño final del arreglo.
 * @param repetir Indica si se permiten números repetidos.
 * @param tipo Tipo de tamaño seleccionado (n, n*n, n*m).
 */
void generarNumeros(int arreglo[], int& n, bool repetir, int tipo)
{
    srand(time(0));

    int m;
    int total = 0;

    // Determinar tamaño según complejidad
    if (tipo == 1)
    {
        cout << "Ingrese n: ";
        cin >> n;
        total = n;
    }
    else if (tipo == 2)
    {
        cout << "Ingrese n: ";
        cin >> n;
        total = n * n;
    }
    else if (tipo == 3)
    {
        cout << "Ingrese n: ";
        cin >> n;
        cout << "Ingrese m: ";
        cin >> m;
        total = n * m;
    }
    else
    {
        cout << "Opcion invalida.\n";
        n = 0;
        return;
    }

    // Validacion de capacidad maxima
    if (total > 1000)
    {
        cout << "Error: excede el tamaño maximo permitido (1000).\n";
        n = 0;
        return;
    }

	unordered_set<int> usados; // para evitar repetidos

    for (int i = 0; i < total; i++)
    {
        int num = rand() % 1000;

        if (!repetir)
        {
            while (usados.count(num))
                num = rand() % 1000;

            usados.insert(num);
        }

        arreglo[i] = num;
    }

    n = total;
}