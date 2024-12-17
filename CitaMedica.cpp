#include "CitaMedica.h"
#include <iostream>
using namespace std;

CitaMedica::CitaMedica(int id, int idPaciente, int idMedico, string fecha)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha) {}

int CitaMedica::getId() const { return id; }
int CitaMedica::getIdPaciente() const { return idPaciente; }
int CitaMedica::getIdMedico() const { return idMedico; }
string CitaMedica::getFecha() const { return fecha; }

void CitaMedica::editarCita(string nuevaFecha) {
    fecha = nuevaFecha;
    cout << "Cita actualizada correctamente." << endl;
}

void CitaMedica::mostrarInformacion() const {
    cout << "ID: " << id << ", Paciente: " << idPaciente
        << ", Medico: " << idMedico << ", Fecha: " << fecha << endl;
}

CitaMedica CitaMedica::crearCita() {
    int id;
    int idPaciente;
    int idMedico;
    string fecha;

    while (true) {
        cout << "Ingrese ID de la Cita: ";
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

    cout << "Ingrese ID del Paciente: ";
    cin >> idPaciente;
    cin.ignore();

    cout << "Ingrese ID del Medico: ";
    cin >> idMedico;
    cin.ignore();

    cout << "Ingrese Fecha (DD/MM/AAAA): ";
    getline(cin, fecha);

    return CitaMedica(id, idPaciente, idMedico, fecha);
}