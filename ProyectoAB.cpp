// ProyectoAB.cpp: define el punto de entrada de la aplicación.
//

#include <iostream>
#include <vector>
#include "Paciente.h"
#include "ProyectoAB.h"

using namespace std;

int main()
{
        // Crear un vector para almacenar los pacientes
        std::vector<Paciente> pacientes;

        // Crear pacientes
        Paciente p1 = Paciente::crearPaciente(1, "Juan Perez", 45, "Hipertensión");
        Paciente p2 = Paciente::crearPaciente(2, "Ana Gomez", 30, "Diabetes tipo 2");
        pacientes.push_back(p1);
        pacientes.push_back(p2);

        // Mostrar pacientes creados
        std::cout << "Pacientes iniciales:\n";
        for (const auto& p : pacientes) {
            std::cout << "ID: " << p.getId() << ", Nombre: " << p.getNombre() << "\n";
        }

        // Editar información de un paciente
        std::cout << "\nEditando información del paciente con ID 1...\n";
        p1.editarPaciente("Juan P. Gonzalez", 46, "Hipertensión controlada");

        // Buscar un paciente por ID
        std::cout << "\nBuscando paciente con ID 2...\n";
        try {
            Paciente encontrado = Paciente::buscarPaciente(pacientes, 2);
            std::cout << "Paciente encontrado: " << encontrado.getNombre() << "\n";
            encontrado.listarHistorial();
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        // Listar historial de un paciente
        std::cout << "\nListando el historial de Juan P. Gonzalez...\n";
        p1.listarHistorial();

        return 0;
    
	cout << "Hello CMake." << endl;
	return 0;
}
