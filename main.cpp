#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include "Busqueda.h"
#include "Ordenamiento.h"
#include "AlgoritmosTextuales.h"
#include "Hash.h"
#include <functional> // Necesario para std::bind

// Función plantilla para medir el tiempo de ejecución
template <typename Func>
long long medirTiempo(Func func){
    auto inicio = std::chrono::high_resolution_clock::now();
    func();
    auto fin = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
}

int main(){
    // ----------------------------
    // 1. Pruebas de Búsqueda
    // ----------------------------
    std::cout << "=== Pruebas de Búsqueda ===\n";
    const int tamanoBusqueda = 100000;
    std::vector<int> datosBusqueda(tamanoBusqueda);
    for(int i=0;i<tamanoBusqueda;i++) datosBusqueda[i] = i;

    // Clave a buscar
    int claveBusqueda = tamanoBusqueda -1;

    // Búsqueda Lineal
    long long tiempoLineal = medirTiempo([&]() { busquedaLineal(datosBusqueda, claveBusqueda); });
    std::cout << "Búsqueda Lineal: " << tiempoLineal << " microsegundos\n";

    // Búsqueda Binaria
    long long tiempoBinaria = medirTiempo([&]() { busquedaBinaria(datosBusqueda, claveBusqueda); });
    std::cout << "Búsqueda Binaria: " << tiempoBinaria << " microsegundos\n";

    // Búsqueda Interpolada
    long long tiempoInterpolada = medirTiempo([&]() { busquedaInterpolada(datosBusqueda, claveBusqueda); });
    std::cout << "Búsqueda Interpolada: " << tiempoInterpolada << " microsegundos\n";

    // Búsqueda Exponencial
    long long tiempoExponencial = medirTiempo([&]() { busquedaExponencial(datosBusqueda, claveBusqueda); });
    std::cout << "Búsqueda Exponencial: " << tiempoExponencial << " microsegundos\n";

    // Búsqueda Fibonacci
    long long tiempoFibonacci = medirTiempo([&]() { busquedaFibonacci(datosBusqueda, claveBusqueda); });
    std::cout << "Búsqueda Fibonacci: " << tiempoFibonacci << " microsegundos\n\n";

    // ----------------------------
    // 2. Pruebas de Ordenamiento
    // ----------------------------
    std::cout << "=== Pruebas de Ordenamiento ===\n";
    const int tamanoOrdenamiento = 10000;
    std::vector<int> datosOrdenamiento(tamanoOrdenamiento);
    for(int i=0;i<tamanoOrdenamiento;i++) datosOrdenamiento[i] = tamanoOrdenamiento - i;

    // Ordenamiento Burbuja
    std::vector<int> burbujaDatos = datosOrdenamiento;
    long long tiempoBurbuja = medirTiempo([&]() { ordenamientoBurbuja(burbujaDatos); });
    std::cout << "Ordenamiento Burbuja: " << tiempoBurbuja << " microsegundos\n";

    // Ordenamiento Selección
    std::vector<int> seleccionDatos = datosOrdenamiento;
    long long tiempoSeleccion = medirTiempo([&]() { ordenamientoSeleccion(seleccionDatos); });
    std::cout << "Ordenamiento Selección: " << tiempoSeleccion << " microsegundos\n";

    // Ordenamiento Inserción
    std::vector<int> insercionDatos = datosOrdenamiento;
    long long tiempoInsercion = medirTiempo([&]() { ordenamientoInsercion(insercionDatos); });
    std::cout << "Ordenamiento Inserción: " << tiempoInsercion << " microsegundos\n";

    // Ordenamiento Merge Sort
    std::vector<int> mergeDatos = datosOrdenamiento;
    long long tiempoMerge = medirTiempo([&]() { ordenamientoMergeSort(mergeDatos, 0, mergeDatos.size()-1); });
    std::cout << "Ordenamiento Merge Sort: " << tiempoMerge << " microsegundos\n";

    // Ordenamiento Quick Sort
    std::vector<int> quickDatos = datosOrdenamiento;
    long long tiempoQuick = medirTiempo([&]() { ordenamientoQuickSort(quickDatos, 0, quickDatos.size()-1); });
    std::cout << "Ordenamiento Quick Sort: " << tiempoQuick << " microsegundos\n\n";

    // ----------------------------
    // 3. Pruebas de Algoritmos Textuales
    // ----------------------------
    std::cout << "=== Pruebas de Algoritmos Textuales ===\n";
    std::string texto = "Este es un ejemplo de texto para probar los algoritmos textuales. Buscamos una palabra específica: algoritmos.";
    std::string patron = "algoritmos";

    // Búsqueda por Fuerza Bruta
    long long tiempoBF = medirTiempo([&]() { busquedaFuerzaBruta(texto, patron); });
    std::cout << "Búsqueda por Fuerza Bruta: " << tiempoBF << " microsegundos\n";

    // Búsqueda KMP
    long long tiempoKMP = medirTiempo([&]() { busquedaKMP(texto, patron); });
    std::cout << "Búsqueda KMP: " << tiempoKMP << " microsegundos\n";

    // Búsqueda Boyer-Moore
    long long tiempoBM = medirTiempo([&]() { busquedaBoyerMoore(texto, patron); });
    std::cout << "Búsqueda Boyer-Moore: " << tiempoBM << " microsegundos\n";

    // Búsqueda Rabin-Karp
    long long tiempoRK = medirTiempo([&]() { busquedaRabinKarp(texto, patron); });
    std::cout << "Búsqueda Rabin-Karp: " << tiempoRK << " microsegundos\n";

    // Búsqueda Aho-Corasick
    std::vector<std::string> patrones = {"algoritmos", "texto", "prueba"};
    long long tiempoAC = medirTiempo([&]() { busquedaAhoCorasick(texto, patrones); });
    std::cout << "Búsqueda Aho-Corasick: " << tiempoAC << " microsegundos\n\n";

    // ----------------------------
    // 4. Pruebas de Hash
    // ----------------------------
    std::cout << "=== Pruebas de Hash ===\n";
    const int tamanoHash = 10000;
    std::vector<int> datosHash(tamanoHash);
    for(int i=0;i<tamanoHash;i++) datosHash[i] = i;

    // Tabla Hash con Encadenamiento
    HashTablaEncadenamiento hashEncadenamiento;
    long long tiempoHashEncadenamiento = 0;
    for(auto num : datosHash){
        tiempoHashEncadenamiento += medirTiempo([&]() { hashEncadenamiento.insertar(num); });
    }
    std::cout << "Inserción en Hash con Encadenamiento: " << tiempoHashEncadenamiento << " microsegundos\n";

    // Tabla Hash con Linear Probing
    HashTablaLinearProbing hashLinear(tamanoHash * 2);
    long long tiempoHashLinear = 0;
    for(auto num : datosHash){
        tiempoHashLinear += medirTiempo([&]() { hashLinear.insertar(num); });
    }
    std::cout << "Inserción en Hash con Linear Probing: " << tiempoHashLinear << " microsegundos\n";

    // Puedes implementar y medir Quadratic Probing, Double Hashing y Cuckoo Hashing siguiendo el mismo patrón.

    return 0;
}
