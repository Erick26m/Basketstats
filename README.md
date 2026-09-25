# Proyecto: BasketStats

BasketStats es un programa que permite organizar y consultar información de jugadores de básquetbol. El sistema maneja datos como nombre, equipo, posición, edad, puntos, asistencias y rebotes por partido.

El objetivo del proyecto es facilitar la organización de una colección de jugadores, permitiendo visualizar su información y ordenarla utilizando diferentes estadísticas.

## Descripción del avance 1

En este primer avance implemente la estructura inicial de BasketStats para organizar información de jugadores de básquetbol.

Se implementa lo siguiente:

- Clase `Jugador` para almacenar la información de cada jugador.
- Clase `ListaJugadores` para administrar la colección de jugadores.
- Lectura de jugadores desde un archivo de texto.
- Almacenamiento de los jugadores utilizando un `vector`.
- Visualización de los jugadores registrados.
- Ordenamiento de jugadores por nombre.
- Ordenamiento de jugadores por puntos.
- Ordenamiento de jugadores por asistencias.
- Ordenamiento de jugadores por rebotes.

Para realizar los ordenamientos se utiliza el algoritmo Merge Sort, permitiendo organizar la información utilizando diferentes atributos de los jugadores.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance`

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`./primer_avance`

## Descripción de las entradas del avance de proyecto

El programa utiliza un archivo de texto llamado `jugadores.txt` para cargar la información de los jugadores de básquetbol.

El formato utilizado es:

`nombre equipo posicion edad puntos asistencias rebotes`

Ejemplo:

```text
Stephen_Curry Warriors Base 38 26.4 5.1 4.5
Luka_Doncic Lakers Base 27 28.3 8.2 8.1
```

Los nombres que contienen espacios se escriben utilizando guion bajo, por ejemplo:

`Stephen_Curry`

La información del archivo se almacena dentro de un `vector` de objetos de tipo `Jugador`.

## Descripción de las salidas del avance de proyecto

El programa muestra un menú desde el cual el usuario puede consultar y ordenar la información de los jugadores.

El menú principal es:

```text
BASKETSTATS
1. Mostrar jugadores
2. Ordenar por nombre
3. Ordenar por puntos
4. Ordenar por asistencias
5. Ordenar por rebotes
0. Salir
```

Las principales salidas del programa son:

- Lista completa de jugadores y sus estadísticas.
- Lista de jugadores ordenada alfabéticamente por nombre.
- Lista de jugadores ordenada de mayor a menor por puntos.
- Lista de jugadores ordenada de mayor a menor por asistencias.
- Lista de jugadores ordenada de mayor a menor por rebotes.
- Mensaje de error en caso de que no se pueda abrir el archivo de entrada.
- Mensaje de error si el usuario selecciona una opción no válida.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

En BasketStats se utiliza el algoritmo Merge Sort para ordenar la información de los jugadores utilizando diferentes atributos como nombre, puntos, asistencias y rebotes.

En el proyecto, la función `mergeSort()` realiza la división recursiva del conjunto de jugadores, mientras que la función `merge()` se encarga de combinar nuevamente los elementos en el orden correspondiente.

Esta implementación se encuentra en el archivo `ListaJugadores.h`.

También se utilizan las siguientes funciones para aplicar el ordenamiento dependiendo del atributo seleccionado:

- `ordenarPorNombre()`
- `ordenarPorPuntos()`
- `ordenarPorAsistencias()`
- `ordenarPorRebotes()`

Todas estas funciones utilizan Merge Sort, por lo que conservan una complejidad temporal de `O(n log n)`.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para BasketStats se seleccionó Merge Sort como algoritmo de ordenamiento porque el programa trabaja con una colección de jugadores que puede organizarse utilizando diferentes estadísticas.

Merge Sort tiene una complejidad de `O(n log n)` en el mejor, promedio y peor caso. Esto permite que el algoritmo mantenga un comportamiento constante aunque aumente la cantidad de jugadores.

Otra ventaja es que el mismo algoritmo puede ser utilizado para ordenar diferentes atributos de los objetos. En BasketStats se utiliza para ordenar por nombre, puntos, asistencias y rebotes.

Para determinar el criterio de ordenamiento se utiliza la función `vaAntes()`, que compara dos jugadores dependiendo del atributo seleccionado.

La implementación de Merge Sort y los diferentes criterios de ordenamiento se encuentran en el archivo `ListaJugadores.h`.

