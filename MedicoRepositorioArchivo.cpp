#include "MedicoRepositorioArchivo.h"

void MedicoRepositorioArchivo::guardar(const Medico& medico) {
    std::cout << "Guardando médico en archivo: " << medico.getNombre() << std::endl;
}

Medico MedicoRepositorioArchivo::obtenerPorId(int id) {
    std::cout << "Obteniendo médico con ID " << id << " desde archivo" << std::endl;
    return Medico(id, "Ejemplo", "General");
}

std::vector<Medico> MedicoRepositorioArchivo::obtenerTodos() {
    std::cout << "Obteniendo todos los médicos desde archivo" << std::endl;
    return { Medico(1, "Dr. Juan", "Cardiología"), Medico(2, "Dra. Ana", "Pediatría") };
}