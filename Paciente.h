#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Paciente {
private:
    int id;
    std::string nombre;
    int edad;
    std::string historial_clinico;

public:
    // Constructor
    Paciente(int id, const std::string& nombre, int edad, const std::string& historial_clinico);

    // Métodos para gestionar pacientes
    static Paciente crearPaciente(int id, const std::string& nombre, int edad, const std::string& historial);
    void editarPaciente(const std::string& nuevoNombre, int nuevaEdad, const std::string& nuevoHistorial);
    static Paciente buscarPaciente(const std::vector<Paciente>& pacientes, int id);
    void listarHistorial() const;

    // Getters
    int getId() const;
    std::string getNombre() const;
};

#endif // PACIENTE_H