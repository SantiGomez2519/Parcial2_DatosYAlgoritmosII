#include <iostream>
#include "Grafo.h"
#include "VecinoMasCercano.cpp"

int main() {
    Grafo g;

    // Agrega vértices al grafo
    g.agregarVertice(Vertice{"Centro", 6.2442, -75.5812});
    g.agregarVertice(Vertice{"Poblado", 6.2084, -75.5687});
    g.agregarVertice(Vertice{"Laureles", 6.2453, -75.5939});
    g.agregarVertice(Vertice{"Belén", 6.2308, -75.6075});
    g.agregarVertice(Vertice{"Envigado", 6.1664, -75.5836});

    VecinoMasCercano vecinoMasCercano(g);
    int nodoInicial = 0; // Puedes elegir cualquier nodo como inicio
    int nodoInicial2 = 1; // Puedes elegir cualquier nodo como inicio
    std::pair<std::vector<int>, std::vector<int>> rutas = vecinoMasCercano.resolver(nodoInicial, nodoInicial2);

    std::vector<int> ruta1 = rutas.first; // Assuming you want the first vector in the pair
    std::vector<int> ruta2 = rutas.second; // Assuming you want the second vector in the pair

    // Mostrar la ruta encontrada
    std::cout << "Ruta 1 encontrada: ";
    for (int nodo : ruta1) {
        std::cout << nodo << " ";
    }
    std::cout << "Ruta 2 encontrada: ";
    for (int nodo : ruta2) {
        std::cout << nodo << " ";
    }

    // Calcular la distancia total de la ruta
    double distanciaTotal = 0;
    for (size_t i = 0; i < ruta1.size() - 1; ++i) {
        distanciaTotal += g.distancia(ruta1[i], ruta1[i + 1]);
    }
    for (size_t i = 0; i < ruta2.size() - 1; ++i) {
        distanciaTotal += g.distancia(ruta2[i], ruta2[i + 1]);
    }

    std::cout << "La distancia total es: " << distanciaTotal;
    std::cout << std::endl;
}
