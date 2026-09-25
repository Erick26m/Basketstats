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

    bool vaAntes(const Jugador& a, const Jugador& b, int criterio) {
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

        int i = inicio;
        int j = mitad + 1;
        int k = inicio;

        while (i <= mitad && j <= fin) {
            if (vaAntes(jugadores[i], jugadores[j], criterio)) {
                aux[k] = jugadores[i];
                i++;
            } else {
                aux[k] = jugadores[j];
                j++;
            }
            k++;
        }

        while (i <= mitad) {
            aux[k] = jugadores[i];
            i++;
            k++;
        }

        while (j <= fin) {
            aux[k] = jugadores[j];
            j++;
            k++;
        }

        for (int x = inicio; x <= fin; x++) {
            jugadores[x] = aux[x];
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

        string nombre, equipo, posicion;
        int edad;
        double puntos, asistencias, rebotes;

        while (archivo >> nombre >> equipo >> posicion
                       >> edad >> puntos >> asistencias >> rebotes) {

            if (cantidad < 100) {
                jugadores[cantidad] = Jugador(nombre, equipo, posicion, edad,
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
