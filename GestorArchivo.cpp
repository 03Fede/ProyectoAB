#include "GestorArchivo.h"
#include <fstream>
#include <iostream>
using namespace std;

void GestorArchivo::guardarPacientes(const vector<Paciente>& pacientes, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    for (const auto& paciente : pacientes) {
        archivo << paciente.getId() << "," << paciente.getNombre() << ","
            << paciente.getEdad() << "," << paciente.getHistorial() << endl;
    }
    archivo.close();
    cout << "Datos guardados exitosamente en " << nombreArchivo << endl;
}

void GestorArchivo::cargarPacientes(vector<Paciente>& pacientes, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        int id;
        string nombre;
        int edad;
        string historial;

        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        size_t pos3 = linea.find(',', pos2 + 1);

        id = stoi(linea.substr(0, pos1));
        nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        edad = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
        historial = linea.substr(pos3 + 1);

        pacientes.emplace_back(id, nombre, edad, historial);
    }
    archivo.close();
    cout << "Datos cargados exitosamente desde " << nombreArchivo << endl;
}
