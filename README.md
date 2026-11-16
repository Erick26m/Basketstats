# Proyecto: BasketStats

BasketStats es un programa que permite organizar y consultar información de jugadores de básquetbol. El sistema maneja datos como nombre, equipo, posición, edad, puntos, asistencias y rebotes por partido.

El objetivo del proyecto es facilitar la organización de una colección de jugadores, permitiendo visualizar su información, ordenarla utilizando diferentes estadísticas, consultar jugadores específicos, agregar nuevos jugadores y guardar los cambios realizados.

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

## Descripción del avance 3

En este tercer avance se completa el funcionamiento principal de BasketStats agregando opciones para modificar y guardar la información de los jugadores.

Se agregó la posibilidad de registrar nuevos jugadores durante la ejecución. Cada jugador nuevo se almacena tanto en el `vector` como en el Árbol Binario de Búsqueda, por lo que después puede mostrarse, ordenarse y buscarse.

También se agregó un mecanismo para guardar los cambios realizados en `jugadores.txt`, permitiendo conservar los jugadores agregados después de cerrar el programa.

Finalmente, se completa el análisis de complejidad de los demás componentes del programa para determinar el costo de sus principales operaciones.

### Cambios sobre el segundo avance

1. Se agregó la función `agregarJugador()` para registrar nuevos jugadores durante la ejecución. El jugador se almacena en el `vector` y también se inserta en el Árbol Binario de Búsqueda.

2. Se agregó la opción `Agregar jugador` al menú principal para ingresar el nombre, equipo, posición, edad, puntos, asistencias y rebotes de un nuevo jugador.

3. Se agregó la función `guardarArchivo()` para escribir en `jugadores.txt` los jugadores almacenados actualmente en el `vector`. Esto permite conservar los cambios realizados durante la ejecución.

4. Se agregó la opción `Guardar cambios` al menú principal para que el usuario pueda guardar la información actualizada.

5. Se agregaron los getters necesarios en la clase `Jugador` para obtener el equipo, posición y edad al momento de escribir nuevamente los datos en el archivo.

6. Se completó el análisis de complejidad de los demás componentes del programa y se determinó la complejidad general considerando las operaciones utilizadas.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o tercer_avance`

## Instrucciones para ejecutar el avance de proyecto

En Windows:

`tercer_avance.exe`

En Linux o macOS:

`./tercer_avance`

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

El programa también recibe información desde el menú. Para agregar un jugador se solicita:

- Nombre.
- Equipo.
- Posición.
- Edad.
- Puntos por partido.
- Asistencias por partido.
- Rebotes por partido.

## Descripción de las salidas del avance de proyecto

El programa muestra un menú desde el cual el usuario puede consultar, ordenar, agregar y guardar información de los jugadores.

El menú principal es:

```text
BASKETSTATS

1. Mostrar jugadores
2. Ordenar por nombre
3. Ordenar por puntos
4. Ordenar por asistencias
5. Ordenar por rebotes
6. Buscar jugador por nombre
7. Agregar jugador
8. Guardar cambios
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
- Mensaje indicando cuando un jugador fue agregado.
- Mensaje indicando cuando los cambios fueron guardados correctamente.
- Mensaje de error si el usuario selecciona una opción no válida.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Después de la retroalimentación del primer avance entendí que no era suficiente mencionar solamente la complejidad final de Merge Sort, sino que debía explicar cómo se obtiene.

La función `merge()` recorre los elementos de las dos partes que se están uniendo, por lo que tiene una complejidad de `O(n)`. Por otro lado, `mergeSort()` divide los datos a la mitad de forma recursiva, generando aproximadamente `log n` niveles. Como en cada nivel se procesan los `n` elementos, la complejidad final es `O(n log n)`.

Merge Sort mantiene una complejidad de `O(n log n)` en el mejor, promedio y peor caso, ya que aunque los datos estén ordenados sigue realizando las divisiones y uniones.

Considero que desarrollé este criterio porque puedo explicar de dónde sale la complejidad del algoritmo y no solamente mencionar el resultado. Esto se puede observar en las funciones `merge()`, `mergeSort()` y `ordenar()` de `ListaJugadores`.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

En BasketStats utilizo un `vector` y un Árbol Binario de Búsqueda.

