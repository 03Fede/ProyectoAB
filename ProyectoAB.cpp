#include "ProyectoAB.h"
#include <iostream>
#include <algorithm>
#include <regex>
#include <fstream>
using namespace std;

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
    cout << "4. Salir" << endl;
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

bool validarIdPaciente(const vector<Paciente>& pacientes, int id) {
    return any_of(pacientes.begin(), pacientes.end(), [id](const Paciente& p) { return p.getId() == id; });
}

bool validarIdMedico(const vector<Medico>& medicos, int id) {
    return any_of(medicos.begin(), medicos.end(), [id](const Medico& m) { return m.getId() == id; });
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
        while (true) {
            cin >> opcion;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada no válida. Intente nuevamente: ";
            }
            else {
                cin.ignore();
                break;
            }
        }

        switch (opcion) {
        case 1: {
            int subOpcion;
            do {
                mostrarSubMenuPaciente();
                cin >> subOpcion;
                cin.ignore();
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
                    int id;
                    cout << "Ingrese el ID del Paciente a editar: ";
                    cin >> id;
                    cin.ignore();
                    bool encontrado = false;
                    for (auto& paciente : pacientes) {
                        if (paciente.getId() == id) {
                            string nuevoNombre;
                            int nuevaEdad;
                            string nuevoHistorial;

                            cout << "Ingrese nuevo Nombre: ";
                            getline(cin, nuevoNombre);
                            cout << "Ingrese nueva Edad: ";
                            cin >> nuevaEdad;
                            cin.ignore();
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
                    int id;
                    cout << "Ingrese el ID del Paciente a eliminar: ";
                    cin >> id;
                    cin.ignore();
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
                cin >> subOpcion;
                cin.ignore();
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
                case 3: {
                    int id;
                    cout << "Ingrese el ID del Médico a editar: ";
                    cin >> id;
                    cin.ignore();
                    bool encontrado = false;
                    for (auto& medico : medicos) {
                        if (medico.getId() == id) {
                            string nuevoNombre;
                            string nuevaEspecialidad;

                            cout << "Ingrese nuevo Nombre: ";
                            getline(cin, nuevoNombre);
                            cout << "Ingrese nueva Especialidad: ";
                            getline(cin, nuevaEspecialidad);

                            medico.editarMedico(nuevoNombre, nuevaEspecialidad);
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) cout << "Médico no encontrado." << endl;
                    break;
                }
                case 4: {
                    int id;
                    cout << "Ingrese el ID del Médico a eliminar: ";
                    cin >> id;
                    cin.ignore();
                    auto it = remove_if(medicos.begin(), medicos.end(), [id](const Medico& m) {
                        return m.getId() == id;
                        });
                    if (it != medicos.end()) {
                        medicos.erase(it, medicos.end());
                        cout << "Médico eliminado correctamente." << endl;
                    }
                    else {
                        cout << "Médico no encontrado." << endl;
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
        case 3: {
            int subOpcion;
            do {
                mostrarSubMenuCita();
                cin >> subOpcion;
                cin.ignore();
                switch (subOpcion) {
                case 1: {
                    int idPaciente, idMedico;
                    cout << "Ingrese el ID del Paciente: ";
                    cin >> idPaciente;
                    cin.ignore();
                    if (!validarIdPaciente(pacientes, idPaciente)) {
                        cout << "ID de Paciente no encontrado. Operación cancelada." << endl;
                        break;
                    }
                    cout << "Ingrese el ID del Médico: ";
                    cin >> idMedico;
                    cin.ignore();
                    if (!validarIdMedico(medicos, idMedico)) {
                        cout << "ID de Médico no encontrado. Operación cancelada." << endl;
                        break;
                    }
                    string fecha = solicitarFechaValida();
                    int idCita = citas.size() + 1; // Genera un ID secuencial
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
                default:
                    cout << "Opción inválida. Intente nuevamente." << endl;
                }
            } while (subOpcion != 5);
            break;
        }
        case 4:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);

    return 0;
}
