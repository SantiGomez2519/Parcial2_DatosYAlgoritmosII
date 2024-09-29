// VecinoMasCercano.h
#ifndef VECINOMASCERCANO_H
#define VECINOMASCERCANO_H

#include <vector>
#include <utility>
#include "Grafo.h"

class VecinoMasCercano {
private:
    const Grafo& grafo;

public:
    // Constructor que recibe el grafo como referencia
    VecinoMasCercano(const Grafo& g);

    // Método que implementa el algoritmo del vecino más cercano con dos nodos de inicio
    std::pair<std::vector<int>, std::vector<int>> resolver(int inicio1, int inicio2);
};

#endif // VECINOMASCERCANO_H
