#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

class GestorDatos {
private:
    vector<Paciente>& pacientes;
    vector<Medico>& medicos;
    vector<CitaMedica>& citas;

public:
    // Constructor que recibe referencias a las listas
    GestorDatos(vector<Paciente>& p, vector<Medico>& m, vector<CitaMedica>& c);

    // M�todos para pacientes
    void agregarPaciente(const Paciente& paciente);
    void eliminarPaciente(int id);
    Paciente* buscarPaciente(int id);

    // M�todos para m�dicos
    void agregarMedico(const Medico& medico);
    void eliminarMedico(int id);
    Medico* buscarMedico(int id);

    // M�todos para citas m�dicas
    void agregarCita(const CitaMedica& cita);
    void eliminarCita(int id);
    CitaMedica* buscarCita(int id);
};

#endif
