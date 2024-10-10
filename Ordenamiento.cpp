#include "Ordenamiento.h"
#include <algorithm>

// 1. Burbuja
void ordenamientoBurbuja(std::vector<int>& arr) {
    bool swapped;
    for (size_t i = 0; i < arr.size()-1; ++i) {
        swapped = false;
        for (size_t j = 0; j < arr.size()-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// 2. Selección
void ordenamientoSeleccion(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size()-1; ++i) {
        size_t min_idx = i;
        for (size_t j = i+1; j < arr.size(); ++j)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[i], arr[min_idx]);
    }
}

// 3. Inserción
void ordenamientoInsercion(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 4. Merge Sort
void merge(std::vector<int>& arr, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for(int i=0;i<n1;i++) L[i] = arr[izquierda + i];
    for(int j=0;j<n2;j++) R[j] = arr[medio + 1 + j];
    int i=0, j=0, k=izquierda;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void ordenamientoMergeSort(std::vector<int>& arr, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        ordenamientoMergeSort(arr, izquierda, medio);
        ordenamientoMergeSort(arr, medio + 1, derecha);
        merge(arr, izquierda, medio, derecha);
    }
}

// 5. Quick Sort
int particion(std::vector<int>& arr, int baja, int alta) {
    int pivote = arr[alta];
    int i = baja -1;
    for(int j = baja; j <= alta -1; j++) {
        if(arr[j] < pivote){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[alta]);
    return i+1;
}

void ordenamientoQuickSort(std::vector<int>& arr, int baja, int alta) {
    if(baja < alta){
        int pi = particion(arr, baja, alta);
        ordenamientoQuickSort(arr, baja, pi -1);
        ordenamientoQuickSort(arr, pi +1, alta);
    }
}

