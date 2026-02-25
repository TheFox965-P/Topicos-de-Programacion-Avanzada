#pragma once
#ifndef SORT_H
#define SORT_H

void ordenarBurbuja(int arreglo[], int n, bool mostrarProceso);
void ordenarSeleccion(int arreglo[], int n, bool mostrarProceso);
void ordenarInsercion(int arreglo[], int n, bool mostrarProceso);
void quickSort(int arreglo[], int izquierda, int derecha,
    int& comparaciones, int& intercambios, bool mostrarProceso);
void mergeSort(int arreglo[], int izquierda, int derecha,
    int& comparaciones, bool mostrarProceso);

#endif