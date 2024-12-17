#ifndef CITAMEDICA_H
#define CITAMEDICA_H

#include <string>
using namespace std;

class CitaMedica {
private:
    int id;
    int idPaciente;
    int idMedico;
    string fecha;

public:
    CitaMedica(int id, int idPaciente, int idMedico, string fecha);

    int getId() const;
    int getIdPaciente() const;
    int getIdMedico() const;
    string getFecha() const;

    void editarCita(string nuevaFecha);
    void mostrarInformacion() const;

    static CitaMedica crearCita();
};

#endif