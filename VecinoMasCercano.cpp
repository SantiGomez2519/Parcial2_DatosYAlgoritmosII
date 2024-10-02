#include "VecinoMasCercano.h"
#include <limits>
#include <omp.h> // Api para la paralelización del código

// Constructor que recibe el grafo
VecinoMasCercano::VecinoMasCercano(const Grafo& g) : grafo(g) {}

// Método que implementa el algoritmo del vecino más cercano con dos nodos de inicio
std::pair<std::vector<int>, std::vector<int>> VecinoMasCercano::resolver(int inicio1, int inicio2) {
    std::vector<int> ruta1, ruta2;
    std::vector<bool> visitado(grafo.size(), false); // Vector para saber los nodos que ya fueron visitados

    int actual1 = inicio1;
    int actual2 = inicio2;
    
    ruta1.push_back(actual1); // Añadir el primer nodo inicial a la primera ruta
    ruta2.push_back(actual2); // Añadir el segundo nodo inicial a la segunda ruta
    visitado[actual1] = true; // Marcar el primer nodo inicial como visitado
    visitado[actual2] = true; // Marcar el segundo nodo inicial como visitado

    // Bucle hasta visitar todos los nodos
    for (size_t i = 2; i < grafo.size(); ++i) {
        // Encuentra el vecino más cercano no visitado para el primer viajero
        int siguiente1 = -1;
        double menorDistancia1 = std::numeric_limits<double>::infinity();
        #pragma omp critical
        {
            for (int j = 0; j < grafo.size(); ++j) {
                if (!visitado[j]) {
                    double distancia = grafo.distancia(actual1, j);
                    if (distancia < menorDistancia1) {
                        menorDistancia1 = distancia;
                        siguiente1 = j; // Actualizar el nodo más cercano para el primer viajero
                    }
                }
            }

            // Encuentra el vecino más cercano no visitado para el segundo viajero
            int siguiente2 = -1;
            double menorDistancia2 = std::numeric_limits<double>::infinity();
            for (int j = 0; j < grafo.size(); ++j) {
                if (!visitado[j] && j != siguiente1) { // Evita que el segundo viajero seleccione el nodo del primero
                    double distancia = grafo.distancia(actual2, j);
                    if (distancia < menorDistancia2) {
                        menorDistancia2 = distancia;
                        siguiente2 = j; // Actualizar el nodo más cercano para el segundo viajero
                    }
                }
            }

            // Actualizar rutas y marcar los nodos como visitados
            if (siguiente1 != -1) {
                ruta1.push_back(siguiente1);
                visitado[siguiente1] = true;
                actual1 = siguiente1;
            }

            if (siguiente2 != -1) {
                ruta2.push_back(siguiente2);
                visitado[siguiente2] = true;
                actual2 = siguiente2;
            }
        }
    }
    // Retornar las dos rutas completas
    return {ruta1, ruta2};
}