#ifndef ARBOLJUGADORES_H
#define ARBOLJUGADORES_H

#include <string>
#include "Jugador.h"

using namespace std;

class ArbolJugadores;

class NodoJugador {
private:
    Jugador jugador;
    NodoJugador* hijoIzquierdo;
    NodoJugador* hijoDerecho;

public:
    NodoJugador(Jugador jugadorNuevo);

    void insertar(Jugador jugadorNuevo);
    bool buscar(string nombreBuscado);
    void borrarHijos();

    friend class ArbolJugadores;
};


// Crea un nodo con un jugador
NodoJugador::NodoJugador(Jugador jugadorNuevo) {
    jugador = jugadorNuevo;
    hijoIzquierdo = 0;
    hijoDerecho = 0;
}


// Inserta un jugador dependiendo de su nombre
void NodoJugador::insertar(Jugador jugadorNuevo) {
    if (jugadorNuevo.getNombre() < jugador.getNombre()) {

        if (hijoIzquierdo != 0) {
            hijoIzquierdo->insertar(jugadorNuevo);
        }
        else {
            hijoIzquierdo = new NodoJugador(jugadorNuevo);
        }
    }
    else if (jugadorNuevo.getNombre() > jugador.getNombre()) {

        if (hijoDerecho != 0) {
            hijoDerecho->insertar(jugadorNuevo);
        }
        else {
            hijoDerecho = new NodoJugador(jugadorNuevo);
        }
    }
}


// Busca un jugador por nombre
bool NodoJugador::buscar(string nombreBuscado) {
    if (nombreBuscado == jugador.getNombre()) {
        jugador.mostrar();
        return true;
    }

    if (nombreBuscado < jugador.getNombre()) {

        if (hijoIzquierdo != 0) {
            return hijoIzquierdo->buscar(nombreBuscado);
        }

        return false;
    }

    if (hijoDerecho != 0) {
        return hijoDerecho->buscar(nombreBuscado);
    }

    return false;
}


// Borra los nodos hijos
void NodoJugador::borrarHijos() {
    if (hijoIzquierdo != 0) {
        hijoIzquierdo->borrarHijos();
        delete hijoIzquierdo;
        hijoIzquierdo = 0;
    }

    if (hijoDerecho != 0) {
        hijoDerecho->borrarHijos();
        delete hijoDerecho;
        hijoDerecho = 0;
    }
}


class ArbolJugadores {
private:
    NodoJugador* raiz;

public:
    ArbolJugadores();
    ~ArbolJugadores();

    void insertar(Jugador jugadorNuevo);
    bool buscar(string nombreBuscado) const;
    void borrarTodo();
};


// Crea un arbol vacio
ArbolJugadores::ArbolJugadores() {
    raiz = 0;
}


// Libera la memoria del arbol
ArbolJugadores::~ArbolJugadores() {
    borrarTodo();
}


// Inserta un jugador en el arbol
void ArbolJugadores::insertar(Jugador jugadorNuevo) {
    if (raiz == 0) {
        raiz = new NodoJugador(jugadorNuevo);
    }
    else {
        raiz->insertar(jugadorNuevo);
    }
}


// Busca un jugador desde la raiz
bool ArbolJugadores::buscar(string nombreBuscado) const {
    if (raiz != 0) {
        return raiz->buscar(nombreBuscado);
    }

    return false;
}


// Borra todos los nodos del arbol
void ArbolJugadores::borrarTodo() {
    if (raiz != 0) {
        raiz->borrarHijos();
        delete raiz;
        raiz = 0;
    }
}

#endif
