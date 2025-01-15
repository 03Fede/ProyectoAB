#include "GestorArchivo.h"
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void GestorArchivo::guardarPacientes(const vector<Paciente>& pacientes, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar pacientes." << endl;
        return;
    }
    for (const auto& paciente : pacientes) {
        archivo << paciente.getId() << "," << paciente.getNombre() << "," << paciente.getEdad() << "," << paciente.getHistorial() << endl;
    }
    archivo.close();
}

void GestorArchivo::guardarMedicos(const vector<Medico>& medicos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar médicos." << endl;
        return;
    }
    for (const auto& medico : medicos) {
        archivo << medico.getId() << "," << medico.getNombre() << "," << medico.getEspecialidad() << endl;
    }
    archivo.close();
}

void GestorArchivo::guardarCitas(const vector<CitaMedica>& citas, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar citas." << endl;
        return;
    }
    for (const auto& cita : citas) {
        archivo << cita.getId() << "," << cita.getIdPaciente() << "," << cita.getIdMedico() << "," << cita.getFecha() << endl;
    }
    archivo.close();
}

void GestorArchivo::cargarPacientes(vector<Paciente>& pacientes, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar pacientes." << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id, edad;
        string nombre, historial;

        getline(ss, nombre, ',');
        ss >> id >> edad;
        getline(ss, historial);

        pacientes.emplace_back(id, nombre, edad, historial);
    }
    archivo.close();
}

void GestorArchivo::cargarMedicos(vector<Medico>& medicos, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar médicos." << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id;
        string nombre, especialidad;

        getline(ss, nombre, ',');
        ss >> id;
        getline(ss, especialidad);

        medicos.emplace_back(id, nombre, especialidad);
    }
    archivo.close();
}

void GestorArchivo::cargarCitas(vector<CitaMedica>& citas, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar citas." << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int id, idPaciente, idMedico;
        string fecha;

        ss >> id >> idPaciente >> idMedico;
        getline(ss, fecha);

        citas.emplace_back(id, idPaciente, idMedico, fecha);
    }
    archivo.close();
}