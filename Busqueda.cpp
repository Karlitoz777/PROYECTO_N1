#include "Busqueda.h"

// 1. Búsqueda Lineal
int busquedaLineal(const std::vector<int>& arr, int clave) {
    for (size_t i = 0; i < arr.size(); ++i)
        if (arr[i] == clave)
            return i;
    return -1;
}

// 2. Búsqueda Binaria
int busquedaBinaria(const std::vector<int>& arr, int clave) {
    int izquierda = 0;
    int derecha = arr.size() - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == clave)
            return medio;
        if (arr[medio] < clave)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return -1;
}

// 3. Búsqueda Interpolada
int busquedaInterpolada(const std::vector<int>& arr, int clave) {
    int izquierda = 0;
    int derecha = arr.size() - 1;
    while (izquierda <= derecha && clave >= arr[izquierda] && clave <= arr[derecha]) {
        if (izquierda == derecha) {
            if (arr[izquierda] == clave)
                return izquierda;
            return -1;
        }
        int pos = izquierda + ((double)(derecha - izquierda) / (arr[derecha] - arr[izquierda])) * (clave - arr[izquierda]);
        if (arr[pos] == clave)
            return pos;
        if (arr[pos] < clave)
            izquierda = pos + 1;
        else
            derecha = pos - 1;
    }
    return -1;
}

// 4. Búsqueda Exponencial
int busquedaExponencial(const std::vector<int>& arr, int clave) {
    if (arr.empty())
        return -1;
    if (arr[0] == clave)
        return 0;
    int i = 1;
    while (i < arr.size() && arr[i] <= clave)
        i = i * 2;
    // Búsqueda binaria en el rango encontrado
    int izquierda = i / 2;
    int derecha = std::min(i, (int)arr.size() - 1);
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == clave)
            return medio;
        if (arr[medio] < clave)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return -1;
}

// 5. Búsqueda Fibonacci
int busquedaFibonacci(const std::vector<int>& arr, int clave) {
    int n = arr.size();
    // Inicializar los dos primeros números de Fibonacci
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1) {
        int i = std::min(offset + fibMMm2, n - 1);
        if (arr[i] < clave) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > clave) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }
    if (fibMMm1 && offset + 1 < n && arr[offset + 1] == clave)
        return offset + 1;
    return -1;
}

