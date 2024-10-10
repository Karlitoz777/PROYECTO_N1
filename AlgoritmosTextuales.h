#ifndef ALGORITMOSTEXTUALES_H
#define ALGORITMOSTEXTUALES_H

#include <string>
#include <vector>

// Declaraciones de funciones de búsqueda textual
int busquedaFuerzaBruta(const std::string& texto, const std::string& patron);
int busquedaKMP(const std::string& texto, const std::string& patron);
int busquedaBoyerMoore(const std::string& texto, const std::string& patron);
int busquedaRabinKarp(const std::string& texto, const std::string& patron);
std::vector<int> busquedaAhoCorasick(const std::string& texto, const std::vector<std::string>& patrones);

#endif // ALGORITMOSTEXTUALES_H

