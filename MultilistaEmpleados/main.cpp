#include <iostream>
#include "Empleado.h"
#include "Multilista.h"
int main() {
    // Crear un objeto Empleado con nombre y sexo inicializados
    Empleado empleadoInicializado1{
            "Juan",
            'M',
            "Ciudad1",
            "Ingles",
            "Sucursal1",
            "Barrio1",
            1,
            "21/12/2001"
    };

    Empleado empleadoInicializado2{
            "Maria",
            'F',
            "Ciudad2",
            "Matematicas",
            "Sucursal2",
            "Barrio2",
            1,
            "21/12/2002"
    };

    Empleado empleadoInicializado3{
            "Carlos",
            'M',
            "Ciudad3",
            "Artes",
            "Sucursal3",
            "Barrio3",
            1,
            "21/12/2003"
    };

    Empleado empleadoInicializado4{
            "Janeth",
            'F',
            "Ciudad4",
            "Artes",
            "Sucursal4",
            "Barrio4",
            1,
            "21/12/2004"
    };

    Empleado empleadoInicializado5{
            "Marcelo",
            'M',
            "Ciudad5",
            "Artes",
            "Sucursal5",
            "Barrio5",
            1,
            "21/12/2005"
    };

    Multilista multilista(6);

    multilista.AgregarEmpleado(empleadoInicializado1);
    multilista.AgregarEmpleado(empleadoInicializado2);
    multilista.AgregarEmpleado(empleadoInicializado3);
    multilista.AgregarEmpleado(empleadoInicializado4);
    multilista.AgregarEmpleado(empleadoInicializado5);

    multilista.ImprimirEmpleadosPorNumHijos(1,2);
    // Imprimir los valores para verificar

    return 0;
}
