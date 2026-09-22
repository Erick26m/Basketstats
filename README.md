# Proyecto: BasketStats

BasketStats es un programa que permite organizar y consultar información de jugadores de básquetbol. El sistema almacena datos como el nombre del jugador, equipo, posición, edad, puntos, asistencias y rebotes por partido.

El objetivo del proyecto es facilitar la consulta y organización de los jugadores mediante diferentes opciones, como mostrar todos los jugadores, agregar nuevos registros, ordenar la información de acuerdo con diferentes estadísticas y buscar jugadores por su nombre.

## Descripción del avance 1

En este primer avance se implementa la estructura principal del programa para administrar una base de datos de jugadores de básquetbol.

El programa utiliza una clase `Jugador` para almacenar la información de cada jugador y una estructura que permite guardar varios jugadores dentro del sistema.

Los datos de los jugadores se cargan desde un archivo de texto y posteriormente pueden ser consultados desde un menú.

En este avance se incluyen las siguientes funcionalidades:

- Cargar jugadores desde un archivo de texto.
- Mostrar todos los jugadores registrados.
- Agregar nuevos jugadores.
- Ordenar los jugadores por nombre.
- Ordenar los jugadores por puntos por partido.
- Ordenar los jugadores por asistencias por partido.
- Ordenar los jugadores por rebotes por partido.
- Buscar un jugador por nombre.

Para realizar los ordenamientos se utiliza el algoritmo Merge Sort, permitiendo organizar los jugadores utilizando diferentes atributos.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance`

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`./primer_avance`

## Descripción de las entradas del avance de proyecto

El programa utiliza un archivo de texto llamado `jugadores.txt`, el cual contiene la información de los jugadores de básquetbol.

Cada línea representa un jugador y sus datos se encuentran separados por comas.

El formato del archivo es el siguiente:

`nombre,equipo,posicion,edad,puntos,asistencias,rebotes`

Ejemplo:

```text
Stephen Curry,Warriors,Base,38,26.4,5.1,4.5
Luka Doncic,Lakers,Base,27,28.3,8.2,8.1
Nikola Jokic,Nuggets,Centro,31,27.1,9.0,12.4
Jayson Tatum,Celtics,Alero,28,26.8,4.9,8.3
Giannis Antetokounmpo,Heat,Ala-Pivot,31,30.2,6.3,11.5
