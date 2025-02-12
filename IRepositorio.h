#pragma once
#ifndef IREPOSITORIO_H
#define IREPOSITORIO_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

class IRepositorio {
public:
    virtual void guardarPacientes(const vector<Paciente>& pacientes) = 0;
    virtual void cargarPacientes(vector<Paciente>& pacientes) = 0;
    virtual ~IRepositorio() {}
};

#endif
