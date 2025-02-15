#include "MedicoRepositorioArchivo.h"
#include <fstream>
#include <sstream>

void MedicoRepositorioArchivo::guardar(const Medico& medico) {
    std::ofstream archivo("medicos.txt", std::ios::app);

    if (!archivo) {
        std::cout << "Error: No se pudo abrir el archivo para escribir." << std::endl;
        return;
    }

    archivo << medico.getId() << "," << medico.getNombre() << "," << medico.getEspecialidad() << std::endl;
    archivo.close(); 

    std::cout << "Médico guardado en el archivo correctamente." << std::endl;
}

Medico MedicoRepositorioArchivo::obtenerPorId(int id) {
    std::ifstream archivo("medicos.txt");

    if (!archivo) {
        std::cout << "Error: No se pudo abrir el archivo para leer." << std::endl;
        return Medico(-1, "No encontrado", "Desconocido");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string idString, nombre, especialidad;
        int idArchivo = -1;

        if (std::getline(ss, idString, ',')) {
            try {
                idArchivo = std::stoi(idString);
            }
            catch (const std::exception& e) {
                std::cerr << "Error al convertir ID: " << e.what() << std::endl;
                continue;
            }
        }

        if (std::getline(ss, nombre, ',') && std::getline(ss, especialidad)) {
            if (idArchivo == id) {
                archivo.close();
                return Medico(idArchivo, nombre, especialidad);
            }
        }
    }

    archivo.close();
    std::cout << "Error: No se encontró el médico en el archivo." << std::endl;
    return Medico(-1, "No encontrado", "Desconocido");
}

std::vector<Medico> MedicoRepositorioArchivo::obtenerTodos() {
    std::cout << "Obteniendo todos los médicos desde archivo" << std::endl;
    return { Medico(1, "Dr. Juan", "Cardiología"), Medico(2, "Dra. Ana", "Pediatría") };
}