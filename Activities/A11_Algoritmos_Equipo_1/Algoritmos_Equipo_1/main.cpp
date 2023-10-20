// ======================================================
// Archivo: main.cpp
// Autores: Maria Azul Rosales Nachón - A01706348
//          José Emiliano Riosmena Castañón - A01704245
//          Mauricio García Villanueva - A01704098
// Fecha: Lunes, 14 de Agosto del 2023
// ======================================================

#include <iostream>
#include <cmath>

using namespace std;

// Función para calcular el tiempo estimado de producción
int tiempoEsperado(int prod1, int prod2, int qnty){
    return qnty / (prod1 + prod2);
}

// Función para calcular el número de botellas llenas
int refrescosLlenos(float r, float h, int v_botella){
    // Volumen del cilindro: V = π * r ^ 2 * h
    return ((3.1416 * h * r * r) / 0.000001) / v_botella;
}

int main() {

    // Problema 1
    int linea1;
    int linea2;
    int playeras;
    
    // Entradas para las líneas 1 y 2, y cantidad de playeras
    cout << "Capacidad de produccion diaria - L1: ";
    cin >> linea1;
    cout << "Capacidad de produccion diaria - L2: ";
    cin >> linea2;
    cout << "Cantidad de playeras a producir: ";
    cin >> playeras;
    
    /* Llamamos a la función para mostrar el tiempo esperado 
    con respecto a las entradas */

    cout << "Dias para producir: ";
    cout << tiempoEsperado(linea1, linea2, playeras);
    
    cout << endl << endl;
    
    // Problema 2
    float radio;
    float altura;
    int v_botella;

    // Entradas para el radio, altura y volumen en mililitros
    cout << "Radio de la base del contenedor: ";
    cin >> radio;
    cout << "Altura del contenedor: ";
    cin >> altura;
    cout << "Volumen botella: ";
    cin >> v_botella;
    
    /* Llamamos a la función para mostrar el número de botellas
    que se llenaran */

    cout << "Botellas llenas: ";
    cout << refrescosLlenos(radio, altura, v_botella);

    return 0;
}

// Fin del programa