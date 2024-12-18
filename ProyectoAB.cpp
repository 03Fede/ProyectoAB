﻿#include "ProyectoAB.h"
#include <iostream>
#include <algorithm>
#include <regex>
#include <fstream>
#include <sstream>
using namespace std;

int validarEntradaEntera(const string& mensaje) {
    int valor;
    cout << mensaje;
    while (true) {
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Intente nuevamente: ";
        }
        else {
            cin.ignore(); // Para descartar caracteres extra
            return valor;
        }
    }
}

string solicitarFechaValida() {
    string fecha;
    regex formatoFecha("\\d{2}/\\d{2}/\\d{4}");

    while (true) {
        cout << "Ingrese Fecha (DD/MM/AAAA): ";
        getline(cin, fecha);
        if (regex_match(fecha, formatoFecha)) {
            return fecha;
        }
        else {
            cout << "Formato inválido. Asegúrese de usar DD/MM/AAAA." << endl;
        }
    }
}

bool validarIdMedico(const vector<Medico>& medicos, int id) {
    return any_of(medicos.begin(), medicos.end(), [id](const Medico& m) { return m.getId() == id; });
}

bool validarIdPaciente(const vector<Paciente>& pacientes, int id) {
    return any_of(pacientes.begin(), pacientes.end(), [id](const Paciente& p) { return p.getId() == id; });
}

