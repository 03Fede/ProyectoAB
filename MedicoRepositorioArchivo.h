#ifndef MEDICOREPOSITORIOARCHIVO_H
#define MEDICOREPOSITORIOARCHIVO_H

#include "IMedicoRepositorio.h"
#include "Medico.h"
#include <vector>
#include <iostream>

class MedicoRepositorioArchivo : public IMedicoRepositorio {
public:
    void guardar(const Medico& medico) override;
    Medico obtenerPorId(int id) override;
    std::vector<Medico> obtenerTodos() override;
};

#endif
