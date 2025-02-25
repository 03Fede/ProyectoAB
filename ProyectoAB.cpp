#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"
#include "GestorArchivo.h"
#include "GestorDatos.h"
#include "IMedicoRepositorio.h"
#include "MedicoRepositorioArchivo.h"
#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

static int validarEntradaEntera(const string& mensaje);
static string solicitarFechaValida();

static Paciente solicitarDatosPaciente();
static Medico solicitarDatosMedico();
static CitaMedica solicitarDatosCita(int idCita);

static int mostrarSubMenu(const string& titulo, const vector<string>& opciones);
static void gestionarPacientes(vector<Paciente>& pacientes);
static void gestionarMedicos(vector<Medico>& medicos);
static void gestionarCitas(vector<CitaMedica>& citas, vector<Paciente>& pacientes, vector<Medico>& medicos);

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

Paciente solicitarDatosPaciente() {
    int id = validarEntradaEntera("Ingrese ID del Paciente: ");
    cout << "Ingrese Nombre: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);

    int edad = validarEntradaEntera("Ingrese Edad: ");
    cout << "Ingrese Historial: ";
    string historial;
    getline(cin, historial);

    return Paciente(id, nombre, edad, historial);
}

Medico solicitarDatosMedico() {
    int id = validarEntradaEntera("Ingrese ID del Médico: ");
    cout << "Ingrese Nombre: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese Especialidad: ";
    string especialidad;
    getline(cin, especialidad);

    return Medico(id, nombre, especialidad);
}

CitaMedica solicitarDatosCita(int idCita) {
    int idPaciente = validarEntradaEntera("Ingrese ID del Paciente: ");
    int idMedico = validarEntradaEntera("Ingrese ID del Médico: ");
    string fecha = solicitarFechaValida();

    return CitaMedica(idCita, idPaciente, idMedico, fecha);
}

// Función genérica para mostrar los submenús
int mostrarSubMenu(const string& titulo, const vector<string>& opciones) {
    cout << "\n==========================" << endl;
    cout << " " << titulo << " " << endl;
    cout << "==========================" << endl;

    for (size_t i = 0; i < opciones.size(); ++i) {
        cout << i + 1 << ". " << opciones[i] << endl;
    }

    cout << "Seleccione una opción: ";
    return validarEntradaEntera("");
}

void gestionarPacientes(vector<Paciente>& pacientes) {
    vector<string> opcionesPaciente = {
        "Registrar Paciente",
        "Listar Pacientes",
        "Buscar Paciente",
        "Editar Paciente",
        "Eliminar Paciente",
        "Volver"
    };

    int subOpcion;
    do {
        subOpcion = mostrarSubMenu("Gestión de Pacientes", opcionesPaciente);

        switch (subOpcion) {
        case 1: {
            Paciente nuevoPaciente = solicitarDatosPaciente();
            GestorDatos::agregar(pacientes, nuevoPaciente);
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
            int id = validarEntradaEntera("Ingrese el ID del Paciente a buscar: ");
            Paciente* p = GestorDatos::buscar(pacientes, id);
            if (p) {
                p->mostrarInformacion();
            }
            else {
                cout << "Paciente no encontrado." << endl;
            }
            break;
        }
        case 4: {
            int id = validarEntradaEntera("Ingrese el ID del Paciente a editar: ");
            Paciente* p = GestorDatos::buscar(pacientes, id);
            if (p) {
                *p = solicitarDatosPaciente();
                cout << "Paciente editado exitosamente." << endl;
            }
            else {
                cout << "Paciente no encontrado." << endl;
            }
            break;
        }
        case 5: {
            int id = validarEntradaEntera("Ingrese el ID del Paciente a eliminar: ");
            GestorDatos::eliminar(pacientes, id);
            break;
        }
        }
    } while (subOpcion != 6);
}