El `vector` se utiliza para almacenar, mostrar y ordenar a los jugadores. Como el vector se crea con espacio para 100 jugadores, almacenar un jugador en una posición conocida utilizando `jugadores[cantidad]` tiene una complejidad de `O(1)` en el mejor caso, caso promedio y peor caso.

Acceder a un jugador mediante una posición del vector también tiene una complejidad de `O(1)` en el mejor, promedio y peor caso, ya que se accede directamente utilizando el índice.

Para mostrar a todos los jugadores es necesario recorrer los elementos almacenados en el vector, por lo que esta operación tiene una complejidad de `O(n)` en el mejor, promedio y peor caso.

El Árbol Binario de Búsqueda se utiliza para insertar y buscar jugadores utilizando su nombre.

Para la operación `insertar()`, el mejor caso es `O(1)` cuando el árbol está vacío o cuando después de comparar con la raíz el jugador puede insertarse directamente como uno de sus hijos. El caso promedio es `O(log n)` cuando el árbol está razonablemente balanceado. El peor caso es `O(n)` cuando el árbol queda desbalanceado y es necesario recorrer varios nodos hasta encontrar dónde insertar al jugador.

Para la operación `buscar()`, el mejor caso es `O(1)` cuando el jugador buscado se encuentra en la raíz. El caso promedio es `O(log n)` cuando el árbol está razonablemente balanceado y el peor caso es `O(n)` cuando el árbol se encuentra desbalanceado.

Considero que desarrollé este criterio porque puedo analizar las operaciones que realmente utilizo de cada estructura de datos e identificar su mejor caso, caso promedio y peor caso dentro de BasketStats.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Después de analizar por separado Merge Sort, el `vector` y el Árbol Binario de Búsqueda, analicé cómo se combinan estas operaciones dentro de las funciones principales de BasketStats.

La función `cargarArchivo()` lee los `n` jugadores de `jugadores.txt`. Cada jugador se guarda en una posición del `vector` y también se inserta en el ABB. Debido a las inserciones en el árbol, la carga completa tiene una complejidad de `O(n log n)` en el mejor caso y caso promedio cuando el árbol se mantiene balanceado. En el peor caso puede llegar a `O(n²)` si el árbol queda completamente desbalanceado.

La función `mostrarJugadores()` recorre los jugadores almacenados, por lo que tiene una complejidad de `O(n)` en el mejor caso, caso promedio y peor caso.

La función `ordenar()` utiliza el algoritmo Merge Sort analizado anteriormente, por lo que tiene una complejidad de `O(n log n)`.

La función `buscarJugador()` utiliza la operación de búsqueda del ABB, por lo que su mejor caso es `O(1)`, su caso promedio es `O(log n)` y su peor caso es `O(n)`.

La función `agregarJugador()` almacena directamente el jugador en el `vector` y después utiliza la operación `insertar()` del ABB. Por esta razón, su mejor caso es `O(1)`, su caso promedio es `O(log n)` y su peor caso es `O(n)`.

La función `guardarArchivo()` recorre todos los jugadores para escribirlos en `jugadores.txt`, por lo que tiene una complejidad de `O(n)` en el mejor caso, caso promedio y peor caso.

La complejidad total de una sesión depende de cuántas veces el usuario utilice cada opción. Sin embargo, considerando las operaciones principales del programa, la carga inicial normalmente trabaja en `O(n log n)` y puede llegar a `O(n²)` en el peor caso debido a la construcción de un ABB completamente desbalanceado.

Por esta razón, el peor caso dominante de BasketStats puede llegar a ser `O(n²)`.

Considero que desarrollé este criterio porque puedo utilizar los análisis realizados anteriormente para determinar el costo de las funciones completas del programa y explicar su complejidad general.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Después de la retroalimentación del primer avance entendí que debía comparar diferentes opciones antes de justificar la elección del algoritmo.

Consideré Bubble Sort y Selection Sort, que pueden tener una complejidad de `O(n²)`. También Insertion Sort, que puede ser `O(n)` cuando los datos ya están ordenados, pero en promedio y en el peor caso llega a `O(n²)`. Quick Sort normalmente trabaja en `O(n log n)`, pero su peor caso puede llegar a `O(n²)`.

