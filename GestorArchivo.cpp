#include "GestorArchivo.h"
#include "GestorDatos.h"
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
        Paciente p = GestorDatos::convertirPaciente(linea);
        pacientes.push_back(p);
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
        Medico m = GestorDatos::convertirMedico(linea);
        medicos.push_back(m);
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
        CitaMedica c = GestorDatos::convertirCita(linea);
        citas.push_back(c);
    }
}