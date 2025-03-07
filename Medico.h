#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include "IPersona.h"
#include "IMedicoFunciones.h" 
using namespace std;

class Medico :  public IPersona, public IMedicoFunciones {
private:
    int id;
    string nombre;
    string especialidad;

public:
    Medico(int id, string nombre, string especialidad);

    int getId() const override;
    string getNombre() const override;
    
    string getEspecialidad() const;
    void editarMedico(string nuevoNombre, string nuevaEspecialidad);
    void mostrarInformacion() const override;

    void prescribirMedicamento(const std::string& medicamento) override;

    static Medico crearMedico();

    friend ostream& operator<<(ostream& os, const Medico& m);

    ~Medico() override = default;
};

#endif