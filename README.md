# Evaluación Parcial: Optimización de Rutas para D1 en Medellín

## Integrantes del grupo
- Santiago Gómez Ospina
- Miguel Angel Ortiz Puerta
- Lucas Higuita
- Juan Simón Ospina Marínez
## Introducción

Este proyecto es una extensión del parcial de Estructuras de Datos y Algoritmos II, enfocado en la optimización logística para la cadena de tiendas D1 en Medellín. El objetivo era desarrollar un sistema eficiente para calcular las rutas más cortas entre los establecimientos D1, utilizando un algoritmo. Para lograrlo, se implementó un método en el cuál, cada vértice (establecimiento del D1) en el grafo, está conectado con todos los otros vertices a tráves de aristas (distancia entre los establecimientos) y en conjunto con el algoritmo de dijkstra se logra recorrer cada grafo, tomando siempre la ruta mas corta entre los vertices vecinos y asegurandose de no visitar dos veces el mismo vértice.

## Contexto del problema

El escenario planteado inicial es el siguiente:

- D1 cuenta con más de 10 locales comerciales distribuidos en Medellín.
- Existen dos bodegas estratégicamente ubicadas: una en la zona norte y otra en la zona sur de la ciudad.
- Dos camiones, cada uno asignado a una bodega, son responsables de abastecer todos los locales.

El desafío original consistía en desarrollar un programa en C++ para determinar las dos rutas más cortas y eficientes para que los camiones abastezcan todos los locales, visitando cada uno una única vez.

## Extensión del Problema

En esta versión extendida del proyecto, hemos ampliado el alcance para incluir:

1. Implementación de una estructura de datos de grafo eficiente.
2. Carga de datos de los establecimientos D1.
3. Ejecución del algoritmo de un algoritmo para encontrar las rutas más cortas.
4. Medición precisa del tiempo de ejecución del algoritmo.

## Enfoque Adoptado
Este proyecto está diseñado para abordar una variante del problema del viajante de comercio (TSP) utilizando el algoritmo del vecino más cercano en un grafo, con la particularidad de que dos viajeros inician en distintos puntos del grafo. El objetivo principal es minimizar las distancias recorridas por ambos viajeros y asegurarse de que visiten todos los nodos del grafo sin repetir visitas.

El enfoque adoptado es una aproximación donde en cada paso los viajeros seleccionan el nodo no visitado más cercano, asegurando un comportamiento eficiente para resolver el TSP.

## Decisiones de Diseño
- Grafo como base del algoritmo: El proyecto incluye la implementación de una clase Grafo que representa el conjunto de nodos y las distancias entre ellos. Esta clase es fundamental para calcular las distancias entre los diferentes puntos y determinar los vecinos más cercanos de cada viajero.

- Simulación de dos viajeros: Una de las particularidades de este diseño es que se utilizan dos viajeros que parten de diferentes nodos. Cada viajero sigue el mismo algoritmo (el del vecino más cercano), pero el segundo viajero debe evitar seleccionar el nodo que el primero eligió en esa misma iteración. Esto genera dos rutas paralelas y complementarias.

- Control de visitas: Para evitar que los viajeros pasen por nodos ya visitados, se utiliza un vector booleano visitado que marca qué nodos han sido recorridos.

## Analisis de Resultados Obtenidos

- Distribución de trabajo entre los viajeros: Al emplear dos viajeros simultáneamente, el proyecto logra reducir el tiempo necesario para recorrer todos los nodos en comparación con el caso de un solo viajero.
- Complejidad: El algoritmo tiene una complejidad de O(𝑛^2) en el peor caso, donde 𝑛 es el número de nodos en el grafo, debido a que para cada nodo, cada viajero busca el nodo no visitado más cercano, lo que requiere comparar todas las distancias.}
- Paralelización: OpenMP mejora el rendimiento del algoritmo en sistemas con múltiples núcleos. Aunque no se paralelizan todos los aspectos del código, la sección crítica que determina los vecinos más cercanos se maneja de manera eficiente.

## Optimización Implementada y Posibles Mejoras
1. Optimización con OpenMP: Se ha implementado una optimización básica con OpenMP para manejar las secciones críticas donde ambos viajeros seleccionan los nodos más cercanos. Esto reduce los tiempos de ejecución en comparación con una versión completamente secuencial.

2. Posibles optimizaciones adicionales:

- Uso de Heurísticas Avanzadas: Implementar algoritmos más avanzados como Algoritmo Held Karp, Simulated Annealing o Búsqueda Tabú podría llevar a rutas más cercanas a la solución óptima.
- Mejor paralelización: Aunque OpenMP es una buena optimización inicial, el código podría beneficiarse de una paralelización más fina, dividiendo el trabajo de cálculo de distancias entre varios hilos.

## Compilación y Ejecución en Linux

1. Asegúrate de tener todos los archivos fuente en el mismo directorio.
2. Usa el Makefile proporcionado para compilar:
   ```
   make
   ```
3. Ejecuta el programa:
   ```
   ./run
   ```
## Compilación y Ejecución en Windows

1. Abrir la terminal y dirigirse a la dirección del archivo
2. Para compilar ejecutar:
   ```
     g++ EvaluarParcial.cpp Parcial.cpp VecinoMasCercano.cpp Grafo.cpp -o evaluador -O3 -ftree-vectorize -fopenmp -mavx2
3. Para Ejecutar:
   ```
   ./evaluador


