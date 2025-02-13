#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class GestorDatos {
public:
    // M�todo gen�rico para agregar cualquier tipo de entidad
    template <typename T>
    static void agregar(vector<T>& lista, const T& obj);

    // M�todo gen�rico para eliminar cualquier tipo de entidad por ID
    template <typename T>
    static void eliminar(vector<T>& lista, int id);

    // M�todo gen�rico para buscar cualquier entidad por ID
    template <typename T>
    static T* buscar(vector<T>& lista, int id);
};

#endif