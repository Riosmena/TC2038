// ====================================================
// Archivo: Palindromo.h
// Descripción : Se realiza una comparación para
//              conocer si una cadena es un palindromo.
// Autor: José Emiliano Riosmena Castañón - A01704245
// Fecha: 25 de Septiembre de 2023
// ====================================================

#ifndef ACTINT1_EQUIPO_01_PALINDROMO_H
#define ACTINT1_EQUIPO_01_PALINDROMO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Función para verificar si una cadena es palíndromo
// Tiempo Complejidad O(n) | Espacio (1) en donde n es la longuitd de la cadena

bool esPalindromo(const string &str)
{
    int inicio = 0;
    int fin = str.length() - 1;

    while (inicio < fin)
    {
        // Si los caracteres no coinciden, no es palíndromo
        if (str[inicio] != str[fin])
        {
            return false;
        }

        inicio++;
        fin--;
    }

    return true;
}

#endif // ACTINT1_EQUIPO_01_PARTE2_H