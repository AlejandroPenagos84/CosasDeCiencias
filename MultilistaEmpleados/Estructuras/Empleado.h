#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "../Librerias/Edad.h"
#include "../Multilistas/MultilistaHijos/MultilistaHijo.h"
#include <string>

struct Empleado {
    //int pk;
    //int fk;

    std::string nombre;
    std::string apellido;
    std::string tipoIdentificacion;
    std::string numIdentificacion;
    char sexo;
    std::string telefonoCelular;
    std::string telefonoFijo;
    std::string email;

    std::string ciudadNacimiento;
    std::string paisNacimiento;
    std::string ciudadResidencia;
    std::string direccion;
    //
    char tieneHijos;
    std::string actividadLaboral;
    std::string sucursalTrabajo;
    std::string barrio;
    int numHijos;
    std::string fechaNacimiento;
    bool estado;
    MultilistaHijo* hijos;
    int edad;


    // Estas variable se inicializan con 0 para evitar doble asignacion
    // Con estas se va manejar la posicion del siguiente dato segun la caracteristica de este
    int sigSexo{-1};
    int sigActividadLaboral{-1};
    int sigEdad{-1};
    int sigNombreSurcursal{-1};
    int sigCiudadNacimiento{-1};
    int sigBarrio{-1};
    int sigNumHijos{-1};

    Empleado() : nombre(""),
                 apellido(""),
                 tipoIdentificacion(""),
                 numIdentificacion(""),
                 sexo('\0'),
                 telefonoCelular(""),
                 telefonoFijo(""),
                 email(""),
                 ciudadNacimiento(""),
                 paisNacimiento(""),
                 ciudadResidencia(""),
                 direccion(""),
                 tieneHijos('\0'),
                 actividadLaboral(""),
                 sucursalTrabajo(""),
                 barrio(""),
                 numHijos(0),
                 fechaNacimiento(""),
                 estado(true),
                 edad(0) ,
                 hijos(nullptr){}

    // Constructor para inicializar los datos de un empleado
    Empleado(std::string nombre,
             std::string apellido,
             std::string tipoIdentificacion,
             std::string numIdentificacion,
             char sexo,
             std::string telefonoCelular,
             std::string telefonoFijo,
             std::string email,
             std::string ciudadNacimiento,
             std::string paisNacimiento,
             std::string ciudadResidencia,
             std::string direccion,
             char tieneHijos,
             std::string actividadLaboral,
             std::string sucursalTrabajo,
             std::string barrio,
             int numHijos,
             std::string fechaNacimiento)
        : nombre(std::move(nombre)),
          apellido(std::move(apellido)),
          tipoIdentificacion(std::move(tipoIdentificacion)),
          numIdentificacion(std::move(numIdentificacion)),
          sexo(sexo),
          telefonoCelular(std::move(telefonoCelular)),
          telefonoFijo(std::move(telefonoFijo)),
          email(std::move(email)),
          ciudadNacimiento(std::move(ciudadNacimiento)),
          paisNacimiento(std::move(paisNacimiento)),
          ciudadResidencia(std::move(ciudadResidencia)),
          direccion(std::move(direccion)),
          tieneHijos(tieneHijos),
          actividadLaboral(std::move(actividadLaboral)),
          sucursalTrabajo(std::move(sucursalTrabajo)),
          barrio(std::move(barrio)),
          numHijos(numHijos),
          fechaNacimiento(std::move(fechaNacimiento)),
          estado(true){

        edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));
    }
};


#endif
