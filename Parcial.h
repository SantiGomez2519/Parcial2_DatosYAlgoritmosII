#ifndef PARCIAL_H
#define PARCIAL_H

#include "Grafo.h"
#include "VecinoMasCercano.h"
#include <vector>

// Clase que encapsula la funcionalidad del grafo para el parcial
class Parcial {
private:
    Grafo grafo;  // Grafo que representa los establecimientos D1

public:
    // Carga los vértices en el grafo
    void cargar(const std::vector<Vertice>& vertices);

    // Ejecuta el algoritmo del Vecino más cercano en el grafo
    std::pair<std::vector<int>, std::vector<int>> run();

    // Imprime la estructura del grafo
    void imprimirGrafo() const;

    // Obtiene la lista de vértices del grafo
    std::vector<Vertice> obtenerVertices() const { return grafo.obtenerVertices(); }

    // Obtiene la distancia entre dos vértices
    double distancia(int origen, int destino) const { return grafo.distancia(origen, destino); };
};

#endif // PARCIAL_H