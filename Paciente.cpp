#include "Paciente.h"
#include <limits>
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
}

void Paciente::mostrarInformacion() const {
    cout << "ID: " << id << ", Nombre: " << nombre
        << ", Edad: " << edad << ", Historial: " << historial << endl;
}

Paciente Paciente::crearPaciente() {
    int id, edad;
    string nombre, historial;

    cout << "Ingrese ID: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no válida. Ingrese un número entero para el ID: ";
    }
    cin.ignore();

    cout << "Ingrese Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese Edad: ";
    while (!(cin >> edad)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no válida. Ingrese un número entero para la Edad: ";
    }
    cin.ignore();

    cout << "Ingrese Historial: ";
    getline(cin, historial);

    return Paciente(id, nombre, edad, historial);
}

ostream& operator<<(ostream& os, const Paciente& p) {
    os << p.id << "," << p.nombre << "," << p.edad << "," << p.historial;
    return os;
}