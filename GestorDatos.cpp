#include "GestorDatos.h"
#include "CitaMedica.h"
#include <sstream>
#include "Medico.h"
#include "Paciente.h"


// Método de conversión de datos para Paciente
Paciente GestorDatos::convertirPaciente(const string& linea) {
    stringstream ss(linea);
    int id, edad;
    string nombre, historial;

    if (!(ss >> id)) {
        cerr << "Error al leer el ID del paciente." << endl;
        return Paciente(-1, "Error", -1, "Error");
    }

    ss.ignore();
    getline(ss, nombre, ',');
    if (!(ss >> edad)) {
        cerr << "Error al leer la edad del paciente." << endl;
        return Paciente(-1, "Error", -1, "Error");
    }

    ss.ignore();
    getline(ss, historial);

    return Paciente(id, nombre, edad, historial);
}

// Método de conversión de datos para Medico
Medico GestorDatos::convertirMedico(const string& linea) {
    stringstream ss(linea);
    int id;
    string nombre, especialidad;

    if (!(ss >> id)) {
        cerr << "Error al leer el ID del médico." << endl;
        return Medico(-1, "Error", "Error");
    }

    ss.ignore();
    getline(ss, nombre, ',');
    getline(ss, especialidad);

    return Medico(id, nombre, especialidad);
}

// Método de conversión de datos para CitaMedica
CitaMedica GestorDatos::convertirCita(const string& linea) {
    stringstream ss(linea);
    int id, idPaciente, idMedico;
    string fecha;

    if (!(ss >> id >> idPaciente >> idMedico)) {
        cerr << "Error al leer la cita médica." << endl;
        return CitaMedica(-1, -1, -1, "Error");
    }

    ss.ignore();
    getline(ss, fecha);

    return CitaMedica(id, idPaciente, idMedico, fecha);
}

// Agregar un objeto a la lista
template <typename T>
void GestorDatos::agregar(vector<T>& lista, const T& obj) {
    lista.push_back(obj);
}

// Eliminar un objeto de la lista por ID
template <typename T>
void GestorDatos::eliminar(vector<T>& lista, int id) {
    auto it = remove_if(lista.begin(), lista.end(),
        [id](const T& obj) { return obj.getId() == id; });

    if (it != lista.end()) {
        lista.erase(it, lista.end());
        cout << "Elemento eliminado correctamente." << endl;
    }
    else {
        cout << "No se encontró el elemento con ID " << id << "." << endl;
    }
}

// Buscar un objeto en la lista por ID
template <typename T>
T* GestorDatos::buscar(vector<T>& lista, int id) {
    for (auto& obj : lista) {
        if (obj.getId() == id) return &obj;
    }
    return nullptr;
}

// Explicación: Aquí explicitamos las instancias de las plantillas.
template void GestorDatos::agregar(vector<Paciente>&, const Paciente&);
template void GestorDatos::agregar(vector<Medico>&, const Medico&);
template void GestorDatos::agregar(vector<CitaMedica>&, const CitaMedica&);

template void GestorDatos::eliminar(vector<Paciente>&, int);
template void GestorDatos::eliminar(vector<Medico>&, int);
template void GestorDatos::eliminar(vector<CitaMedica>&, int);

template Paciente* GestorDatos::buscar(vector<Paciente>&, int);
template Medico* GestorDatos::buscar(vector<Medico>&, int);
template CitaMedica* GestorDatos::buscar(vector<CitaMedica>&, int);