#include <iostream>
#include "ListaJugadores.h"
using namespace std;

int main() {
    ListaJugadores lista;
    int opcion;

    lista.cargarArchivo("jugadores.txt");

    do {
        cout << "\n BASKETSTATS " << endl;
        cout << "1. Mostrar jugadores" << endl;
        cout << "2. Ordenar por nombre" << endl;
        cout << "3. Ordenar por puntos" << endl;
        cout << "4. Ordenar por asistencias" << endl;
        cout << "5. Ordenar por rebotes" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            lista.mostrarJugadores();
        }
        else if (opcion == 2) {
            lista.ordenarPorNombre();
            lista.mostrarJugadores();
        }
        else if (opcion == 3) {
            lista.ordenarPorPuntos();
            lista.mostrarJugadores();
        }
        else if (opcion == 4) {
            lista.ordenarPorAsistencias();
            lista.mostrarJugadores();
        }
        else if (opcion == 5) {
            lista.ordenarPorRebotes();
            lista.mostrarJugadores();
        }
        else if (opcion != 0) {
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    cout << "Programa terminado." << endl;
    return 0;
}
