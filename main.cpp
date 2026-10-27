#include <iostream>
#include <string>
#include "ListaJugadores.h"

using namespace std;

int main() {
    ListaJugadores lista;
    int opcion = -1;

    lista.cargarArchivo("jugadores.txt");

    while (opcion != 0) {
        cout << "\n BASKETSTATS " << endl;
        cout << "1. Mostrar jugadores" << endl;
        cout << "2. Ordenar por nombre" << endl;
        cout << "3. Ordenar por puntos" << endl;
        cout << "4. Ordenar por asistencias" << endl;
        cout << "5. Ordenar por rebotes" << endl;
        cout << "6. Buscar jugador por nombre" << endl;
        cout << "7. Agregar jugador" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            lista.mostrarJugadores();
        }
        else if (opcion == 2) {
            lista.ordenar(1);
            lista.mostrarJugadores();
        }
        else if (opcion == 3) {
            lista.ordenar(2);
            lista.mostrarJugadores();
        }
        else if (opcion == 4) {
            lista.ordenar(3);
            lista.mostrarJugadores();
        }
        else if (opcion == 5) {
            lista.ordenar(4);
            lista.mostrarJugadores();
        }
        else if (opcion == 6) {
            string nombreBuscado;

            cout << "Nombre del jugador: ";
            cin >> nombreBuscado;

            lista.buscarJugador(nombreBuscado);
        }
        else if (opcion == 7) {
            string nombre, equipo, posicion;
            int edad;
            double puntos, asistencias, rebotes;

            cout << "Nombre: ";
            cin >> nombre;

            cout << "Equipo: ";
            cin >> equipo;

            cout << "Posicion: ";
            cin >> posicion;

            cout << "Edad: ";
            cin >> edad;

            cout << "Puntos por partido: ";
            cin >> puntos;

            cout << "Asistencias por partido: ";
            cin >> asistencias;

            cout << "Rebotes por partido: ";
            cin >> rebotes;

            lista.agregarJugador(nombre, equipo, posicion, edad,
                                 puntos, asistencias, rebotes);
        }
        else if (opcion != 0) {
            cout << "Opcion no valida" << endl;
        }
    }

    cout << "Programa terminado" << endl;

    return 0;
}
