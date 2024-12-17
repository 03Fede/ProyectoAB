#include "Paciente.h"
#include <iostream>
using namespace std;

Paciente::Paciente(int id, string nombre, int edad, string historial)
    : id(id), nombre(nombre), edad(edad), historial(historial) {}

int Paciente::getId() const { return id; }
string Paciente::getNombre() const { return nombre; }
int Paciente::getEdad() const { return edad; }
string Paciente::getHistorial() const { return historial; }

void Paciente::editarPaciente(string nuevoNombre, int nuevaEdad, string nuevoHistorial) {
    nombre = nuevoNombre;
    edad = nuevaEdad;
    historial = nuevoHistorial;
    cout << "Paciente actualizado correctamente." << endl;
}

void Paciente::mostrarInformacion() const {
    cout << "ID: " << id << ", Nombre: " << nombre
        << ", Edad: " << edad << ", Historial: " << historial << endl;
}

Paciente Paciente::crearPaciente() {
    int id;
    string nombre;
    int edad;
    string historial;

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

    while (true) {
        cout << "Ingrese Edad: ";
        cin >> edad;
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

    cout << "Ingrese Historial: ";
    getline(cin, historial);

    return Paciente(id, nombre, edad, historial);
}
