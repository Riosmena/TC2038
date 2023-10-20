// ====================================================
// File: main.cpp
// Descpcion : Se realiza una búsqueda del código malicioso en cada archivo de transmisión
//        y muestra el resultado de la búsqueda, en caso de ser encontrado imprime tambien la posicion.
// Autor: Mauricio García Villanueva - A01704098
// Fecha: 23 de Septiembre de 2023
// ====================================================

#ifndef ACTINT1_EQUIPO_01_BUSQUEDAKMP_H
#define ACTINT1_EQUIPO_01_BUSQUEDAKMP_H

#include "BusquedaKMP.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
La función construirLPS se encarga de calcular el arreglo LPS
Tiempo Complejidad O(m) | Espacio (m) en donde m es la longuitd de la subcadena.
*/
vector<int> construirLPS(const string &subcadena)
{
    int m = subcadena.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (subcadena[i] == subcadena[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

/*
La función algoritmoKMP se encarga de buscar el codigo malicioso
Tiempo Complejidad O(n) | Espacio (1) en donde n es la longuitd de la cadena donde estamos buscando el codigo malicioso

Tomando en cuenta que dentro de esta funcion se llama a la funcion construirLPS el tiempo y espacio de complejidad
se ven afectados ->  Tiempo Complejidad O(m+n) | Espacio (m+n)
 */
int algoritmoKMP(const string &textoTransmision, const string &codigoMalicioso)
{
    int n = textoTransmision.length();
    int m = codigoMalicioso.length();
    vector<int> lps = construirLPS(codigoMalicioso);

    int i = 0; // Índice para el texto de transmisión
    int j = 0; // Índice para la subcadena

    while (i < n)
    {
        if (codigoMalicioso[j] == textoTransmision[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            // Se encontró una coincidencia, devuelve la posición (en esa linea)
            return i - j;
        }
        else if (i < n && codigoMalicioso[j] != textoTransmision[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return -1; // No se encontró ninguna coincidencia
}

/*
La funcion lectorArchivos coordina la búsqueda del código malicioso en el archivo de transmisión y utiliza la
función algoritmoKMP para realizar la búsqueda en cada línea del archivo
 */
bool lectorArchivos(const string &archivoTransmision, const string &archivoCodigo)
{
    ifstream archivo(archivoTransmision);
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo de transmisión: " << archivoTransmision << endl;
        return false;
    }

    string codigoMalicioso;
    ifstream archivoCodigoMalicioso(archivoCodigo);
    if (!archivoCodigoMalicioso.is_open())
    {
        cerr << "Error al abrir el archivo de código malicioso: " << archivoCodigo << endl;
        archivo.close();
        return false;
    }

    getline(archivoCodigoMalicioso, codigoMalicioso);
    archivoCodigoMalicioso.close();

    // Variable para guardar el texto de transmissions
    string textoTransmision;
    int posicionGlobal = 0;

    string linea;
    while (getline(archivo, linea))
    {
        textoTransmision += linea + '\n'; // Agrega la línea al texto de transmisión
    }

    archivo.close();

    // Llama a algoritmoKMP con el texto completo
    int resultado = algoritmoKMP(textoTransmision, codigoMalicioso);

    if (resultado != -1)
    {
        // Se encontró una coincidencia, imprime el resultado
        cout << "true " << resultado + posicionGlobal << endl;
        return true;
    }
    else
    {
        return false;
    }
}

#endif // ACTINT1_EQUIPO_01_BUSQUEDAKMP_H
