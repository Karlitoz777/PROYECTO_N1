#include "AlgoritmosTextuales.h"
#include <unordered_map>
#include <queue>
#include <algorithm>

// 1. Búsqueda por Fuerza Bruta
int busquedaFuerzaBruta(const std::string& texto, const std::string& patron) {
    int n = texto.size();
    int m = patron.size();
    for(int i=0;i<=n-m;i++) {
        int j=0;
        for(;j<m;j++) {
            if(texto[i+j] != patron[j])
                break;
        }
        if(j == m)
            return i;
    }
    return -1;
}

// 2. Knuth-Morris-Pratt (KMP)
std::vector<int> construirTablaKMP(const std::string& patron) {
    int m = patron.size();
    std::vector<int> lps(m, 0);
    int len =0;
    for(int i=1;i<m;i++) {
        if(patron[i] == patron[len]){
            len++;
            lps[i] = len;
        }
        else{
            if(len !=0){
                len = lps[len-1];
                i--;
            }
            else{
                lps[i] =0;
            }
        }
    }
    return lps;
}

int busquedaKMP(const std::string& texto, const std::string& patron) {
    int n = texto.size();
    int m = patron.size();
    if(m ==0) return 0;
    std::vector<int> lps = construirTablaKMP(patron);
    int i=0, j=0;
    while(i < n){
        if(patron[j] == texto[i]){
            i++;
            j++;
        }
        if(j == m)
            return i - j;
        else if(i < n && patron[j] != texto[i]){
            if(j !=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return -1;
}

// 3. Boyer-Moore (Implementación Simplificada)
int busquedaBoyerMoore(const std::string& texto, const std::string& patron) {
    int n = texto.size();
    int m = patron.size();
    if(m ==0) return 0;
    std::unordered_map<char, int> badChar;
    for(int i=0;i<m;i++) {
        badChar[patron[i]] = i;
    }
    int shift =0;
    while(shift <= n - m) {
        int j = m-1;
        while(j >=0 && patron[j] == texto[shift + j])
            j--;
        if(j <0){
            return shift;
        }
        else{
            char bad = texto[shift + j];
            if(badChar.find(bad) != badChar.end())
                shift += std::max(1, j - badChar[bad]);
            else
                shift += j +1;
        }
    }
    return -1;
}

// 4. Rabin-Karp (Implementación Simplificada)
int busquedaRabinKarp(const std::string& texto, const std::string& patron) {
    int n = texto.size();
    int m = patron.size();
    if(m ==0) return 0;
    const int prime = 101;
    long long patHash =0, txtHash =0, power =1;
    for(int i=0;i<m;i++) {
        patHash = (patHash * 256 + patron[i]) % prime;
        txtHash = (txtHash * 256 + texto[i]) % prime;
        if(i < m-1) power = (power * 256) % prime;
    }
    for(int i=0;i<=n-m;i++) {
        if(patHash == txtHash) {
            bool match = true;
            for(int j=0;j<m;j++)
                if(texto[i+j] != patron[j]){
                    match = false;
                    break;
                }
            if(match) return i;
        }
        if(i < n - m){
            txtHash = (txtHash - texto[i] * power) * 256 + texto[i+m];
            txtHash %= prime;
            if(txtHash <0) txtHash += prime;
        }
    }
    return -1;
}

// 5. Aho-Corasick (Implementación Corregida y Completa)
struct NodoAhoCorasick {
    std::unordered_map<char, NodoAhoCorasick*> hijos;
    NodoAhoCorasick* fallo;
    std::vector<std::string> salidas;
    NodoAhoCorasick() : fallo(nullptr) {}
};

// Función para construir el automata Aho-Corasick
void construirAutomata(NodoAhoCorasick* raiz, const std::vector<std::string>& patrones) {
    // Construir el trie
    for(const auto& patron : patrones){
        NodoAhoCorasick* nodo = raiz;
        for(char c : patron){
            if(nodo->hijos.find(c) == nodo->hijos.end())
                nodo->hijos[c] = new NodoAhoCorasick();
            nodo = nodo->hijos[c];
        }
        nodo->salidas.push_back(patron);
    }
    // Construir las transiciones de fallo
    std::queue<NodoAhoCorasick*> cola;
    // Inicializar la fila de nivel 1
    for(auto& [c, nodo] : raiz->hijos){
        nodo->fallo = raiz;
        cola.push(nodo);
    }
    // Procesar los niveles siguientes
    while(!cola.empty()){
        NodoAhoCorasick* current = cola.front(); cola.pop();
        for(auto& [c, child] : current->hijos){
            NodoAhoCorasick* fallo = current->fallo;
            while(fallo != nullptr && fallo->hijos.find(c) == fallo->hijos.end())
                fallo = fallo->fallo;
            if(fallo == nullptr)
                child->fallo = raiz;
            else
                child->fallo = fallo->hijos[c];
            // Agregar las salidas del nodo de fallo al nodo hijo
            for(auto& patron : child->fallo->salidas)
                child->salidas.push_back(patron);
            cola.push(child);
        }
    }
}

std::vector<int> busquedaAhoCorasick(const std::string& texto, const std::vector<std::string>& patrones) {
    NodoAhoCorasick* raiz = new NodoAhoCorasick();
    construirAutomata(raiz, patrones);
    std::vector<int> posiciones;
    NodoAhoCorasick* estado = raiz;
    for(int i=0;i<texto.size();i++) {
        char c = texto[i];
        while(estado != raiz && estado->hijos.find(c) == estado->hijos.end())
            estado = estado->fallo;
        if(estado->hijos.find(c) != estado->hijos.end())
            estado = estado->hijos[c];
        for(auto& patron : estado->salidas){
            posiciones.push_back(i - patron.size() +1);
        }
    }
    // Liberar memoria
    // Aquí deberías implementar una función para liberar toda la memoria asignada dinámicamente
    // Por brevedad, esto no está incluido, pero es importante para evitar fugas de memoria
    return posiciones;
}
