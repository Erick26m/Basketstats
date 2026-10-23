# Proyecto: BasketStats

BasketStats es un programa que permite organizar y consultar información de jugadores de básquetbol. El sistema maneja datos como nombre, equipo, posición, edad, puntos, asistencias y rebotes por partido.

El objetivo del proyecto es facilitar la organización de una colección de jugadores, permitiendo visualizar su información, ordenarla utilizando diferentes estadísticas y consultar jugadores específicos.

## Descripción del avance 1

En este primer avance implementé la estructura inicial de BasketStats para organizar información de jugadores de básquetbol.

Se implementó lo siguiente:

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

## Descripción del avance 2

En este segundo avance se mantiene el funcionamiento del primer avance y se agrega un Árbol Binario de Búsqueda para poder consultar jugadores de una forma diferente.

El `vector` se sigue utilizando para almacenar, mostrar y ordenar a los jugadores con Merge Sort.

Además, los jugadores se almacenan en un Árbol Binario de Búsqueda utilizando el nombre del jugador como criterio. Esto permite buscar un jugador específico comparando su nombre con los nombres almacenados en el árbol.

En este avance se implementa:

- Uso del `vector` para almacenar y ordenar jugadores.
- Implementación de un Árbol Binario de Búsqueda.
- Inserción de los jugadores en el árbol.
- Búsqueda de jugadores por nombre.
- Visualización de la información del jugador encontrado.
- Lectura de los jugadores desde el archivo `jugadores.txt` y almacenamiento en las estructuras correspondientes.

### Cambios sobre el primer avance

1. Se agregó un Árbol Binario de Búsqueda para consultar jugadores por nombre. En el primer avance el programa estaba enfocado principalmente en ordenar los datos, por lo que ahora se agregó una estructura que también permite realizar búsquedas.

2. Se agregó una opción para buscar jugadores por nombre desde el menú. El nombre se utiliza como criterio dentro del árbol, de manera similar a como se comparan números en un ABB.

3. Se decidió mantener el `vector` del primer avance porque sigue siendo útil para recorrer, mostrar y ordenar todos los jugadores utilizando Merge Sort. El árbol se utiliza principalmente para las búsquedas.

4. También se corrigió la documentación del primer avance tomando en cuenta la retroalimentación recibida, agregando un análisis de complejidad más completo y una comparación entre diferentes algoritmos antes de justificar la elección de Merge Sort.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o segundo_avance`

## Instrucciones para ejecutar el avance de proyecto

En Windows:

`segundo_avance.exe`


## Descripción de las entradas del avance de proyecto

El programa utiliza un archivo de texto llamado `jugadores.txt` para cargar la información de los jugadores de básquetbol.

El formato utilizado es:

`nombre equipo posicion edad puntos asistencias rebotes`

Ejemplo:

```text
Stephen_Curry Warriors Base 38 26.4 5.1 4.5
Luka_Doncic Lakers Base 27 28.3 8.2 8.1
Nikola_Jokic Nuggets Centro 31 27.1 9.0 12.4
Jayson_Tatum Celtics Alero 28 26.8 4.9 8.3
Giannis_Antetokounmpo Bucks Ala-Pivot 31 30.2 6.3 11.5
```

Los nombres que contienen espacios se escriben utilizando guion bajo, por ejemplo:

`Stephen_Curry`

Al leer el archivo, la información de los jugadores se almacena en el `vector` y también se utiliza para construir el Árbol Binario de Búsqueda.

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
6. Buscar jugador por nombre
7.Guardar jugadores en archivo
0. Salir
```

Las principales salidas del programa son:

- Lista completa de jugadores y sus estadísticas.
- Lista de jugadores ordenada alfabéticamente por nombre.
- Lista de jugadores ordenada de mayor a menor por puntos.
- Lista de jugadores ordenada de mayor a menor por asistencias.
- Lista de jugadores ordenada de mayor a menor por rebotes.
- Información de un jugador encontrado mediante el Árbol Binario de Búsqueda.
- Mensaje indicando cuando un jugador no se encuentra.
- Creación del archivo `jugadores_guardados.txt` con la información de los jugadores.
- Mensaje de error si el usuario selecciona una opción no válida.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Después de la retroalimentación del primer avance entendí que no era suficiente mencionar solamente la complejidad final de Merge Sort, sino que debía explicar cómo se obtiene.

La función `merge()` recorre los elementos de las dos partes que se están uniendo, por lo que tiene una complejidad de `O(n)`. Por otro lado, `mergeSort()` divide los datos a la mitad de forma recursiva, generando aproximadamente `log n` niveles. Como en cada nivel se procesan los `n` elementos, la complejidad final es `O(n log n)`.

Merge Sort mantiene una complejidad de `O(n log n)` en el mejor, promedio y peor caso, ya que aunque los datos estén ordenados sigue realizando las divisiones y uniones.

Considero que ahora sí desarrollé este criterio porque puedo explicar de dónde sale la complejidad del algoritmo y no solamente mencionar el resultado. Esto se puede observar en las funciones `merge()`, `mergeSort()` y `ordenar()` de `ListaJugadores`.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

En BasketStats utilizo un `vector` y un Árbol Binario de Búsqueda.

