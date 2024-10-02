#include "Parcial.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

// Para compilar: g++ EvaluarParcial.cpp Parcial.cpp VecinoMasCercano.cpp Grafo.cpp -o evaluador -O3 -ftree-vectorize -fopenmp -mavx2

// Clase para evaluar el rendimiento y resultados del parcial
class EvaluarParcial {
public:

    void ejecutar() {
        Parcial parcial;

        // Datos de ejemplo (coordenadas aproximadas de algunos barrios de Medellín)
        std::vector<Vertice> vertices = {
            {"Bodega Sur", 6.20000, -75.57000},
            {"Bodega Norte", 6.30000, -75.57000},
            {"D1 Laureles", 6.23457, -75.58132},
            {"D1 Estadio", 6.24931, -75.57014},
            {"D1 Belén", 6.26708, -75.56435},
            {"D1 Envigado", 6.17123, -75.58291},
            {"D1 Poblado", 6.20528, -75.56719},
            {"D1 Centro", 6.24611, -75.56889},
            {"D1 Castilla", 6.28512, -75.55987},
            {"D1 Robledo", 6.29876, -75.58743},
            {"D1 Buenos Aires", 6.24032, -75.57561},
            {"D1 Manrique", 6.27394, -75.55203},
            {"D1 Aranjuez", 6.25817, -75.56128},
            {"D1 Floresta", 6.23019, -75.57845},
            {"D1 Guayabal", 6.21854, -75.59320},
            {"D1 Itagui", 6.16256, -75.60183},
            {"D1 Sabaneta", 6.14589, -75.61027},
            {"D1 El Salvador", 6.2389163360910915, -75.56056794770858},
            {"D1 San Diego", 6.239757524435364, -75.56793218132314},
            {"D1 Unicentro", 6.241380025216626, -75.58602416890596},
            {"D1 Belén Rincón", 6.213806578967952, -75.60176056520928},
            {"D1 Guayabas", 6.202236924156238, -75.58559460657207},
            {"D1 Exposiciones", 6.238446500715659, -75.57350886717384},
            {"D1 La 65", 6.246080619829119, -75.58399445198604},
            {"D1 Colombia", 6.257507431810545, -75.5829787918462},
            {"D1 Sudamericana", 6.253973236291311, -75.58221131931738},
            {"D1 Popular 1", 6.2962335581324185, -75.54914161317058}
        };

        // Cargar datos
        parcial.cargar(vertices);

        // parcial.imprimirGrafo();

        // Medir tiempo de ejecución de run()
        auto inicio = std::chrono::high_resolution_clock::now();
        
        // Ejecutar el algoritmo y obtener resultados
        std::pair<std::vector<int>, std::vector<int>> resultado = parcial.run();
        
        auto fin = std::chrono::high_resolution_clock::now();

        std::vector<int> ruta1 = resultado.first;
        std::vector<int> ruta2 = resultado.second;

        // Calcular duración
        auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);

        // Imprimir resultados
        std::cout << "Tiempo de ejecución del método run(): " 
                  << duracion.count() << " microsegundos" << std::endl;


        auto vertices_grafo = parcial.obtenerVertices();

        std::cout << "\nRutas más cortas desde Bodega Sur: \n";
        for (int nodo : ruta1) {
            std::cout << vertices_grafo[nodo].nombre << "-> ";
        }

        std::cout << std::endl;

        std::cout << "\nRutas más cortas desde Bodega Norte: \n";
        for (int nodo : ruta2) {
            std::cout << vertices_grafo[nodo].nombre << "-> ";
        }
        
        // Imprimir la distancia total
        double distanciaTotal = 0;

        for (size_t i = 0; i < ruta1.size() - 1; ++i) {
            distanciaTotal += parcial.distancia(ruta1[i], ruta1[i + 1]);
        }
        for (size_t i = 0; i < ruta2.size() - 1; ++i) {
            distanciaTotal += parcial.distancia(ruta2[i], ruta2[i + 1]);
        }

        std::cout << "\nLa distancia total es: " << distanciaTotal << "km" << std::endl;
    }
};

int main() {
    EvaluarParcial evaluador;
    evaluador.ejecutar();
    return 0;
}