#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    string equipo;
    string posicion;
    int edad;
    double puntos;
    double asistencias;
    double rebotes;

public:
    Jugador() {
        nombre = "";
        equipo = "";
        posicion = "";
        edad = 0;
        puntos = 0;
        asistencias = 0;
        rebotes = 0;
    }

    Jugador(string nom, string eq, string pos, int ed,
            double pts, double ast, double reb) {
        nombre = nom;
        equipo = eq;
        posicion = pos;
        edad = ed;
        puntos = pts;
        asistencias = ast;
        rebotes = reb;
    }

    string getNombre() const {
        return nombre;
    }

    double getPuntos() const {
        return puntos;
    }

    double getAsistencias() const {
        return asistencias;
    }

    double getRebotes() const {
        return rebotes;
    }

    void mostrar() const {
        cout << nombre << " | "
             << equipo << " | "
             << posicion << " | "
             << edad << " anios | "
             << puntos << " pts | "
             << asistencias << " ast | "
             << rebotes << " reb" << endl;
    }
};

#endif
