// ====================================================
// Archivo: StringComunMasLargo.h
// Descripción : Se realiza una comparación entre archivos para identificar el
//               string común más grande entre dos archivos.
// Autor: María Azul Rosales Nachón - A01706348
// Fecha: 30 de Septiembre de 2023
// ====================================================

#ifndef ACTINT1_EQUIPO_01_STRINGCOMUNMASLARGO_H
#define ACTINT1_EQUIPO_01_STRINGCOMUNMASLARGO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Estructura para almacenar información sobre el substring común más largo.
struct SubstringInfo {
    string substring; // El substring común más largo.
    vector<pair<int, int>> posiciones1; // Posiciones del substring en el primer archivo.
    vector<pair<int, int>> posiciones2; // Posiciones del substring en el segundo archivo.
};



/*
La funcion encontrarTodasLasApariciones se encarga de encontrar todas las apariciones de una subcadena en un
texto y almacenar sus posiciones.
Tiempo de Compejidad O(m * n), donde m es la longitud del texto y n es la longitud de la subcadena. Espacio O(1).
 */
void encontrarTodasLasApariciones(const string& texto, const string& subcadena, vector<pair<int, int>>& posiciones) {
    int pos = texto.find(subcadena);
    while (pos != string::npos) {
        posiciones.emplace_back(pos, pos + subcadena.length() - 1);
        pos = texto.find(subcadena, pos + 1);
    }
}

/*
La funcion encontrarSubstringComun se encarga de  encontrar el substring común más largo entre dos archivos.
Tiempo de Complejidad O(m * n) | Espacio O(m * n)
 */
SubstringInfo encontrarSubstringComun(const string& archivo1, const string& archivo2) {
    ifstream archivo1Stream(archivo1);
    ifstream archivo2Stream(archivo2);

    SubstringInfo result;
    result.substring = "";

    // Verificar si los archivos se abren correctamente.
    if (!archivo1Stream.is_open() || !archivo2Stream.is_open()) {
        cerr << "Error al abrir uno o ambos archivos." << endl;
        return result;
    }

    string linea1, linea2;
    string texto1, texto2;

    // Leer el contenido de ambos archivos línea por línea y almacenarlos como texto.
    while (getline(archivo1Stream, linea1)) {
        texto1 += linea1 + '\n'; // Incluir saltos de línea
    }

    while (getline(archivo2Stream, linea2)) {
        texto2 += linea2 + '\n'; // Incluir saltos de línea
    }

    archivo1Stream.close();
    archivo2Stream.close();

    // Algoritmo para encontrar el substring común más largo utilizando una matriz de programación dinámica.
    int m = texto1.length();
    int n = texto2.length();
    vector<vector<int>> matriz(m + 1, vector<int>(n + 1, 0));
    int longitudMaxima = 0;
    int finPosicion = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (texto1[i - 1] == texto2[j - 1]) {
                matriz[i][j] = matriz[i - 1][j - 1] + 1;
                if (matriz[i][j] > longitudMaxima) {
                    longitudMaxima = matriz[i][j];
                    finPosicion = i;
                }
            }
        }
    }

    // Obtener el substring común más largo y encontrar sus posiciones en ambos archivos.
    if (longitudMaxima > 0) {
        result.substring = texto1.substr(finPosicion - longitudMaxima, longitudMaxima);
        encontrarTodasLasApariciones(texto1, result.substring, result.posiciones1);
        encontrarTodasLasApariciones(texto2, result.substring, result.posiciones2);
    }

    return result;
}

#endif // ACTINT1_EQUIPO_01_PARTE3_H
