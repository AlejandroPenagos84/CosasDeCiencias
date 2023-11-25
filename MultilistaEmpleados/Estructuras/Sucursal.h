#ifndef SUCURSAL_H
#define SUCURSAL_H
#include "../Multilistas/MultilistaEmpleados/MultilistaEmpleados.h"
#include "Empleado.h"
#include "iostream"

struct Sucursal {
    int pk;
    int fk;

    std::string nombre;
    std::string direccion;
    std::string barrio;
    std::string nombreGerente;
    MultilistaEmpleados* empleados;
    //List<Empleado> empleados;

    Sucursal() : pk(0), fk(0), nombre(""), direccion(""), barrio(""), nombreGerente(""), empleados(nullptr) {}

    Sucursal(int pk,
             int fk,
             std::string& nombre,
             std::string& direccion,
             std::string& barrio,
             std::string& nombreGerente,
             MultilistaEmpleados* empleados)
        : pk(pk), fk(fk), nombre(nombre), direccion(direccion), barrio(barrio), nombreGerente(nombreGerente) {}
};

#endif