void gestionarMedicos(vector<Medico>& medicos) {
    vector<string> opcionesMedico = {
        "Registrar Médico",
        "Listar Médicos",
        "Buscar Médico",
        "Editar Médico",
        "Eliminar Médico",
        "Volver"
    };

    int subOpcion;
    do {
        subOpcion = mostrarSubMenu("Gestión de Médicos", opcionesMedico);

        switch (subOpcion) {
        case 1: {
            Medico nuevoMedico = solicitarDatosMedico();
            GestorDatos::agregar(medicos, nuevoMedico);
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
            int id = validarEntradaEntera("Ingrese el ID del Médico a buscar: ");
            Medico* m = GestorDatos::buscar(medicos, id);
            if (m) {
                m->mostrarInformacion();
            }
            else {
                cout << "Médico no encontrado." << endl;
            }
            break;
        }
        case 4: {
            int id = validarEntradaEntera("Ingrese el ID del Médico a editar: ");
            Medico* m = GestorDatos::buscar(medicos, id);
            if (m) {
                *m = solicitarDatosMedico();
                cout << "Médico editado exitosamente." << endl;
            }
            else {
                cout << "Médico no encontrado." << endl;
            }
            break;
        }
        case 5: {
            int id = validarEntradaEntera("Ingrese el ID del Médico a eliminar: ");
            GestorDatos::eliminar(medicos, id);
            break;
        }
        }
    } while (subOpcion != 6);
}

void gestionarCitas(vector<CitaMedica>& citas, vector<Paciente>& pacientes, vector<Medico>& medicos) {
    vector<string> opcionesCita = {
        "Registrar Cita",
        "Listar Citas",
        "Buscar Cita",
        "Editar Cita",
        "Eliminar Cita",
        "Volver"
    };

    int subOpcion;
    do {
        subOpcion = mostrarSubMenu("Gestión de Citas", opcionesCita);

        switch (subOpcion) {
        case 1: {
            CitaMedica nuevaCita = solicitarDatosCita(static_cast<int>(citas.size()) + 1);
            GestorDatos::agregar(citas, nuevaCita);
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
            int id = validarEntradaEntera("Ingrese el ID de la Cita a buscar: ");
            CitaMedica* c = GestorDatos::buscar(citas, id);
            if (c) {
                c->mostrarInformacion();
            }
            else {
                cout << "Cita no encontrada." << endl;
            }
            break;
        }
        case 4: {
            int id = validarEntradaEntera("Ingrese el ID de la Cita a editar: ");
            CitaMedica* c = GestorDatos::buscar(citas, id);
            if (c) {
                *c = solicitarDatosCita(id);
                cout << "Cita editada exitosamente." << endl;
            }
            else {
                cout << "Cita no encontrada." << endl;
            }
            break;
        }
        case 5: {
            int id = validarEntradaEntera("Ingrese el ID de la Cita a eliminar: ");
            GestorDatos::eliminar(citas, id);
            break;
        }
        }
    } while (subOpcion != 6);
}

int main() {
    std::unique_ptr<IMedicoRepositorio> repo = std::make_unique<MedicoRepositorioArchivo>();

    Medico nuevoMedico(3, "Dr. Onnis", "Neurologia");
    repo->guardar(nuevoMedico);

    Medico recuperado = repo->obtenerPorId(3);
    if (recuperado.getNombre() != "Ejemplo") {
        std::cout << "Médico recuperado: " << recuperado.getNombre() << std::endl;
    }
    else {
        std::cout << "Error: No se encontró el médico en el archivo." << std::endl;
    }

    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

    GestorArchivo gestorArchivo;

    int opcion;
    do {
        vector<string> opcionesMenu = { "Pacientes", "Médicos", "Citas", "Guardar Datos","Cargar Datos", "Salir" };
        opcion = mostrarSubMenu("Sistema de Gestión Hospitalaria", opcionesMenu);

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
            gestorArchivo.guardarPacientes(pacientes);
            gestorArchivo.guardarMedicos(medicos);
            gestorArchivo.guardarCitas(citas);
            cout << "Datos guardados correctamente." << endl;
            break;
        case 5:
            gestorArchivo.cargarPacientes(pacientes);
            gestorArchivo.cargarMedicos(medicos);
            gestorArchivo.cargarCitas(citas);
            cout << "Datos cargados correctamente." << endl;
            break;
        case 6:
            cout << "Saliendo del sistema..." << endl;
            break;

        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);

    return 0;
}