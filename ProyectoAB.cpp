#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"
#include "GestorArchivo.h"
#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

// Función para validar entrada de números enteros
int validarEntradaEntera(const string& mensaje) {
    int valor;
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        try {
            size_t pos;
            valor = stoi(entrada, &pos);
            if (pos == entrada.length()) return valor;
        }
        catch (...) {
            cout << "Entrada no válida. Intente nuevamente." << endl;
        }
    }
}

// Función para solicitar una fecha válida
string solicitarFechaValida() {
    string fecha;
    regex formatoFecha("\\d{2}/\\d{2}/\\d{4}");
    while (true) {
        cout << "Ingrese Fecha (DD/MM/AAAA): ";
        getline(cin, fecha);
        if (regex_match(fecha, formatoFecha)) return fecha;
        cout << "Formato inválido. Asegúrese de usar DD/MM/AAAA." << endl;
    }
}

// Validar si un ID de paciente existe en el vector
bool validarIdPaciente(const vector<Paciente>& pacientes, int id) {
    return any_of(pacientes.begin(), pacientes.end(), [id](const Paciente& p) {
        return p.getId() == id;
        });
}

// Validar si un ID de médico existe en el vector
bool validarIdMedico(const vector<Medico>& medicos, int id) {
    return any_of(medicos.begin(), medicos.end(), [id](const Medico& m) {
        return m.getId() == id;
        });
}

// Función genérica para mostrar los menús
int mostrarSubMenu(const string& titulo, const vector<string>& opciones) {
    cout << "==========================" << endl;
    cout << " " << titulo << " " << endl;
    cout << "==========================" << endl;

    for (size_t i = 0; i < opciones.size(); ++i) {
        cout << i + 1 << ". " << opciones[i] << endl;
    }

    cout << "Seleccione una opción: ";
    int opcion = validarEntradaEntera("");
    if (opcion < 1 || opcion > static_cast<int>(opciones.size())) {
        cout << "Opción inválida. Intente nuevamente." << endl;
        return mostrarSubMenu(titulo, opciones);
    }

    return opcion;
}

// Funciones externas para manejar la presentación de pacientes
void mostrarPaciente(const Paciente& paciente) {
    cout << "ID: " << paciente.getId() << ", Nombre: " << paciente.getNombre()
        << ", Edad: " << paciente.getEdad() << ", Historial: " << paciente.getHistorial() << endl;
}

Paciente solicitarDatosPaciente() {
    int id = validarEntradaEntera("Ingrese ID: ");
    cout << "Ingrese Nombre: ";
    string nombre;
    getline(cin, nombre);

    int edad = validarEntradaEntera("Ingrese Edad: ");
    cout << "Ingrese Historial: ";
    string historial;
    getline(cin, historial);

    return Paciente(id, nombre, edad, historial);
}

// Funciones externas para manejar la presentación de médicos
void mostrarMedico(const Medico& medico) {
    cout << "ID: " << medico.getId() << ", Nombre: " << medico.getNombre()
        << ", Especialidad: " << medico.getEspecialidad() << endl;
}

Medico solicitarDatosMedico() {
    int id = validarEntradaEntera("Ingrese ID: ");
    cout << "Ingrese Nombre: ";
    string nombre;
    getline(cin, nombre);

    cout << "Ingrese Especialidad: ";
    string especialidad;
    getline(cin, especialidad);

    return Medico(id, nombre, especialidad);
}

// Funciones externas para manejar la presentación de citas
void mostrarCita(const CitaMedica& cita) {
    cout << "ID: " << cita.getId() << ", Paciente ID: " << cita.getIdPaciente()
        << ", Médico ID: " << cita.getIdMedico() << ", Fecha: " << cita.getFecha() << endl;
}

CitaMedica solicitarDatosCita(int idCita) {
    int idPaciente = validarEntradaEntera("Ingrese ID del Paciente: ");
    int idMedico = validarEntradaEntera("Ingrese ID del Médico: ");
    string fecha = solicitarFechaValida();

    return CitaMedica(idCita, idPaciente, idMedico, fecha);
}

