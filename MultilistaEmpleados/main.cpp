#include <iostream>
#include "Empleado.h"
#include "Multilista.h"
#include "MultilistaHijo.h"

int main() {
    /*
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

    std::cout<<multilista.getNumEmpleados()<<std::endl;


    */
    MultilistaHijo multilistaHijo(6);
    Hijo hijoInicializado1{
            "Hijo1",
            "21/12/2000"
    };

    Hijo hijoInicializado2{
            "Hijo2",
            "21/12/2009"
    };

    Hijo hijoInicializado3{
            "Hijo3",
            "21/12/2012"
    };

    Hijo hijoInicializado4{
            "Hijo4",
            "21/12/2013"
    };

    Hijo hijoInicializado5{
            "Hijo5",
            "21/12/2015"
    };

    multilistaHijo.AgregarHijo(hijoInicializado1);
    multilistaHijo.AgregarHijo(hijoInicializado2);
    multilistaHijo.AgregarHijo(hijoInicializado3);
    multilistaHijo.AgregarHijo(hijoInicializado4);
    multilistaHijo.AgregarHijo(hijoInicializado5);

    multilistaHijo.ImprimirEdad(6,10);
    // Imprimir los valores para verificar

    return 0;
}
