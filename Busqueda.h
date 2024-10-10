#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>

// Declaraciones de funciones de búsqueda
int busquedaLineal(const std::vector<int>& arr, int clave);
int busquedaBinaria(const std::vector<int>& arr, int clave);
int busquedaInterpolada(const std::vector<int>& arr, int clave);
int busquedaExponencial(const std::vector<int>& arr, int clave);
int busquedaFibonacci(const std::vector<int>& arr, int clave);

#endif // BUSQUEDA_H
