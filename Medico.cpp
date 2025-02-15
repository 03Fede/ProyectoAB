#include "Medico.h"
#include <iostream>
#include <limits>
using namespace std;

Medico::Medico(int id, string nombre, string especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

int Medico::getId() const { return id; }
string Medico::getNombre() const { return nombre; }
string Medico::getEspecialidad() const { return especialidad; }

void Medico::editarMedico(string nuevoNombre, string nuevaEspecialidad) {
    nombre = nuevoNombre;
    especialidad = nuevaEspecialidad;
}

void Medico::prescribirMedicamento(const std::string& medicamento) {
    cout << "El médico " << nombre << " ha prescrito: " << medicamento << endl;
}

void Medico::mostrarInformacion() const {
    cout << "ID: " << id << ", Nombre: " << nombre
        << ", Especialidad: " << especialidad << endl;
}

Medico Medico::crearMedico() {
    int id;
    string nombre, especialidad;

    cout << "Ingrese ID: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no válida. Ingrese un número entero para el ID: ";
    }
    cin.ignore();

    cout << "Ingrese Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese Especialidad: ";
    getline(cin, especialidad);

    return Medico(id, nombre, especialidad);
}

ostream& operator<<(ostream& os, const Medico& m) {
    os << m.id << "," << m.nombre << "," << m.especialidad;
    return os;
}