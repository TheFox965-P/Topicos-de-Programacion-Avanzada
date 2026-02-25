#include "Ordenamiento.h"

// Metodo Burbuja
void Ordenamiento::burbuja(int arr[], int n, bool mostrar) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        if (mostrar) {
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}

// Metodo Seleccion
void Ordenamiento::seleccion(int arr[], int n, bool mostrar) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        if (mostrar) {
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}

// Metodo Insercion
void Ordenamiento::insercion(int arr[], int n, bool mostrar) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = clave;

        if (mostrar) {
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}