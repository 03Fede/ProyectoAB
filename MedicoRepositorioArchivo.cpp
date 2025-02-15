#include "MedicoRepositorioArchivo.h"

void MedicoRepositorioArchivo::guardar(const Medico& medico) {
    std::cout << "Guardando m�dico en archivo: " << medico.getNombre() << std::endl;
}

Medico MedicoRepositorioArchivo::obtenerPorId(int id) {
    std::cout << "Obteniendo m�dico con ID " << id << " desde archivo" << std::endl;
    return Medico(id, "Ejemplo", "General");
}

std::vector<Medico> MedicoRepositorioArchivo::obtenerTodos() {
    std::cout << "Obteniendo todos los m�dicos desde archivo" << std::endl;
    return { Medico(1, "Dr. Juan", "Cardiolog�a"), Medico(2, "Dra. Ana", "Pediatr�a") };
}