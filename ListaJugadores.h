#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Jugador.h"

using namespace std;

class ListaJugadores {
private:
    vector<Jugador> jugadores;
    int cantidad;

    bool comparar(const Jugador& a, const Jugador& b, int criterio) {
        if (criterio == 1) {
            return a.getNombre() < b.getNombre();
        }

        if (criterio == 2) {
            return a.getPuntos() > b.getPuntos();
        }

        if (criterio == 3) {
            return a.getAsistencias() > b.getAsistencias();
        }

        return a.getRebotes() > b.getRebotes();
    }

    void merge(int inicio, int mitad, int fin, int criterio) {
        vector<Jugador> aux(100);

        int izquierda = inicio;
        int derecha = mitad + 1;
        int posicion = inicio;

        while (izquierda <= mitad && derecha <= fin) {

            if (comparar(jugadores[izquierda],
                         jugadores[derecha],
                         criterio)) {

                aux[posicion] = jugadores[izquierda];
                izquierda++;
            }
            else {
                aux[posicion] = jugadores[derecha];
                derecha++;
            }

            posicion++;
        }

        while (izquierda <= mitad) {
            aux[posicion] = jugadores[izquierda];
            izquierda++;
            posicion++;
        }

        while (derecha <= fin) {
            aux[posicion] = jugadores[derecha];
            derecha++;
            posicion++;
        }

        for (int i = inicio; i <= fin; i++) {
            jugadores[i] = aux[i];
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

    void cargarArchivo(string nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cout << "No se pudo abrir el archivo." << endl;
            return;
        }

        string nombre;
        string equipo;
        string posicion;

        int edad;

        double puntos;
        double asistencias;
        double rebotes;

        while (archivo >> nombre >> equipo >> posicion
                       >> edad >> puntos >> asistencias >> rebotes) {

            if (cantidad < 100) {

                jugadores[cantidad] =
                    Jugador(nombre, equipo, posicion, edad,
                            puntos, asistencias, rebotes);

                cantidad++;
            }
        }

        archivo.close();
    }

    void mostrarJugadores() const {
        if (cantidad == 0) {
            cout << "No hay jugadores registrados." << endl;
            return;
        }

        for (int i = 0; i < cantidad; i++) {
            jugadores[i].mostrar();
        }
    }

    void ordenarPorNombre() {
        if (cantidad > 1) {
            mergeSort(0, cantidad - 1, 1);
        }
    }

    void ordenarPorPuntos() {
        if (cantidad > 1) {
            mergeSort(0, cantidad - 1, 2);
        }
    }

    void ordenarPorAsistencias() {
        if (cantidad > 1) {
            mergeSort(0, cantidad - 1, 3);
        }
    }

    void ordenarPorRebotes() {
        if (cantidad > 1) {
            mergeSort(0, cantidad - 1, 4);
        }
    }
};

#endif
