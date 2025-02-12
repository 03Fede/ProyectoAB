#include "GestorDatos.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Constructor
GestorDatos::GestorDatos(vector<Paciente>& p, vector<Medico>& m, vector<CitaMedica>& c)
    : pacientes(p), medicos(m), citas(c) {}

// Métodos para pacientes
void GestorDatos::agregarPaciente(const Paciente& paciente) {
    pacientes.push_back(paciente);
    cout << "Paciente agregado correctamente." << endl;
}

void GestorDatos::eliminarPaciente(int id) {
    auto it = remove_if(pacientes.begin(), pacientes.end(),
        [id](const Paciente& p) { return p.getId() == id; });

    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        cout << "Paciente eliminado correctamente." << endl;
    }
    else {
        cout << "Paciente no encontrado." << endl;
    }
}

Paciente* GestorDatos::buscarPaciente(int id) {
    for (auto& p : pacientes) {
        if (p.getId() == id) return &p;
    }
    return nullptr;
}

// Métodos para médicos
void GestorDatos::agregarMedico(const Medico& medico) {
    medicos.push_back(medico);
    cout << "Médico agregado correctamente." << endl;
}

void GestorDatos::eliminarMedico(int id) {
    auto it = remove_if(medicos.begin(), medicos.end(),
        [id](const Medico& m) { return m.getId() == id; });

    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        cout << "Médico eliminado correctamente." << endl;
    }
    else {
        cout << "Médico no encontrado." << endl;
    }
}

Medico* GestorDatos::buscarMedico(int id) {
    for (auto& m : medicos) {
        if (m.getId() == id) return &m;
    }
    return nullptr;
}

// Métodos para citas médicas
void GestorDatos::agregarCita(const CitaMedica& cita) {
    citas.push_back(cita);
    cout << "Cita médica agregada correctamente." << endl;
}

void GestorDatos::eliminarCita(int id) {
    auto it = remove_if(citas.begin(), citas.end(),
        [id](const CitaMedica& c) { return c.getId() == id; });

    if (it != citas.end()) {
        citas.erase(it, citas.end());
        cout << "Cita médica eliminada correctamente." << endl;
    }
    else {
        cout << "Cita médica no encontrada." << endl;
    }
}

CitaMedica* GestorDatos::buscarCita(int id) {
    for (auto& c : citas) {
        if (c.getId() == id) return &c;
    }
    return nullptr;
}