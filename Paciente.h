#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>
#include "IGestionable.h" 
using namespace std;

class Paciente : public IGestionable {
private:
    int id;
    string nombre;
    int edad;
    string historial;

public:
    Paciente(int id, string nombre, int edad, string historial);

    int getId() const override;
    string getNombre() const;
    int getEdad() const;
    string getHistorial() const;

    void editarPaciente(string nuevoNombre, int nuevaEdad, string nuevoHistorial);
    void mostrarInformacion() const override;

    static Paciente crearPaciente();
    
    friend ostream& operator<<(ostream& os, const Paciente& p);
};

#endif