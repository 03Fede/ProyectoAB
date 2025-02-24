#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include "IPersona.h"
using namespace std;

class Paciente : public IPersona {
private:
    int id;
    string nombre;
    int edad;
    string historial;

public:
    Paciente(int id, string nombre, int edad, string historial);

    int getId() const override;
    string getNombre() const override;

    int getEdad() const;
    string getHistorial() const;

    void editarPaciente(string nuevoNombre, int nuevaEdad, string nuevoHistorial);
    void mostrarInformacion() const override;

    static Paciente crearPaciente();
    
    friend ostream& operator<<(ostream& os, const Paciente& p);

    ~Paciente() override = default;
};

#endif