#include <iostream>
#include "Estructuras/Empleado.h"
#include "Multilistas/MultilistaEmpleados.h"
#include "Multilistas/MultilistaHijo.h"

int main() {

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

    // Imprimir los valores para verificar

    MultilistaEmpleados Empleados(6);
    // Crear un objeto Empleado con nombre y sexo inicializados
    Empleado empleado1{
            "Juan",
            'M',
            "Ciudad1",
            "Ingles",
            "Sucursal1",
            "Barrio1",
            1,
            "21/12/2001",

    };
    empleado1.hijos.AgregarHijo(hijoInicializado1);

    Empleado empleado2{
            "Maria",
            'F',
            "Ciudad2",
            "Matematicas",
            "Sucursal2",
            "Barrio2",
            1,
            "21/12/2002"
    };
    empleado2.hijos.AgregarHijo(hijoInicializado2);

    Empleado empleado3{
            "Carlos",
            'M',
            "Ciudad3",
            "Artes",
            "Sucursal3",
            "Barrio3",
            1,
            "21/12/2003"
    };
    empleado3.hijos.AgregarHijo(hijoInicializado3);

    Empleado empleado4{
            "Janeth",
            'F',
            "Ciudad4",
            "Artes",
            "Sucursal4",
            "Barrio4",
            1,
            "21/12/2004"
    };

    empleado4.hijos.AgregarHijo(hijoInicializado4);

    Empleado empleado5{
            "Marcelo",
            'M',
            "Ciudad5",
            "Artes",
            "Sucursal5",
            "Barrio5",
            1,
            "21/12/2005"
    };
    empleado5.hijos.AgregarHijo(hijoInicializado5);

    MultilistaEmpleados multilista(6);

    multilista.AgregarEmpleado(empleado1);
    multilista.AgregarEmpleado(empleado2);
    multilista.AgregarEmpleado(empleado3);
    multilista.AgregarEmpleado(empleado4);
    multilista.AgregarEmpleado(empleado5);

    multilista.ImprimirActividad("Ciudad5");

    return 0;
}
