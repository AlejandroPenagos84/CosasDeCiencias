#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

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
    //std::string fechaNacimiento;
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
    //int edad;

    int sigSexo{-1};
    int sigActividadLaboral{-1};
   // int numeroDeHijos{-1};
   // int sigEdad{-1};
    int sigNombreSurcursal{-1};
    int sigCiudadNacimiento{-1};
    int sigBarrio{-1};
    int sigNumHijos{-1};
};



#endif

