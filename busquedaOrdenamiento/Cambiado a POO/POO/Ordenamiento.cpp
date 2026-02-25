#include "Ordenamiento.h"

// Metodo Burbuja
// Complejidad O(n²)
void Ordenamiento::burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Metodo Seleccion
// Complejidad O(n²)
void Ordenamiento::seleccion(int arr[], int n) {
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
    }
}

// Metodo Insercion
// Complejidad O(n²)
void Ordenamiento::insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = clave;
    }
}