// Submenú de los pacientes
void gestionarPacientes(vector<Paciente>& pacientes) {
    vector<string> opcionesPaciente = {
        "Registrar Paciente",
        "Listar Pacientes",
        "Editar Paciente",
        "Eliminar Paciente",
        "Volver"
    };

    int subOpcion;
    do {
        subOpcion = mostrarSubMenu("Gestión de Pacientes", opcionesPaciente);

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
            auto it = find_if(pacientes.begin(), pacientes.end(), [id](const Paciente& p) {
                return p.getId() == id;
                });
            if (it != pacientes.end()) {
                string nuevoNombre;
                int nuevaEdad;
                string nuevoHistorial;

                cout << "Ingrese nuevo Nombre: ";
                getline(cin, nuevoNombre);
                nuevaEdad = validarEntradaEntera("Ingrese nueva Edad: ");
                cout << "Ingrese nuevo Historial: ";
                getline(cin, nuevoHistorial);

                it->editarPaciente(nuevoNombre, nuevaEdad, nuevoHistorial);
                cout << "Paciente editado exitosamente." << endl;
            }
            else {
                cout << "Paciente no encontrado." << endl;
            }
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
        }
    } while (subOpcion != 5);
}

// Submenú de  los médicos
void gestionarMedicos(vector<Medico>& medicos) {
    vector<string> opcionesMedico = {
        "Registrar Médico",
        "Listar Médicos",
        "Editar Médico",
        "Eliminar Médico",
        "Volver"
    };

    int subOpcion;
    do {
        subOpcion = mostrarSubMenu("Gestión de Médicos", opcionesMedico);

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
            int id = validarEntradaEntera("Ingrese el ID del Médico a editar: ");
            auto it = find_if(medicos.begin(), medicos.end(), [id](const Medico& m) {
                return m.getId() == id;
                });
            if (it != medicos.end()) {
                string nuevoNombre;
                string nuevaEspecialidad;

                cout << "Ingrese nuevo Nombre: ";
                getline(cin, nuevoNombre);
                cout << "Ingrese nueva Especialidad: ";
                getline(cin, nuevaEspecialidad);

                it->editarMedico(nuevoNombre, nuevaEspecialidad);
                cout << "Médico editado exitosamente." << endl;
            }
            else {
                cout << "Médico no encontrado." << endl;
            }
            break;
        }
        case 4: {
            int id = validarEntradaEntera("Ingrese el ID del Médico a eliminar: ");
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
        }
    } while (subOpcion != 5);
}

// Submenú de las citas
void gestionarCitas(vector<CitaMedica>& citas, const vector<Paciente>& pacientes, const vector<Medico>& medicos) {
    vector<string> opcionesCita = {
        "Registrar Cita",
        "Listar Citas",
        "Editar Cita",
        "Eliminar Cita",
        "Volver"
    };

    int subOpcion;
    do {
        subOpcion = mostrarSubMenu("Gestión de Citas", opcionesCita);

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
            int id = validarEntradaEntera("Ingrese el ID de la Cita a editar: ");
            auto it = find_if(citas.begin(), citas.end(), [id](const CitaMedica& c) {
                return c.getId() == id;
                });
            if (it != citas.end()) {
                string nuevaFecha = solicitarFechaValida();
                it->editarCita(nuevaFecha);
                cout << "Cita editada exitosamente." << endl;
            }
            else {
                cout << "Cita no encontrada." << endl;
            }
            break;
        }
        case 4: {
            int id = validarEntradaEntera("Ingrese el ID de la Cita a eliminar: ");
            auto it = remove_if(citas.begin(), citas.end(), [id](const CitaMedica& c) {
                return c.getId() == id;
                });
            if (it != citas.end()) {
                citas.erase(it, citas.end());
                cout << "Cita eliminada correctamente." << endl;
            }
            else {
                cout << "Cita no encontrada." << endl;
            }
            break;
        }
        }
    } while (subOpcion != 5);
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
        vector<string> opcionesMenuPrincipal = {
            "Pacientes",
            "Médicos",
            "Citas",
            "Cargar Datos",
            "Guardar Datos",
            "Salir"
        };

        opcion = mostrarSubMenu("Sistema de Gestión Hospitalaria", opcionesMenuPrincipal);

        switch (opcion) {
        case 1:
            gestionarPacientes(pacientes);
            break;
        case 2:
            gestionarMedicos(medicos);
            break;
        case 3:
            gestionarCitas(citas, pacientes, medicos);
            break;
        case 4:
            GestorArchivo::cargarPacientes(pacientes, archivoPacientes);
            GestorArchivo::cargarMedicos(medicos, archivoMedicos);
            GestorArchivo::cargarCitas(citas, archivoCitas);
            break;
        case 5:
            GestorArchivo::guardarPacientes(pacientes, archivoPacientes);
            GestorArchivo::guardarMedicos(medicos, archivoMedicos);
            GestorArchivo::guardarCitas(citas, archivoCitas);
            break;
        case 6:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);

    return 0;
}
