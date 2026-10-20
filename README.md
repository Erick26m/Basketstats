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
- Mensaje de error si el usuario selecciona una opción no válida.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

En mi proyecto utilizo Merge Sort para ordenar a los jugadores por nombre, puntos, asistencias o rebotes.

La función `comparar()` solamente compara dos jugadores dependiendo del criterio que se esté usando. Como solamente se revisa uno de los atributos de los jugadores, esta operación se considera `O(1)`.

La función `merge()` se encarga de unir dos partes que ya están ordenadas. Para hacerlo recorre los elementos de esas dos partes y los acomoda en un vector auxiliar. Por esta razón su complejidad es `O(n)`.

La función `mergeSort()` divide la lista de jugadores en dos mitades de manera recursiva hasta llegar a grupos de un solo elemento. Esta división genera aproximadamente `log n` niveles.

Como en cada nivel se recorren en total los `n` elementos para volverlos a juntar, la complejidad final es:

`O(n log n)`

Esto se mantiene en los tres casos:

- Mejor caso: `O(n log n)`
- Caso promedio: `O(n log n)`
- Peor caso: `O(n log n)`

Aunque los jugadores ya estén ordenados, Merge Sort sigue realizando las divisiones y después vuelve a unir los elementos, por lo que el mejor caso también sigue siendo `O(n log n)`.

En BasketStats esta lógica se encuentra principalmente en las funciones `merge()`, `mergeSort()`, `comparar()` y `ordenar()` de la clase `ListaJugadores`.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

En BasketStats utilizo principalmente dos estructuras de datos: un `vector` y un Árbol Binario de Búsqueda.

El `vector` se utiliza para almacenar a los jugadores y poder recorrerlos y ordenarlos.

El acceso a una posición específica del vector tiene una complejidad de `O(1)`, ya que se puede acceder directamente utilizando un índice.

Para mostrar todos los jugadores es necesario recorrer el vector completo, por lo que la complejidad de esta operación es `O(n)`.

También utilizo el vector para realizar los ordenamientos con Merge Sort, cuya complejidad es `O(n log n)`.

El Árbol Binario de Búsqueda se utiliza principalmente para insertar y buscar jugadores utilizando su nombre.

En un árbol razonablemente balanceado, la inserción y la búsqueda tienen una complejidad promedio de `O(log n)`, porque en cada comparación se puede descartar una parte del árbol.

Sin embargo, como el árbol no se balancea automáticamente, en el peor caso podría quedar parecido a una lista y tanto la inserción como la búsqueda podrían llegar a `O(n)`.

Por lo tanto:

- Acceso a una posición del vector: `O(1)`.
- Recorrido completo del vector: `O(n)`.
- Ordenamiento con Merge Sort: `O(n log n)`.
- Inserción en el ABB: promedio `O(log n)`, peor caso `O(n)`.
- Búsqueda en el ABB: promedio `O(log n)`, peor caso `O(n)`.

Cada estructura se utiliza para una necesidad diferente dentro del programa. El vector facilita el recorrido y ordenamiento de todos los jugadores, mientras que el ABB se utiliza para consultar jugadores por nombre.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para elegir el algoritmo de ordenamiento consideré varios de los algoritmos que vimos en clase.

Bubble Sort y Selection Sort son sencillos, pero conforme aumenta la cantidad de jugadores pueden realizar muchas comparaciones porque su complejidad puede llegar a `O(n²)`.

Insertion Sort puede funcionar bien cuando los datos ya están ordenados o casi ordenados, pero en el caso promedio y en el peor caso también puede llegar a `O(n²)`.

También consideré Quick Sort porque normalmente tiene una complejidad de `O(n log n)`, pero en su peor caso puede llegar a `O(n²)` dependiendo de cómo se dividan los datos.

Merge Sort mantiene una complejidad de `O(n log n)` en el mejor caso, en el caso promedio y en el peor caso.

Por esta razón decidí utilizar Merge Sort en BasketStats, ya que los jugadores pueden venir en cualquier orden dentro del archivo y la cantidad de datos puede aumentar.

Además, el mismo algoritmo me permite ordenar por diferentes datos del jugador. La función `comparar()` cambia la comparación dependiendo de si quiero ordenar por nombre, puntos, asistencias o rebotes.

Por estas razones decidí utilizar Merge Sort para el proyecto.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Para este avance necesitaba una estructura que me permitiera consultar jugadores específicos por nombre.

Consideré seguir utilizando solamente el `vector`, pero para buscar un jugador tendría que recorrer los elementos hasta encontrarlo, por lo que una búsqueda secuencial tendría una complejidad de `O(n)`.

También consideré una lista ligada, pero para encontrar un jugador también tendría que recorrer los nodos uno por uno, por lo que la búsqueda seguiría siendo `O(n)`.

Decidí utilizar un Árbol Binario de Búsqueda porque permite organizar los jugadores utilizando su nombre. Si el nombre es menor al nombre del nodo actual se continúa por el lado izquierdo, y si es mayor se continúa por el lado derecho.

De esta manera, en un árbol razonablemente balanceado una búsqueda tiene una complejidad promedio de `O(log n)`, aunque puede llegar a `O(n)` en el peor caso si el árbol queda desbalanceado.

No eliminé el `vector` porque sigue siendo útil para recorrer y ordenar todos los jugadores. Por eso decidí utilizar las dos estructuras para diferentes partes del programa: el vector para mostrar y ordenar, y el ABB para realizar búsquedas por nombre.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

Para consultar un jugador específico se utiliza el Árbol Binario de Búsqueda.

La búsqueda comienza desde la raíz y compara el nombre que ingresó el usuario con el nombre del jugador que se encuentra en el nodo actual.

Si los nombres son iguales, el jugador fue encontrado.

Si el nombre buscado es menor, la búsqueda continúa por el subárbol izquierdo. Si es mayor, continúa por el subárbol derecho.

De esta manera no es necesario recorrer todos los jugadores en todos los casos.

Cuando se encuentra al jugador, el programa muestra su nombre, equipo, posición, edad, puntos, asistencias y rebotes. Si no se encuentra, se muestra un mensaje indicando que el jugador no está registrado.

Este mecanismo se utiliza desde la opción de búsqueda del menú principal.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

BasketStats utiliza el archivo `jugadores.txt` para cargar la información al iniciar el programa.

El archivo se abre utilizando `ifstream`. Antes de leer los datos se verifica que el archivo se haya abierto correctamente. Si no se puede abrir, el programa muestra un mensaje de error.

Después se leen los datos de cada jugador:

`nombre equipo posicion edad puntos asistencias rebotes`

Con estos datos se crea un objeto de tipo `Jugador`.

Cada jugador leído se almacena en el `vector` y también se inserta en el Árbol Binario de Búsqueda para que pueda ser utilizado posteriormente en los ordenamientos y en las búsquedas.

Al terminar de leer la información, el archivo se cierra.

De esta manera los datos del archivo quedan cargados correctamente en las estructuras que utiliza BasketStats.
