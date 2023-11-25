#ifndef SUCURSAL_H
#define SUCURSAL_H
#include "../Multilistas/MultilistaEmpleados/MultilistaEmpleados.h"
#include "Empleado.h"
#include "iostream"

struct Sucursal {
    //int pk;
    //int fk;

    std::string nombre;
    std::string direccion;
    std::string barrio;
    std::string nombreGerente;
    bool estado;
    MultilistaEmpleados* empleados;
    //List<Empleado> empleados;

    Sucursal() :nombre(""), direccion(""), barrio(""), nombreGerente(""), estado(true), empleados(nullptr) {}

    Sucursal(std::string& nombre,
             std::string& direccion,
             std::string& barrio,
             std::string& nombreGerente)
        :nombre(nombre), direccion(direccion), barrio(barrio), nombreGerente(nombreGerente), estado(true) {}
};

#endif
