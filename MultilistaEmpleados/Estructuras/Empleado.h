#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include "../Librerias/Edad.h"
#include "../Multilistas/MultilistaHijo.h"

struct Empleado {
    //int pk;
    //int fk;

    std::string nombre;
    //std::string apellido;
    //std::string tipoIdentificacion;
    //std::string numIdentificacion;
    char sexo;
    //std::string telefonoCelular;
    //std::string telefonoFijo;
    //std::string email;

    std::string ciudadNacimiento;
    //std::string paisNacimiento;
    //std::string ciudadResidencia;
    //std::string direccion;
    //
    //char tieneHijos;
    std::string actividadLaboral;
    std::string sucursalTrabajo;
    std::string barrio;
    int numHijos;
    std::string fechaNacimiento;
    //MultilistaHijo hijos{numHijos};
    int edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));


    // Estas variable se inicializan con 0 para evitar doble asignacion
    // Con estas se va manejar la posicion del siguiente dato segun la caracteristica de este
    int sigSexo{-1};
    int sigActividadLaboral{-1};
    int sigEdad{-1};
    int sigNombreSurcursal{-1};
    int sigCiudadNacimiento{-1};
    int sigBarrio{-1};
    int sigNumHijos{-1};
};



#endif

