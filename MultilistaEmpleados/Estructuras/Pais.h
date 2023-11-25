#ifndef PROYECTO_CIENCIAS_PAIS_H
#define PROYECTO_CIENCIAS_PAIS_H
#include "../Multilistas/MultilistaCiudades/MultilistaCiudad.h"
#include <iostream>

struct Pais
{
    //int pk;
    std::string nombre;
    bool estado;
    //List<Ciudad> ciudades;

    MultilistaCiudad* ciudades;

    Pais() : nombre(""), estado(true), ciudades(nullptr) {}

    Pais(std::string& nombre)
        : nombre(nombre), estado(true) {}
};
#endif //PROYECTO_CIENCIAS_PAIS_H
