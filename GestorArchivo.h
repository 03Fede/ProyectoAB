#ifndef GESTORARCHIVO_H
#define GESTORARCHIVO_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"
#include "IRepositorio.h"

class GestorArchivo : public IRepositorio {
public:
    // M�todos para pacientes
    void guardarPacientes(const vector<Paciente>& pacientes) override;
    void cargarPacientes(vector<Paciente>& pacientes) override;

    // M�todos para m�dicos
    void guardarMedicos(const vector<Medico>& medicos);
    void cargarMedicos(vector<Medico>& medicos);

    // M�todos para citas m�dicas
    void guardarCitas(const vector<CitaMedica>& citas);
    void cargarCitas(vector<CitaMedica>& citas);
};

#endif