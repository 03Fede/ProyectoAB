#include "GestorDatos.h"
#include "CitaMedica.h"
#include "Medico.h"
#include "Paciente.h"

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

template void GestorDatos::agregar(vector<Paciente>&, const Paciente&);
template void GestorDatos::agregar(vector<Medico>&, const Medico&);
template void GestorDatos::agregar(vector<CitaMedica>&, const CitaMedica&);

template void GestorDatos::eliminar(vector<Paciente>&, int);
template void GestorDatos::eliminar(vector<Medico>&, int);
template void GestorDatos::eliminar(vector<CitaMedica>&, int);

template Paciente* GestorDatos::buscar(vector<Paciente>&, int);
template Medico* GestorDatos::buscar(vector<Medico>&, int);
template CitaMedica* GestorDatos::buscar(vector<CitaMedica>&, int);