#include "Hash.h"
#include <algorithm>

// Implementación de HashTablaEncadenamiento
void HashTablaEncadenamiento::insertar(int clave) {
    tabla[clave].push_back(clave);
}

bool HashTablaEncadenamiento::buscar(int clave) {
    if(tabla.find(clave) != tabla.end())
        return true;
    return false;
}

// Implementación de HashTablaLinearProbing
HashTablaLinearProbing::HashTablaLinearProbing(int cap) : capacidad(cap), tabla(cap, -1) {}

int HashTablaLinearProbing::hash(int clave) {
    return clave % capacidad;
}

void HashTablaLinearProbing::insertar(int clave) {
    int idx = hash(clave);
    while(tabla[idx] != -1 && tabla[idx] != clave){
        idx = (idx +1) % capacidad;
    }
    tabla[idx] = clave;
}

bool HashTablaLinearProbing::buscar(int clave) {
    int idx = hash(clave);
    int inicio = idx;
    while(tabla[idx] != -1){
        if(tabla[idx] == clave)
            return true;
        idx = (idx +1) % capacidad;
        if(idx == inicio)
            break;
    }
    return false;
}

// Implementaciones para Quadratic Probing, Double Hashing y Cuckoo Hashing pueden seguir patrones similares

