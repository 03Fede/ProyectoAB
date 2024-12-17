#ifndef GESTORARCHIVO_H
#define GESTORARCHIVO_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"
using namespace std;

class GestorArchivo {
public:
    static void guardarPacientes(const vector<Paciente>& pacientes, const string& nombreArchivo);
    static void cargarPacientes(vector<Paciente>& pacientes, const string& nombreArchivo);

    static void guardarMedicos(const vector<Medico>& medicos, const string& nombreArchivo);
    static void cargarMedicos(vector<Medico>& medicos, const string& nombreArchivo);

    static void guardarCitas(const vector<CitaMedica>& citas, const string& nombreArchivo);
    static void cargarCitas(vector<CitaMedica>& citas, const string& nombreArchivo);
};

#endif