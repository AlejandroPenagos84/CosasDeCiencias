#ifndef HIJO_H
#define HIJO_H
#include "Librerias/Edad.h"
#include <string>
struct Hijo
{
    std::string nombre;
    std::string fechaNacimiento;
    int edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));

    int sigEdad{-1};
};
#endif //MULTILISTAEMPLEADOS_HIJO_H
