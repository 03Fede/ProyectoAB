#include "Medico.h"
#include <iostream>
using namespace std;

Medico::Medico(int id, string nombre, string especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

int Medico::getId() const { return id; }
string Medico::getNombre() const { return nombre; }
string Medico::getEspecialidad() const { return especialidad; }

void Medico::editarMedico(string nuevoNombre, string nuevaEspecialidad) {
    nombre = nuevoNombre;
    especialidad = nuevaEspecialidad;
    cout << "Medico actualizado correctamente." << endl;
}

void Medico::mostrarInformacion() const {
    cout << "ID: " << id << ", Nombre: " << nombre
        << ", Especialidad: " << especialidad << endl;
}

Medico Medico::crearMedico() {
    int id;
    string nombre;
    string especialidad;

    while (true) {
        cout << "Ingrese ID: ";
        cin >> id;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Intente nuevamente." << endl;
        }
        else {
            cin.ignore();
            break;
        }
    }

    cout << "Ingrese Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese Especialidad: ";
    getline(cin, especialidad);

    return Medico(id, nombre, especialidad);
}