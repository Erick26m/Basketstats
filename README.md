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

En mi proyecto utilizo Merge Sort para ordenar a los jugadores por nombre, puntos, asistencias o rebotes.

La función `comparar()` solamente compara dos jugadores dependiendo del criterio que se esté usando.

Después está la función `merge()`, que se encarga de unir dos partes que ya están ordenadas. Para hacerlo tiene que recorrer los elementos de esas dos partes y acomodarlos en el vector auxiliar. Por eso su complejidad es `O(n)`.

La función `mergeSort()` divide la lista de jugadores en dos mitades de manera recursiva hasta llegar a grupos de un solo elemento. Esta división genera aproximadamente `log n` niveles.

Como en cada nivel se recorren en total los `n` elementos para volverlos a juntar, la complejidad final del algoritmo es:

`O(n log n)`

Esto se mantiene en los tres casos:

- Mejor caso: `O(n log n)`
- Caso promedio: `O(n log n)`
- Peor caso: `O(n log n)`

Aunque los jugadores ya estuvieran ordenados, Merge Sort sigue haciendo las divisiones y después vuelve a unir los elementos, por eso el mejor caso también sigue siendo `O(n log n)`.

En BasketStats esta lógica se encuentra principalmente en las funciones `merge()`, `mergeSort()`, `comparar()` y `ordenar()` del archivo `ListaJugadores.h`.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para elegir el algoritmo de ordenamiento consideré los algoritmos que vimos en clase: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort y Quick Sort.

Bubble Sort y Selection Sort son fáciles de entender, pero cuando aumenta la cantidad de datos pueden llegar a realizar muchas comparaciones porque su complejidad es `O(n²)`.

Insertion Sort puede funcionar bien cuando los datos ya están casi ordenados, pero en el caso promedio y en el peor caso también puede llegar a `O(n²)`.

También consideré Quick Sort porque normalmente tiene una complejidad de `O(n log n)`, pero en su peor caso puede llegar a `O(n²)` dependiendo de cómo se seleccione el pivote y de cómo estén acomodados los datos.

Al final elegí Merge Sort porque mantiene una complejidad de `O(n log n)` en el mejor, promedio y peor caso. Esto me pareció conveniente para BasketStats porque la cantidad de jugadores puede aumentar y los datos no necesariamente van a estar ordenados desde el inicio.

Además, puedo utilizar el mismo Merge Sort para ordenar por diferentes datos del jugador. La función `comparar()` cambia la comparación dependiendo de si quiero ordenar por nombre, puntos, asistencias o rebotes.

Por estas razones decidí utilizar Merge Sort para el proyecto.
