# Evaluación Parcial: Optimización de Rutas para D1 en Medellín

## Integrantes del grupo
- Santiago Gomez Ospina
- Miguel Angel Ortiz Puerta
- Lucas Higuita
- Juan Simón Ospina Marínez
## Introducción

Este proyecto es una extensión del parcial de Estructuras de Datos y Algoritmos II, enfocado en la optimización logística para la cadena de tiendas D1 en Medellín. El objetivo era desarrollar un sistema eficiente para calcular las rutas más cortas entre los establecimientos D1, utilizando el algoritmo de Dijkstra. Para lograrlo, se implementó un método en el cuál, cada vértice (establecimiento del D1) en el grafo, está conectado con todos los otros vertices a tráves de aristas (distancia entre los establecimientos) y en conjunto con el algoritmo de dijkstra se logra recorrer cada grafo, tomando siempre la ruta mas corta entre los vertices vecinos y asegurandose de no visitar dos veces el mismo vértice.

## Contexto del problema

El escenario planteado inicial es el siguiente:

- D1 cuenta con más de 10 locales comerciales distribuidos en Medellín.
- Existen dos bodegas estratégicamente ubicadas: una en la zona norte y otra en la zona sur de la ciudad.
- Dos camiones, cada uno asignado a una bodega, son responsables de abastecer todos los locales.

El desafío original consistía en desarrollar un programa en C++ para determinar las dos rutas más cortas y eficientes para que los camiones abastezcan todos los locales, visitando cada uno una única vez.

## Extensión del problema

En esta versión extendida del proyecto, hemos ampliado el alcance para incluir:

1. Implementación de una estructura de datos de grafo eficiente.
2. Carga de datos de los establecimientos D1.
3. Ejecución del algoritmo de Dijkstra para encontrar las rutas más cortas.
4. Medición precisa del tiempo de ejecución del algoritmo.

## Compilación y Ejecución

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


