#ifndef HASH_H
#define HASH_H

#include <vector>
#include <unordered_map>

// Clase para Tabla Hash con Encadenamiento
class HashTablaEncadenamiento {
    std::unordered_map<int, std::vector<int>> tabla;
public:
    void insertar(int clave);
    bool buscar(int clave);
};

// Clase para Tabla Hash con Linear Probing
class HashTablaLinearProbing {
    std::vector<int> tabla;
    int capacidad;
    int elementoVacio = -1;
public:
    HashTablaLinearProbing(int cap);
    int hash(int clave);
    void insertar(int clave);
    bool buscar(int clave);
};

// Declaraciones para Quadratic Probing, Double Hashing y Cuckoo Hashing
// Puedes implementarlos de manera similar siguiendo el patrón anterior

#endif // HASH_H

