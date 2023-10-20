// ========================================================
// Archivo: main.cpp
// Authores: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Fecha: Miercoles 20 de septiembre del 2023
// ========================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

// Función para calcular la suma de los valores ASCII en una columna de una tabla
int sumaASCII(const vector<string> &tabla, int columna)
{
    int suma = 0;
    for (const string &fila : tabla)
    {
        if (columna < fila.length())
        {
            suma += static_cast<int>(fila[columna]);
        }
    }
    return suma % 256;
}

int main(int argc, char *argv[])
{
    string nombreArchivo;
    int n;

    // Leer los argumentos ingresados por el usuario
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;
    cout << "Ingrese un numero entero: ";
    cin >> n;

    /* Verificación de que se hayan pasado los argumentos correctos
    en el nombre del archivo y el número n */

    // Verificar que el número sea un múltiplo de 4 entre 16 y 64
    if (n < 16 || n > 64 || n % 4 != 0)
    {
        cout << "El número debe ser un múltiplo de 4 entre 16 y 64" << endl;
        return 1;
    }

    ifstream archivo(nombreArchivo + ".txt");

    // Verificar que se haya pasado el nombre del archivo correcto
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    // Leer el archivo y guardar cada línea en un vector
    vector<string> tabla;
    string linea;
    while (getline(archivo, linea))
    {
        tabla.push_back(linea);
    }

    archivo.close();

    // Rellenar la última fila si es necesario
    int filas = tabla.size();
    int columnas = n;

    if (filas * columnas % n != 0)
    {
        int faltantes = n - (filas * columnas % n);
        for (int i = 0; i < faltantes; i++)
        {
            tabla[filas - 1] += " ";
        }
    }

    // Imprimir la matriz generada por el algoritmo
    cout << endl
         << "Matriz generada por el algoritmo:" << endl;

    for (const string &fila : tabla)
    {
        cout << fila << endl;
    }

    // Calcular la suma de las columnas con el modulo 256
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = sumaASCII(tabla, i);
    }

    // Imprimir el arreglo de longitud n
    cout << endl
         << "Arreglo de longitud " << n
         << " que muestra la suma de las columnas con el modulo 256"
         << endl;
    for (int valor : a)
    {
        cout << valor << " ";
    }
    cout << endl;

    // Imprimir la representación hexadecimal del arreglo
    stringstream resultadoHex;
    for (int valor : a)
    {
        resultadoHex << setw(2) << setfill('0') << hex << valor;
    }

    cout << endl
         << "Representacion hexadecimal: " << endl;

    // Imprimir la representación hexadecimal con espacios cada 4 caracteres
    string resultado;
    for (int i = 0; i < resultadoHex.str().length(); i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            resultado += " ";
        }
        resultado += resultadoHex.str()[i];
    }

    // Imprimir la representación hexadecimal en mayúsculas
    for (int i = 0; i < resultado.length(); i++)
    {
        resultado[i] = toupper(resultado[i]);
    }

    cout << resultado << endl;

    return 0;
}