# Proyecto: BasketStats

BasketStats es un programa que permite organizar y consultar información de jugadores de básquetbol. El sistema maneja datos como nombre, equipo, posición, edad, puntos, asistencias y rebotes por partido.

El objetivo del proyecto es facilitar la organización y consulta de una colección de jugadores, permitiendo visualizar su información, agregar nuevos registros, ordenar a los jugadores utilizando diferentes estadísticas y buscar jugadores específicos por su nombre.

## Descripción del avance 1

En este primer avance se implementa la estructura inicial de BasketStats para administrar la información de los jugadores de básquetbol.

Se implementa lo siguiente:

- Clase `Jugador` para almacenar la información de cada jugador.
- Clase `ListaJugadores` para administrar la colección de jugadores.
- Lectura de jugadores desde un archivo de texto.
- Almacenamiento de los jugadores utilizando un vector.
- Visualización de los jugadores registrados.
- Funcionalidad para agregar nuevos jugadores.
- Ordenamiento de jugadores por nombre, puntos, asistencias y rebotes.
- Búsqueda binaria para encontrar un jugador por su nombre.

Para realizar los ordenamientos se utiliza el algoritmo Merge Sort, permitiendo organizar la información de los jugadores utilizando diferentes atributos.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance`

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`./primer_avance`

## Descripción de las entradas del avance de proyecto

El programa utiliza un archivo de texto llamado `jugadores.txt` para cargar inicialmente la información de los jugadores de básquetbol.

Cada línea del archivo contiene los datos de un jugador separados por comas.

El formato es el siguiente:

`nombre,equipo,posicion,edad,puntos,asistencias,rebotes`

Ejemplo de datos de entrada:

~~~text
Stephen Curry,Warriors,Base,38,26.4,5.1,4.5
Luka Doncic,Lakers,Base,27,28.3,8.2,8.1
Nikola Jokic,Nuggets,Centro,31,27.1,9.0,12.4
Jayson Tatum,Celtics,Alero,28,26.8,4.9,8.3
Giannis Antetokounmpo,Bucks,Ala-Pivot,31,30.2,6.3,11.5
~~~

Los campos representan:

- `nombre`: nombre del jugador.
- `equipo`: equipo al que pertenece.
- `posicion`: posición en la que juega.
- `edad`: edad del jugador.
- `puntos`: promedio de puntos por partido.
- `asistencias`: promedio de asistencias por partido.
- `rebotes`: promedio de rebotes por partido.

Además de los datos cargados desde el archivo, el usuario puede ingresar la información de un nuevo jugador desde el menú del programa.

## Descripción de las salidas del avance de proyecto

El programa muestra un menú desde el cual el usuario puede realizar diferentes operaciones con los jugadores registrados.

Las principales salidas son:

- Lista completa de jugadores y sus estadísticas.
- Lista de jugadores ordenada alfabéticamente por nombre.
- Lista de jugadores ordenada por puntos.
- Lista de jugadores ordenada por asistencias.
- Lista de jugadores ordenada por rebotes.
- Información de un jugador después de realizar una búsqueda por nombre.
- Mensaje de confirmación cuando se agrega un nuevo jugador.
- Mensaje indicando cuando un jugador no fue encontrado.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

En BasketStats se utiliza el algoritmo Merge Sort para ordenar la información de los jugadores utilizando diferentes atributos como nombre, puntos, asistencias y rebotes.

Merge Sort funciona dividiendo la colección de jugadores en partes cada vez más pequeñas hasta llegar a elementos individuales. Después, estas partes se combinan nuevamente mientras se comparan los atributos seleccionados.

La complejidad temporal del algoritmo es:

- Mejor caso: `O(n log n)`
- Caso promedio: `O(n log n)`
- Peor caso: `O(n log n)`

Esto se debe a que el algoritmo divide los datos aproximadamente `log n` veces y en cada nivel procesa los `n` elementos.

En BasketStats esta implementación permite utilizar el mismo algoritmo de ordenamiento para diferentes estadísticas de los jugadores.

**Evidencia en el código:**

Esta implementación se puede observar en las funciones de Merge Sort utilizadas para ordenar el vector de jugadores.

> Al terminar el código se agregarán aquí los nombres exactos de las funciones, archivo y líneas correspondientes.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para BasketStats se seleccionó Merge Sort como algoritmo de ordenamiento porque el programa trabaja con una colección de jugadores que puede aumentar conforme se agregan nuevos registros.

Merge Sort mantiene una complejidad de `O(n log n)` en el mejor, promedio y peor caso, por lo que permite organizar los datos de manera eficiente incluso cuando aumenta la cantidad de jugadores.

Otra ventaja es que el mismo algoritmo puede utilizarse para ordenar diferentes atributos de los objetos. En BasketStats se utiliza para ordenar por nombre, puntos, asistencias y rebotes.

Por estas razones se seleccionó Merge Sort como el algoritmo principal de ordenamiento del proyecto.

**Evidencia en el código:**

El uso del algoritmo se puede observar en las funciones encargadas de ordenar la colección de jugadores.

> Al terminar el código se agregarán aquí los nombres exactos de las funciones, archivo y líneas correspondientes.
