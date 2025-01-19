# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(ProyectoAB VERSION 1.0 LANGUAGES CXX)

# Configuración del estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Detectar el sistema operativo
if (WIN32)
    message(STATUS "Sistema detectado: Windows")
elseif (UNIX AND NOT APPLE)
    message(STATUS "Sistema detectado: Linux/Unix")
elseif (APPLE)
    message(STATUS "Sistema detectado: macOS")
else ()
    message(WARNING "Sistema operativo desconocido")
endif ()

# Habilitar Recarga activa en compiladores de MSVC si se admite
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif ()

# Archivos fuente
set(SOURCES
    ProyectoAB.cpp
    Paciente.cpp
    Medico.cpp
    CitaMedica.cpp
    GestorArchivo.cpp
)

# Archivos de encabezado
set(HEADERS
    ProyectoAB.h
    Paciente.h
    Medico.h
    CitaMedica.h
    GestorArchivo.h
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Opcional: Definir configuraciones específicas para compiladores
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
endif ()

# TODO: Agregue pruebas y destinos de instalación si es necesario