#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>

// Declaraciones de funciones de ordenamiento
void ordenamientoBurbuja(std::vector<int>& arr);
void ordenamientoSeleccion(std::vector<int>& arr);
void ordenamientoInsercion(std::vector<int>& arr);
void ordenamientoMergeSort(std::vector<int>& arr, int izquierda, int derecha);
void ordenamientoQuickSort(std::vector<int>& arr, int baja, int alta);

#endif // ORDENAMIENTO_H

