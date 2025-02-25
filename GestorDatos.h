#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"

using namespace std;

class GestorDatos {
public:
    // Método genérico para agregar cualquier tipo de entidad
    template <typename T>
    static void agregar(vector<T>& lista, const T& obj);

    // Método genérico para eliminar cualquier tipo de entidad por ID
    template <typename T>
    static void eliminar(vector<T>& lista, int id);

    // Método genérico para buscar cualquier entidad por ID
    template <typename T>
    static T* buscar(vector<T>& lista, int id);

    // Métodos para convertir strings a objetos
    static Paciente convertirPaciente(const string& linea);
    static Medico convertirMedico(const string& linea);
    static CitaMedica convertirCita(const string& linea);

};

#endif