// ========================================================
// Archivo: main.cpp
// Authores: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Fecha: Lunes, 6 de noviembre del 2023
// ========================================================

#include <iostream>
#include <vector>

using namespace std;

// Función que verifica si es seguro asignar un color a un vertice
bool isSafe(int v, vector<int> &color, vector<vector<int>> &graph, int c)
{
    // Se verifica si el color c es seguro para el vertice v
    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[v][i] && c == color[i])
        {
            return false;
        }
    }
    return true;
}
// Complejidad: O(n)

// Función que asigna colores a los nodos
bool graphColoringUtil(vector<vector<int>> &graph, int m, vector<int> &color, int v)
{
    // Caso base: si todos los nodos tienen un color asignado, se regresa true
    if (v == graph.size())
    {
        return true;
    }

    // Se consideran los colores de 1 a m
    for (int c = 0; c < m; ++c)
    {
        // Se verifica si es seguro asignar el color c al vertice v
        if (isSafe(v, color, graph, c))
        {
            color[v] = c;

            // Se asigna el color c al vertice v y se verifica si se puede asignar un color a los nodos restantes
            if (graphColoringUtil(graph, m, color, v + 1))
            {
                return true;
            }

            // Si no se puede asignar el color c al vertice v, se remueve
            color[v] = -1;
        }
    }
    return false;
}
// Complejidad: O(n * m)

// Función que asigna colores a los nodos
void graphColoring(vector<vector<int>> &graph)
{
    // Se inicializa el vector de colores con -1
    int numNodes = graph.size();
    vector<int> color(numNodes, -1);
    int numColors = 3;

    // Se asignan los colores a los nodos
    if (graphColoringUtil(graph, numColors, color, 0))
    {
        for (int i = 0; i < numNodes; ++i)
        {
            cout << "Vertice: " << i << ", Color asignado: " << color[i] << endl;
        }
    }

    // Si no se puede asignar un color a los nodos, se imprime un mensaje
    else
    {
        cout << "No es posible asignar colores a los nodos." << endl;
    }
}
// Complejidad: O(n * m)

int main(int argc, char *argv[])
{
    // Se pide al usuario el numero de nodos y la matriz de adyacencia
    int numNodes;
    cout << "Introduce el numero de nodos: ";
    cin >> numNodes;
    cout << endl;

    // Se crea la matriz de adyacencia
    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));
    cout << "Introduce la matriz de adyacencia: " << endl;
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            cin >> graph[i][j];
        }
    }

    cout << endl;

    // Se asignan los colores a los nodos
    graphColoring(graph);

    return 0;
}