El `vector` se utiliza para almacenar, mostrar, ordenar y guardar jugadores. Acceder a una posición mediante su índice es `O(1)`, mientras que recorrer todos sus elementos es `O(n)`. Al ordenar el vector con Merge Sort la complejidad es `O(n log n)`.

El ABB se utiliza para insertar y buscar jugadores por nombre. En un árbol razonablemente balanceado, una inserción o búsqueda tiene una complejidad promedio de `O(log n)`. En el peor caso, si el árbol queda desbalanceado, estas operaciones pueden llegar a `O(n)`.

Al cargar todos los jugadores al árbol se realizan `n` inserciones, por lo que el proceso completo tiene una complejidad promedio de `O(n log n)` y puede llegar a `O(n²)` en el peor caso si el árbol queda completamente desbalanceado.

Considero que desarrollé este criterio porque puedo identificar la complejidad de las operaciones realizadas con cada estructura y explicar para qué se utiliza cada una dentro del programa.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Además de las estructuras y el algoritmo de ordenamiento, también analicé las demás funciones principales de BasketStats.

La función `mostrarJugadores()` recorre todos los jugadores almacenados, por lo que tiene una complejidad de `O(n)`. La función `guardarArchivo()` también recorre el vector completo para escribir cada jugador en el archivo, por lo que su complejidad es `O(n)`.

La búsqueda de un jugador en el ABB tiene una complejidad promedio de `O(log n)` y puede llegar a `O(n)` en el peor caso.

El ordenamiento mediante Merge Sort tiene una complejidad de `O(n log n)`. La carga inicial de los jugadores, considerando también su inserción en el ABB, tiene una complejidad promedio de `O(n log n)` y un peor caso de `O(n²)`.

Por lo tanto, las operaciones principales del programa normalmente se mantienen en `O(n log n)`, aunque en el peor caso la construcción del ABB puede llegar a `O(n²)`.

Considero que desarrollé este criterio porque puedo analizar las funciones principales del programa y determinar cómo afectan a su complejidad general.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Después de la retroalimentación del primer avance entendí que debía comparar diferentes opciones antes de justificar la elección del algoritmo.

Consideré Bubble Sort y Selection Sort, que pueden tener una complejidad de `O(n²)`. También Insertion Sort, que puede ser `O(n)` cuando los datos ya están ordenados, pero en promedio y en el peor caso llega a `O(n²)`. Quick Sort normalmente trabaja en `O(n log n)`, pero su peor caso puede llegar a `O(n²)`.

Decidí utilizar Merge Sort porque mantiene `O(n log n)` en el mejor, promedio y peor caso. Además, puedo utilizar el mismo algoritmo para ordenar jugadores por nombre, puntos, asistencias o rebotes.

Considero que ahora sí desarrollé este criterio porque comparé distintas alternativas antes de elegir el algoritmo que utilizo en BasketStats.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Para buscar jugadores consideré utilizar solamente el `vector`, pero una búsqueda secuencial puede llegar a `O(n)`. Una lista ligada también necesitaría recorrer sus nodos uno por uno.

Decidí utilizar un Árbol Binario de Búsqueda porque permite organizar los jugadores por nombre y realizar búsquedas con una complejidad promedio de `O(log n)`, aunque puede llegar a `O(n)` si el árbol queda desbalanceado.

También mantuve el `vector` porque sigue siendo útil para mostrar, ordenar y guardar jugadores. Considero que desarrollé este criterio porque seleccioné cada estructura dependiendo de lo que necesito realizar: el vector para recorridos, ordenamientos y escritura de archivos, y el ABB para búsquedas.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

Para consultar un jugador utilizo el Árbol Binario de Búsqueda. La búsqueda comienza desde la raíz y compara el nombre buscado con el nombre del nodo actual.

Si los nombres son iguales se encontró al jugador. Si el nombre buscado es menor se continúa por la izquierda y si es mayor se continúa por la derecha. Si se llega a un nodo vacío, significa que el jugador no se encuentra registrado.

Considero que desarrollé este criterio porque implementé una forma de consultar la información utilizando directamente la estructura del ABB.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

BasketStats utiliza el archivo `jugadores.txt` para cargar los datos al iniciar el programa. El archivo se abre utilizando `ifstream` y se verifica que se haya abierto correctamente antes de leerlo.

Cada jugador se lee utilizando el formato:

`nombre equipo posicion edad puntos asistencias rebotes`

Con esos datos se crea un objeto `Jugador`, que se almacena en el `vector` y se inserta en el Árbol Binario de Búsqueda.

Considero que desarrollé este criterio porque el programa puede leer los datos desde un archivo externo y cargarlos correctamente en las estructuras utilizadas por BasketStats.

#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.

BasketStats implementa la función `guardarArchivo()`, que utiliza `ofstream` para guardar la información de los jugadores en el archivo `jugadores_guardados.txt`.

La función recorre los jugadores almacenados en el `vector` y escribe el nombre, equipo, posición, edad, puntos, asistencias y rebotes de cada jugador.

Antes de escribir se verifica que el archivo se haya abierto correctamente y al terminar se cierra utilizando `close()`.

Considero que desarrollé este criterio porque el programa no solamente puede cargar información desde un archivo, sino que también puede guardar nuevamente los datos almacenados durante la ejecución.
