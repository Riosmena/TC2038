// ====================================================
// Archivo: main.cpp
// Descripción: AI1_Actividad Integradora 1, busqueda
//             de codigo malicioso dentro de archivos
//             de transmisión.
// Autores: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Fecha: 1 de Octubre de 2023
// ====================================================

#include "BusquedaKMP.h"
#include "Palindromo.h"
#include <iostream>

using namespace std;

int main()
{

    /*
     PARTE 1
        Se realiza una búsqueda del código malicioso en cada archivo de transmisión
        y muestra el resultado de la búsqueda, en caso de ser encontrado imprime tambien la posicion.
     */

    cout << "Parte 1" << endl
         << "=====================================================" << endl;

    string archivosTransmision[] = {"transmissions01.txt", "transmissions02.txt"};
    string archivosCodigoMalicioso[] = {"mcode01.txt", "mcode02.txt", "mcode03.txt"};

    for (const string &archivoTransmision : archivosTransmision)
    {
        for (const string &archivoCodigo : archivosCodigoMalicioso)
        {
            bool encontrado = buscarCodigoEnArchivo(archivoTransmision, archivoCodigo);
            if (!encontrado)
            {
                cout << "false" << endl;
            }
        }
    }

    /*
    Parte 2
        Se realiza una comparación para conocer si una cadena es un palindromo.
    */

    cout << endl
         << "Parte 2" << endl
         << "=====================================================" << endl;

    vector<string> transmisiones = {"transmissions01.txt", "transmissions02.txt"};

    // Se recorre cada archivo de transmisión
    for (int i = 0; i < transmisiones.size(); i++)
    {
        ifstream archivo(transmisiones[i]);

        // Se verifica que el archivo se haya abierto correctamente
        if (!archivo.is_open())
        {
            cout << "No se pudo abrir el archivo " << transmisiones[i] << endl;
            return 1;
        }

        // Se lee el contenido del archivo
        string contenido;
        getline(archivo, contenido);
        archivo.close();

        // Se busca el palindromo más largo
        int inicio = 0;
        int fin = 0;
        string espejeado;

        // Se recorre la cadena para encontrar el palindromo más largo
        for (int j = 0; j < contenido.length(); j++)
        {
            // Se recorre la cadena desde la posición j
            for (int k = j + 1; k < contenido.length(); k++)
            {
                // Se obtiene la subcadena
                string sub = contenido.substr(j, k - j + 1);

                // Se verifica si la subcadena es palindromo y si es más larga que la anterior
                if (esPalindromo(sub) && sub.length() > espejeado.length())
                {
                    espejeado = sub;
                    inicio = j + 1;
                    fin = k + 1;
                }
            }
        }

        // Se imprime el resultado
        cout << inicio << " " << fin << " (para archivo de " << (transmisiones[i]) << ")" << endl;
    }

    return 0;
}
