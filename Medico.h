#ifndef MEDICO_H
#define MEDICO_H

#include <string>
using namespace std;

class Medico {
private:
    int id;
    string nombre;
    string especialidad;

public:
    Medico(int id, string nombre, string especialidad);

    int getId() const;
    string getNombre() const;
    string getEspecialidad() const;

    void editarMedico(string nuevoNombre, string nuevaEspecialidad);
    void mostrarInformacion() const;

    static Medico crearMedico();
};

#endif