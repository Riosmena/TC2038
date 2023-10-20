// ========================================================
// Archivo: main.cpp
// Authores: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Fecha: Viernes, 20 de octubre del 2023
// ========================================================

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Funcion para encontrar el camino mas corto entre dos nodos mediante el algoritmo de Dijkstra
void dijkstra(vector<vector<int>> &graph, int startNode, int n)
{
    // Se inicializan los vectores de distancias y visitados
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    // Se inicializa la distancia del nodo inicial como 0
    dist[startNode] = 0;

    // Encontrar el camino mas corto entre el nodo inicial y todos los demas nodos
    for (int i = 0; i < n - 1; ++i)
    {
        // Encontrar el nodo con la distancia mas corta que no haya sido visitado
        int minDist = INT_MAX, minIndex;

        // Se busca el nodo con la distancia mas corta
        for (int j = 0; j < n; ++j)
        {
            // Si el nodo no ha sido visitado y su distancia es menor a la distancia minima
            if (!visited[j] && dist[j] < minDist)
            {
                // Se actualiza la distancia minima y el indice del nodo
                minDist = dist[j];
                minIndex = j;
            }
        }

        // Se marca el nodo como visitado
        visited[minIndex] = true;

        // Se actualizan las distancias de los nodos adyacentes al nodo actual
        for (int j = 0; j < n; ++j)
        {
            // Si el nodo no ha sido visitado, hay una conexion entre el nodo actual y el nodo adyacente
            if (!visited[j] && graph[minIndex][j] != -1 && dist[minIndex] != INT_MAX && dist[minIndex] + graph[minIndex][j] < dist[j])
            {
                // Se actualiza la distancia del nodo adyacente
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    // Se imprimen las distancias
    for (int i = 0; i < n; ++i)
    {
        // Si el nodo no es el nodo inicial
        if (i != startNode)
        {
            // Se imprime la distancia del nodo inicial al nodo actual
            cout << "node " << startNode + 1 << " to node " << i + 1 << ": ";

            // Si la distancia es diferente de infinito, se imprime la distancia
            if (dist[i] != INT_MAX)
            {
                cout << dist[i] << endl;
            }
            // Si no, no hay camino
            else
            {
                cout << "No path" << endl;
            }
        }
    }
}
// Complejidad: O(n^2)

// Funcion para encontrar el camino mas corto entre dos nodos mediante el algoritmo de Floyd
void floyd(vector<vector<int>> &graph, int n)
{
    // Se inicializa la matriz de distancias
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // Si hay una conexion entre el nodo i y el nodo k y entre el nodo k y el nodo j
                if (graph[i][k] != -1 && graph[k][j] != -1 && (graph[i][j] == -1 || graph[i][k] + graph[k][j] < graph[i][j]))
                {
                    // Se actualiza la distancia entre el nodo i y el nodo j
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Se imprimen las distancias
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
// Complejidad: O(n^3)

int main(int argc, char *argv[])
{
    // Inicializamos el tamaño de la matriz
    int n;
    cout << "Input the size of the matrix: ";
    cin >> n;

    // Inicializamos la matriz de adyacencia
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Input the matrix values:" << endl;

    // Leemos la matriz de adyacencia
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    // Se imprimen las distancias minimas con Dijkstra
    cout << endl
         << "Dijkstra:" << endl;
    for (int i = 0; i < n; ++i)
    {
        dijkstra(graph, i, n);
    }

    // Se imprimen las distancias minimas con Floyd
    cout << endl
         << "Floyd:" << endl;
    floyd(graph, n);

    // Se termina el programa
    return 0;
}
