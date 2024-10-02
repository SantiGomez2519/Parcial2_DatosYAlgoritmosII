#include "Parcial.h"

// Carga los vértices en el grafo
//
// Pseudocódigo:
// Procedimiento cargar(vertices)
//     Para cada v en vertices
//         grafo.agregarVertice(v)
//     Fin Para
// Fin Procedimiento
//
// Explicación:
// - Iteramos sobre cada vértice en la lista proporcionada.
// - Agregamos cada vértice al grafo utilizando el método agregarVertice().
// - Esto inicializa el grafo con todos los establecimientos D1.
void Parcial::cargar(const std::vector<Vertice>& vertices) {
    for (const auto& v : vertices) {
        grafo.agregarVertice(v);
    }
}

// Ejecuta el algoritmo del Vecino más Cercano en el grafo
//
// Pseudocódigo:
// Función run()
//     VecinoMasCercano vecinoMasCercano(grafo)        
//     return vecinoMasCercano.resolver(0, 1)
// Fin Función
//
// Explicación:
// - Llamamos al método resolver() del vecinoMasCercano, comenzando desde el vértice 0 y 1.
// - Esto calcula las rutas más cortas desde las dos bodegas a los demás establecimiento.
// - Retornamos el resultado del algoritmo del vecino más cercano (rutas).
std::pair<std::vector<int>, std::vector<int>> Parcial::run() {
    VecinoMasCercano vecinoMasCercano(grafo);
    return vecinoMasCercano.resolver(0, 1);
}

// Imprime la estructura del grafo
//
// Explicación:
// - Simplemente llamamos al método imprimirGrafo() del objeto grafo.
// - Esto mostrará todos los vértices y sus conexiones.
void Parcial::imprimirGrafo() const {
    grafo.imprimirGrafo();
}