#include "GestorArchivo.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Pacientes
void GestorArchivo::guardarPacientes(const vector<Paciente>& pacientes) {
    ofstream archivo("pacientes.txt");
    for (const auto& p : pacientes) {
        archivo << p.getId() << " " << p.getNombre() << " " << p.getEdad() << " " << p.getHistorial() << endl;
    }
}

void GestorArchivo::cargarPacientes(vector<Paciente>& pacientes) {
    ifstream archivo("pacientes.txt");
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id, edad;
        string nombre, historial;
        ss >> id >> nombre >> edad >> historial;
        pacientes.push_back(Paciente(id, nombre, edad, historial));
    }
}

// Médicos
void GestorArchivo::guardarMedicos(const vector<Medico>& medicos) {
    ofstream archivo("medicos.txt");
    for (const auto& m : medicos) {
        archivo << m.getId() << " " << m.getNombre() << " " << m.getEspecialidad() << endl;
    }
}

void GestorArchivo::cargarMedicos(vector<Medico>& medicos) {
    ifstream archivo("medicos.txt");
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id;
        string nombre, especialidad;
        ss >> id >> nombre >> especialidad;
        medicos.push_back(Medico(id, nombre, especialidad));
    }
}

// Citas Médicas
void GestorArchivo::guardarCitas(const vector<CitaMedica>& citas) {
    ofstream archivo("citas.txt");
    for (const auto& c : citas) {
        archivo << c.getId() << " " << c.getIdPaciente() << " " << c.getIdMedico() << " " << c.getFecha() << endl;
    }
}

void GestorArchivo::cargarCitas(vector<CitaMedica>& citas) {
    ifstream archivo("citas.txt");
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id, idPaciente, idMedico;
        string fecha;
        ss >> id >> idPaciente >> idMedico >> fecha;
        citas.push_back(CitaMedica(id, idPaciente, idMedico, fecha));
    }
}