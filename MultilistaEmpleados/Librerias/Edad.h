
#ifndef EDAD_H
#define EDAD_H
#include <iostream>
#include <sstream>
#include <ctime>

// Con esto se calcula la edad
struct Fecha {
    int dia;
    int mes;
    int anio;
};

inline Fecha obtenerFechaDesdeString(const std::string& fechaStr) {
    Fecha fecha{};
    std::stringstream ss(fechaStr);
    char delimiter;

    ss >> fecha.dia >> delimiter >> fecha.mes >> delimiter >> fecha.anio;

    return fecha;
}

inline int calcularEdad(const Fecha& fechaNacimiento) {
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    int edad = tiempoLocal->tm_year + 1900 - fechaNacimiento.anio;

    if (tiempoLocal->tm_mon + 1 < fechaNacimiento.mes ||
        (tiempoLocal->tm_mon + 1 == fechaNacimiento.mes && tiempoLocal->tm_mday < fechaNacimiento.dia)) {
        --edad;
    }
    return edad;
}

#endif