Decidí utilizar Merge Sort porque mantiene `O(n log n)` en el mejor, promedio y peor caso. Además, puedo utilizar el mismo algoritmo para ordenar jugadores por nombre, puntos, asistencias o rebotes.

Considero que desarrollé este criterio porque comparé distintas alternativas antes de elegir el algoritmo que utilizo en BasketStats.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Para buscar jugadores consideré utilizar solamente el `vector`, pero una búsqueda secuencial puede llegar a `O(n)`. Una lista ligada también necesitaría recorrer sus nodos uno por uno.

Decidí utilizar un Árbol Binario de Búsqueda porque permite organizar los jugadores por nombre y realizar búsquedas con una complejidad promedio de `O(log n)`, aunque puede llegar a `O(n)` si el árbol queda desbalanceado.

También mantuve el `vector` porque sigue siendo útil para mostrar y ordenar jugadores. Considero que desarrollé este criterio porque seleccioné cada estructura dependiendo de lo que necesito realizar: el vector para recorridos y ordenamientos, y el ABB para búsquedas.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

Para consultar un jugador utilizo el Árbol Binario de Búsqueda. La búsqueda comienza desde la raíz y compara el nombre buscado con el nombre del jugador almacenado en el nodo actual.

Si los nombres son iguales, significa que el jugador fue encontrado. Si el nombre buscado es menor se continúa por el lado izquierdo y si es mayor se continúa por el lado derecho. Si se llega a un nodo vacío, significa que el jugador no se encuentra registrado.

Considero que desarrollé este criterio porque implementé una forma de consultar la información utilizando directamente la estructura del ABB, en lugar de recorrer todos los jugadores uno por uno.

Esta consulta se puede observar en la función `buscar()` del árbol y en la opción de búsqueda por nombre del menú principal.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

BasketStats utiliza el archivo `jugadores.txt` para cargar los datos al iniciar el programa. El archivo se abre utilizando `ifstream` y se verifica que se haya abierto correctamente antes de comenzar la lectura.

Cada jugador se lee utilizando el formato:

`nombre equipo posicion edad puntos asistencias rebotes`

Con estos datos se crea un objeto `Jugador`, que se almacena en el `vector` y también se inserta en el Árbol Binario de Búsqueda.

Al terminar de leer la información, el archivo se cierra.

Considero que desarrollé este criterio porque el programa puede leer correctamente la información desde un archivo externo y utilizar esos datos para llenar las estructuras que necesita BasketStats.

#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.

BasketStats utiliza la función `guardarArchivo()` para guardar los datos actuales de los jugadores en `jugadores.txt`.

La función abre el archivo utilizando `ofstream` y verifica que se haya abierto correctamente. Después recorre los jugadores almacenados en el `vector` y escribe el nombre, equipo, posición, edad, puntos, asistencias y rebotes de cada uno.

Al terminar de escribir todos los jugadores, el archivo se cierra utilizando `close()`.

Esta función permite que los jugadores agregados durante la ejecución no se pierdan al cerrar el programa, ya que al seleccionar la opción `Guardar cambios` la información actual queda almacenada en `jugadores.txt`.

Considero que desarrollé este criterio porque BasketStats puede cargar información desde un archivo y también guardar nuevamente los datos modificados durante la ejecución.

### SEG0701: Cultura digital

#### El producto entregado genera valor para un usuario final y se ejecuta sin errores.

BasketStats permite organizar información de jugadores de básquetbol desde un solo programa. El usuario puede cargar jugadores desde un archivo, consultar su información, ordenar los datos por diferentes estadísticas, buscar jugadores por nombre, agregar jugadores nuevos y guardar los cambios realizados.

Las opciones se presentan mediante un menú sencillo y cada una realiza una función específica dentro del programa.

Considero que BasketStats genera valor para un usuario final porque permite organizar y consultar la información de los jugadores sin tener que modificar directamente el archivo de texto.

#### Cumple con las pautas éticas institucionales y no utiliza IA para sustituir el proceso de aprendizaje.

Durante todo el curso estuve en cada parte del proyecto trabajando con los algoritmos y estructuras vistos durante el curso y fui revisando el funcionamiento de cada parte del programa.

Las herramientas de apoyo utilizadas durante el desarrollo sirvieron para revisar, organizar y comprender mejor el proyecto, sin sustituir mi aprendizaje de los temas trabajados durante el curso.
