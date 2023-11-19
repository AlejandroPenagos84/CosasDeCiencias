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
    //std::string ciudadNacimiento;
    //std::string paisNacimiento;
    //std::string ciudadResidencia;
    //std::string direccion;
    //std::string barrio;
    //char tieneHijos;
    std::string actividadLaboral;
    //int numHijos;
    //std::string sucursalTrabajo;
    //int edad;

    //int sigLocalidad{-1};
    int sigSexo{-1};
    int sigActividadLaboral{-1};
   // int numeroDeHijos{-1};
   // int sigEdad{-1};
    //int nombreSurcursal{-1};
};



#endif

