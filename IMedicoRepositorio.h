#ifndef IMEDICOREPOSITORIO_H
#define IMEDICOREPOSITORIO_H

#include "Medico.h"
#include <vector>

class IMedicoRepositorio {
public:
    virtual void guardar(const Medico& medico) = 0;
    virtual Medico obtenerPorId(int id) = 0;
    virtual std::vector<Medico> obtenerTodos() = 0;
    virtual ~IMedicoRepositorio() = default;
};

#endif
