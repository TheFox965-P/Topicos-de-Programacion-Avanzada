#ifndef NUMEROS_RANDOM_H
#define NUMEROS_RANDOM_H

// Menu: permite elegir si los numeros se repiten
int menuGeneracion();

// Submenu: tipo de complejidad (n, n*n, n*m)
int submenuComplejidad();

// Genera los numeros y llena el arreglo
void generarNumeros(int arreglo[], int& n, bool repetir, int tipo);

#endif