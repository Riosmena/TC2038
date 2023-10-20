// =============================================================================
// Archivo: main.cpp
// Authores: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Fecha: Jueves 21 de septiembre del 2023
// =============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    // Pide al usuario un string
    string input;
    cout << "Ingresa un string: ";
    cin >> input;

    // Crea un vector de strings con todas las substrings

    // Complejidad: O(n^2)
    vector<string> substrings;
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 1; j <= input.length() - i; j++)
        {
            // Crea una substring de la posición i con longitud j
            string substring = input.substr(i, j);
            substrings.push_back(substring);
        }
    }

    // Ordena el vector de substrings alfabéticamente
    sort(substrings.begin(), substrings.end());

    // Imprime las substrings ordenadas alfabéticamente

    // Complejidad: O(n)
    cout << "Substrings ordenados alfabeticamente: " << endl;
    for (const string &substring : substrings)
    {
        cout << substring << endl;
    }

    return 0;
}