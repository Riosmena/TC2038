// ========================================================
// Archivo: main.cpp
// Authores: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Fecha: Martes, 24 de octubre del 2023
// ========================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para resolver el problema de la mochila
int knapsack(int N, vector<int> &beneficios, vector<int> &pesos, int W, vector<vector<int>> &matriz)
{
    // Llenar la matriz
    for (int i = 0; i <= N; ++i)
    {
        // Llenar la fila i
        for (int w = 0; w <= W; ++w)
        {
            // Casos base
            if (i == 0 || w == 0)
            {
                // No hay elementos o no hay capacidad
                matriz[i][w] = 0;
            }

            // Caso recursivo
            else if (pesos[i - 1] <= w)
            {
                // Tomar el máximo entre el beneficio de tomar el elemento y el beneficio de no tomarlo
                matriz[i][w] = max(beneficios[i - 1] + matriz[i - 1][w - pesos[i - 1]], matriz[i - 1][w]);
            }

            // No se puede tomar el elemento
            else
            {
                // Tomar el beneficio de no tomar el elemento
                matriz[i][w] = matriz[i - 1][w];
            }
        }
    }

    // Regresar el mejor beneficio
    return matriz[N][W];
}
// Complejidad: O(NW)

// Función para mostrar la matriz
void mostrarMatriz(const vector<vector<int>> &matriz)
{
    // Recorrer las filas
    for (const auto &fila : matriz)
    {
        // Recorrer los elementos de la fila
        for (int valor : fila)
        {
            // Mostrar el valor
            cout << valor << " ";
        }
        cout << endl;
    }
}
// Complejidad: O(NW)

int main(int argc, char *argv[])
{
    // Leer los datos
    int N;
    cout << "Numero de elementos: ";
    cin >> N;

    // Crear los vectores
    vector<int> beneficios(N);
    vector<int> pesos(N);

    // Leer los beneficios
    cout << endl
         << "Introduzca los beneficios" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << "Beneficio " << i + 1 << ": ";
        cin >> beneficios[i];
    }
    cout << endl;

    // Leer los pesos
    cout << "Introduzca los pesos" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << "Peso " << i + 1 << ": ";
        cin >> pesos[i];
    }
    cout << endl;

    // Leer la capacidad de la mochila
    int W;
    cout << "Capacidad de la mochila: ";
    cin >> W;

    // Mostrar los resultados
    cout << endl
         << "=========================\nResultados " << endl;

    // Crear la matriz
    vector<vector<int>> matriz(N + 1, vector<int>(W + 1, 0));

    // Calcular el mejor beneficio
    int mejorBeneficio = knapsack(N, beneficios, pesos, W, matriz);

    // Mostrar el mejor beneficio
    cout << endl
         << "Mejor beneficio: " << mejorBeneficio << endl;

    // Mostrar la matriz
    cout << endl
         << "Matriz: " << endl;
    mostrarMatriz(matriz);

    return 0;
}