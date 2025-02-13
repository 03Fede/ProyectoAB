#ifndef CITAMEDICA_H
#define CITAMEDICA_H

#include <string>
#include "IGestionable.h"
using namespace std;

class CitaMedica : public IGestionable {
private:
    int id;
    int idPaciente;
    int idMedico;
    string fecha;

public:
    CitaMedica(int id, int idPaciente, int idMedico, string fecha);

    int getId() const override;
    int getIdPaciente() const;
    int getIdMedico() const;
    string getFecha() const;

    void editarCita(string nuevaFecha);
    void mostrarInformacion() const override;

    static CitaMedica crearCita();

    friend ostream& operator<<(ostream& os, const CitaMedica& c);
};
#endif