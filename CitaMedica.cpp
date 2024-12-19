#include "CitaMedica.h"
#include <iostream>
#include <limits>
using namespace std;

CitaMedica::CitaMedica(int id, int idPaciente, int idMedico, string fecha)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha) {}

int CitaMedica::getId() const { return id; }
int CitaMedica::getIdPaciente() const { return idPaciente; }
int CitaMedica::getIdMedico() const { return idMedico; }
string CitaMedica::getFecha() const { return fecha; }

void CitaMedica::editarCita(string nuevaFecha) {
    fecha = nuevaFecha;
}

void CitaMedica::mostrarInformacion() const {
    cout << "ID: " << id << ", Paciente: " << idPaciente
        << ", Médico: " << idMedico << ", Fecha: " << fecha << endl;
}

CitaMedica CitaMedica::crearCita() {
    int id, idPaciente, idMedico;
    string fecha;

    cout << "Ingrese ID de la Cita: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no válida. Ingrese un número entero para el ID: ";
    }
    cin.ignore();

    cout << "Ingrese ID del Paciente: ";
    while (!(cin >> idPaciente)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no válida. Ingrese un número entero para el ID del Paciente: ";
    }
    cin.ignore();

    cout << "Ingrese ID del Médico: ";
    while (!(cin >> idMedico)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no válida. Ingrese un número entero para el ID del Médico: ";
    }
    cin.ignore();

    cout << "Ingrese Fecha (DD/MM/AAAA): ";
    getline(cin, fecha);

    return CitaMedica(id, idPaciente, idMedico, fecha);
}

ostream& operator<<(ostream& os, const CitaMedica& c) {
    os << c.id << "," << c.idPaciente << "," << c.idMedico << "," << c.fecha;
    return os;
}