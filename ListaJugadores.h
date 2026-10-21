#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Jugador.h"
#include "ArbolJugadores.h"

using namespace std;

class ListaJugadores {
private:
    vector<Jugador> jugadores;
    int cantidad;
    ArbolJugadores arbolJugadores;

    bool comparar(const Jugador& jugador1, const Jugador& jugador2, int criterio) {
        if (criterio == 1)
            return jugador1.getNombre() < jugador2.getNombre();

        if (criterio == 2)
            return jugador1.getPuntos() > jugador2.getPuntos();

        if (criterio == 3)
            return jugador1.getAsistencias() > jugador2.getAsistencias();

        return jugador1.getRebotes() > jugador2.getRebotes();
    }

    void merge(int inicio, int mitad, int fin, int criterio) {
        vector<Jugador> jugadoresOrdenados(100);

        int izquierda = inicio;
        int derecha = mitad + 1;
        int posicion = inicio;

        while (izquierda <= mitad && derecha <= fin) {
            if (comparar(jugadores[izquierda], jugadores[derecha], criterio)) {
                jugadoresOrdenados[posicion] = jugadores[izquierda];
                izquierda++;
            }
            else {
                jugadoresOrdenados[posicion] = jugadores[derecha];
                derecha++;
            }

            posicion++;
        }

        while (izquierda <= mitad) {
            jugadoresOrdenados[posicion] = jugadores[izquierda];
            izquierda++;
            posicion++;
        }

        while (derecha <= fin) {
            jugadoresOrdenados[posicion] = jugadores[derecha];
            derecha++;
            posicion++;
        }

        for (int i = inicio; i <= fin; i++) {
            jugadores[i] = jugadoresOrdenados[i];
        }
    }

    void mergeSort(int inicio, int fin, int criterio) {
        if (inicio < fin) {
            int mitad = (inicio + fin) / 2;

            mergeSort(inicio, mitad, criterio);
            mergeSort(mitad + 1, fin, criterio);

            merge(inicio, mitad, fin, criterio);
        }
    }

public:
    ListaJugadores() : jugadores(100) {
        cantidad = 0;
    }

    // Carga los jugadores del archivo en el vector y en el arbol
    void cargarArchivo(string nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cout << "No se pudo abrir el archivo" << endl;
            return;
        }

        string nombre, equipo, posicion;
        int edad;
        double puntos, asistencias, rebotes;

        while (archivo >> nombre >> equipo >> posicion
                       >> edad >> puntos >> asistencias >> rebotes) {

            if (cantidad < 100) {
                Jugador jugadorNuevo(nombre, equipo, posicion, edad,
                                     puntos, asistencias, rebotes);

                jugadores[cantidad] = jugadorNuevo;
                arbolJugadores.insertar(jugadorNuevo);

                cantidad++;
            }
        }

        archivo.close();
    }

    // Muestra todos los jugadores guardados en el vector
    void mostrarJugadores() const {
        for (int i = 0; i < cantidad; i++) {
            jugadores[i].mostrar();
        }
    }

    // Ordena los jugadores dependiendo del criterio seleccionado
    void ordenar(int criterio) {
        if (cantidad > 1) {
            mergeSort(0, cantidad - 1, criterio);
        }
    }

    // Busca un jugador por nombre utilizando el arbol
    void buscarJugador(string nombreBuscado) {
        bool jugadorEncontrado = arbolJugadores.buscar(nombreBuscado);

        if (!jugadorEncontrado) {
            cout << "Jugador no encontrado" << endl;
        }
    }
};

#endif
