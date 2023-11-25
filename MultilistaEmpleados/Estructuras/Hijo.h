#ifndef HIJO_H
#define HIJO_H
#include "../Librerias/Edad.h"
#include <string>
struct Hijo
{
    std::string nombre{};
    std::string fechaNacimiento{};
    bool estado{true};
    int edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));

    int sigEdad{-1};


    Hijo():nombre(), fechaNacimiento(){}

    Hijo(std::string nombre, std::string fechaNacimiento)
        : nombre(std::move(nombre)), fechaNacimiento(std::move(fechaNacimiento))
    {
        // Supongo que calcularEdad y obtenerFechaDesdeString están definidas
        edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));
    }

};
#endif
