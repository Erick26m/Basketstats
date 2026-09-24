# Proyecto: BasketStats

BasketStats es un programa para organizar y consultar información de jugadores de básquetbol. El sistema trabaja con una colección de jugadores que contiene datos como nombre, equipo, posición, edad, puntos, asistencias y rebotes por partido.

El problema que busca resolver es facilitar la organización y consulta de una cantidad grande de jugadores y sus estadísticas. El usuario podrá visualizar la información, agregar jugadores, ordenarlos utilizando diferentes estadísticas y buscar jugadores específicos.

El proyecto utilizará estructuras de datos y algoritmos de ordenamiento para manejar la información de forma organizada y eficiente.

## Descripción del avance 1

En este primer avance se desarrolla la estructura inicial de BasketStats.

Cada jugador es representado mediante un objeto de la clase `Jugador`, que contiene los siguientes atributos:

- Nombre.
- Equipo.
- Posición.
- Edad.
- Puntos por partido.
- Asistencias por partido.
- Rebotes por partido.

Los jugadores se almacenan en una estructura que permite administrar todos los registros cargados en el programa.

En este avance se implementan las siguientes funcionalidades:

- Leer los jugadores desde un archivo de entrada.
- Almacenar los jugadores dentro del programa.
- Mostrar todos los jugadores registrados.
- Agregar un nuevo jugador.
- Ordenar jugadores por nombre.
- Ordenar jugadores por puntos.
- Ordenar jugadores por asistencias.
- Ordenar jugadores por rebotes.
- Buscar un jugador por nombre.

Para realizar los ordenamientos se utiliza el algoritmo Merge Sort, permitiendo utilizar diferentes atributos de los jugadores como criterio de comparación.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance`

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`./primer_avance`

## Descripción de las entradas del avance de proyecto

El programa utiliza un archivo llamado `jugadores.txt` para cargar inicialmente la información de los jugadores de básquetbol.

Cada línea del archivo representa un jugador y los atributos se encuentran separados por comas.

El formato utilizado es:

`nombre,equipo,posicion,edad,puntos,asistencias,rebotes`

Ejemplo:

```text
Stephen Curry,Warriors,Base,38,26.4,5.1,4.5
Luka Doncic,Lakers,Base,27,28.3,8.2,8.1
Nikola Jokic,Nuggets,Centro,31,27.1,9.0,12.4
Jayson Tatum,Celtics,Alero,28,26.8,4.9,8.3
Giannis Antetokounmpo,Bucks,Ala-Pivot,31,30.2,6.3,11.5