void mostrarSubMenuPaciente() {
    cout << "==========================" << endl;
    cout << " Gestión de Pacientes " << endl;
    cout << "==========================" << endl;
    cout << "1. Registrar Paciente" << endl;
    cout << "2. Listar Pacientes" << endl;
    cout << "3. Editar Paciente" << endl;
    cout << "4. Eliminar Paciente" << endl;
    cout << "5. Volver" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarSubMenuMedico() {
    cout << "==========================" << endl;
    cout << " Gestión de Médicos " << endl;
    cout << "==========================" << endl;
    cout << "1. Registrar Médico" << endl;
    cout << "2. Listar Médicos" << endl;
    cout << "3. Editar Médico" << endl;
    cout << "4. Eliminar Médico" << endl;
    cout << "5. Volver" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarSubMenuCita() {
    cout << "==========================" << endl;
    cout << " Gestión de Citas " << endl;
    cout << "==========================" << endl;
    cout << "1. Registrar Cita" << endl;
    cout << "2. Listar Citas" << endl;
    cout << "3. Editar Cita" << endl;
    cout << "4. Eliminar Cita" << endl;
    cout << "5. Volver" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenu() {
    cout << "==========================" << endl;
    cout << " Sistema de Gestión Hospitalaria " << endl;
    cout << "==========================" << endl;
    cout << "1. Paciente" << endl;
    cout << "2. Médico" << endl;
    cout << "3. Cita" << endl;
    cout << "4. Cargar Datos desde Archivos" << endl;
    cout << "5. Guardar Datos en Archivos" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void guardarPacientes(const vector<Paciente>& pacientes, const string& archivo) {
    ofstream out(archivo);
    if (!out.is_open()) {
        cout << "Error al abrir archivo para guardar pacientes." << endl;
        return;
    }
    for (const auto& paciente : pacientes) {
        out << paciente << endl;
    }
    out.close();
    cout << "Pacientes guardados exitosamente." << endl;
}

void guardarMedicos(const vector<Medico>& medicos, const string& archivo) {
    ofstream out(archivo);
    if (!out.is_open()) {
        cout << "Error al abrir archivo para guardar médicos." << endl;
        return;
    }
    for (const auto& medico : medicos) {
        out << medico << endl;
    }
    out.close();
    cout << "Médicos guardados exitosamente." << endl;
}

void guardarCitas(const vector<CitaMedica>& citas, const string& archivo) {
    ofstream out(archivo);
    if (!out.is_open()) {
        cout << "Error al abrir archivo para guardar citas." << endl;
        return;
    }
    for (const auto& cita : citas) {
        out << cita << endl;
    }
    out.close();
    cout << "Citas guardadas exitosamente." << endl;
}

void cargarPacientes(vector<Paciente>& pacientes, const string& archivo) {
    ifstream in(archivo);
    if (!in.is_open()) {
        cout << "No se pudo abrir el archivo para cargar pacientes." << endl;
        return;
    }
    pacientes.clear();
    int id, edad;
    string nombre, historial, linea;

    while (getline(in, linea)) {
        stringstream ss(linea);
        string tempId, tempEdad;

        getline(ss, tempId, ',');
        getline(ss, nombre, ',');
        getline(ss, tempEdad, ',');
        getline(ss, historial);

        id = stoi(tempId);
        edad = stoi(tempEdad);

        pacientes.emplace_back(id, nombre, edad, historial);
    }
    in.close();
    cout << "Pacientes cargados exitosamente desde el archivo." << endl;
}

void cargarMedicos(vector<Medico>& medicos, const string& archivo) {
    ifstream in(archivo);
    if (!in.is_open()) {
        cout << "No se pudo abrir el archivo para cargar médicos." << endl;
        return;
    }
    medicos.clear();
    int id;
    string nombre, especialidad, linea;

    while (getline(in, linea)) {
        stringstream ss(linea);
        string tempId;

        getline(ss, tempId, ',');
        getline(ss, nombre, ',');
        getline(ss, especialidad);

        id = stoi(tempId);
        medicos.emplace_back(id, nombre, especialidad);
    }
    in.close();
    cout << "Médicos cargados exitosamente desde el archivo." << endl;
}

void cargarCitas(vector<CitaMedica>& citas, const string& archivo) {
    ifstream in(archivo);
    if (!in.is_open()) {
        cout << "No se pudo abrir el archivo para cargar citas." << endl;
        return;
    }
    citas.clear();
    int id, idPaciente, idMedico;
    string fecha, linea;

    while (getline(in, linea)) {
        stringstream ss(linea);
        string tempId, tempIdPaciente, tempIdMedico;

        getline(ss, tempId, ',');
        getline(ss, tempIdPaciente, ',');
        getline(ss, tempIdMedico, ',');
        getline(ss, fecha);

        id = stoi(tempId);
        idPaciente = stoi(tempIdPaciente);
        idMedico = stoi(tempIdMedico);

        citas.emplace_back(id, idPaciente, idMedico, fecha);
    }
    in.close();
    cout << "Citas cargadas exitosamente desde el archivo." << endl;
}

int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;
    string archivoPacientes = "pacientes.txt";
    string archivoMedicos = "medicos.txt";
    string archivoCitas = "citas.txt";

    int opcion;
    do {
        mostrarMenu();
        opcion = validarEntradaEntera("Seleccione una opción: ");

        switch (opcion) {
        case 3: {
            int subOpcion;
            do {
                mostrarSubMenuCita();
                subOpcion = validarEntradaEntera("Seleccione una opción: ");
                switch (subOpcion) {
                case 1: {
                    int idPaciente = validarEntradaEntera("Ingrese el ID del Paciente: ");
                    if (!validarIdPaciente(pacientes, idPaciente)) {
                        cout << "ID de Paciente no encontrado. Operación cancelada." << endl;
                        break;
                    }

                    int idMedico = validarEntradaEntera("Ingrese el ID del Médico: ");
                    if (!validarIdMedico(medicos, idMedico)) {
                        cout << "ID de Médico no encontrado. Operación cancelada." << endl;
                        break;
                    }

                    string fecha = solicitarFechaValida();
                    int idCita = static_cast<int>(citas.size()) + 1;
                    citas.emplace_back(idCita, idPaciente, idMedico, fecha);
                    cout << "Cita registrada exitosamente." << endl;
                    break;
                }
                case 2: {
                    cout << "Lista de Citas:" << endl;
                    for (const auto& cita : citas) {
                        cita.mostrarInformacion();
                    }
                    break;
                }
                case 3: {
                    cout << "Funcionalidad de edición de citas pendiente." << endl;
                    break;
                }
                case 4: {
                    cout << "Funcionalidad de eliminación de citas pendiente." << endl;
                    break;
                }
                case 5:
                    break;
                default:
                    cout << "Opción inválida. Intente nuevamente." << endl;
                }
            } while (subOpcion != 5);
            break;
        }
        case 1: {
            int subOpcion;
            do {
                mostrarSubMenuPaciente();
                subOpcion = validarEntradaEntera("Seleccione una opción: ");
                switch (subOpcion) {
                case 1: {
                    Paciente nuevoPaciente = Paciente::crearPaciente();
                    pacientes.push_back(nuevoPaciente);
                    cout << "Paciente registrado exitosamente." << endl;
                    break;
                }
                case 2: {
                    cout << "Lista de Pacientes:" << endl;
                    for (const auto& paciente : pacientes) {
                        paciente.mostrarInformacion();
                    }
                    break;
                }
                case 3: {
                    int id = validarEntradaEntera("Ingrese el ID del Paciente a editar: ");
                    bool encontrado = false;
                    for (auto& paciente : pacientes) {
                        if (paciente.getId() == id) {
                            string nuevoNombre;
                            int nuevaEdad;
                            string nuevoHistorial;

                            cout << "Ingrese nuevo Nombre: ";
                            getline(cin, nuevoNombre);
                            cout << "Ingrese nueva Edad: ";
                            nuevaEdad = validarEntradaEntera("Edad: ");
                            cout << "Ingrese nuevo Historial: ";
                            getline(cin, nuevoHistorial);

                            paciente.editarPaciente(nuevoNombre, nuevaEdad, nuevoHistorial);
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) cout << "Paciente no encontrado." << endl;
                    break;
                }
                case 4: {
                    int id = validarEntradaEntera("Ingrese el ID del Paciente a eliminar: ");
                    auto it = remove_if(pacientes.begin(), pacientes.end(), [id](const Paciente& p) {
                        return p.getId() == id;
                        });
                    if (it != pacientes.end()) {
                        pacientes.erase(it, pacientes.end());
                        cout << "Paciente eliminado correctamente." << endl;
                    }
                    else {
                        cout << "Paciente no encontrado." << endl;
                    }
                    break;
                }
                case 5:
                    break;
                default:
                    cout << "Opción inválida. Intente nuevamente." << endl;
                }
            } while (subOpcion != 5);
            break;
        }
        case 2: {
            int subOpcion;
            do {
                mostrarSubMenuMedico();
                subOpcion = validarEntradaEntera("Seleccione una opción: ");
                switch (subOpcion) {
                case 1: {
                    Medico nuevoMedico = Medico::crearMedico();
                    medicos.push_back(nuevoMedico);
                    cout << "Médico registrado exitosamente." << endl;
                    break;
                }
                case 2: {
                    cout << "Lista de Médicos:" << endl;
                    for (const auto& medico : medicos) {
                        medico.mostrarInformacion();
                    }
                    break;
                }
                case 5:
                    break;
                default:
                    cout << "Opción inválida. Intente nuevamente." << endl;
                }
            } while (subOpcion != 5);
            break;
        }
        case 6:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);

    return 0;
}
