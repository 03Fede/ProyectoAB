#include "Paciente.h"

// Constructor
Paciente::Paciente(int id, const std::string& nombre, int edad, const std::string& historial_clinico)
    : id(id), nombre(nombre), edad(edad), historial_clinico(historial_clinico) {}

// Métodos para gestionar pacientes
Paciente Paciente::crearPaciente(int id, const std::string& nombre, int edad, const std::string& historial) {
    return Paciente(id, nombre, edad, historial);
}

void Paciente::editarPaciente(const std::string& nuevoNombre, int nuevaEdad, const std::string& nuevoHistorial) {
    nombre = nuevoNombre;
    edad = nuevaEdad;
    historial_clinico = nuevoHistorial;
}

Paciente Paciente::buscarPaciente(const std::vector<Paciente>& pacientes, int id) {
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [id](const Paciente& p) { return p.id == id; });
    if (it != pacientes.end()) {
        return *it;
    }
    throw std::runtime_error("Paciente no encontrado.");
}

void Paciente::listarHistorial() const {
    std::cout << "Historial de " << nombre << ": " << historial_clinico << std::endl;
}

// Getters
int Paciente::getId() const {
    return id;
}

std::string Paciente::getNombre() const {
    return nombre;
}