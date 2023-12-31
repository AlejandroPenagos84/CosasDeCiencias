#include "Estructuras/Empleado.h"
#include "Multilistas/MultilistaEmpleados/MultilistaEmpleados.h"
#include "Multilistas/MultilistaHijos/MultilistaHijo.h"
#include <iostream>

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


    Empleado empleado2{
            "Maria",
            'F',
            "Ciudad1",
            "Matematicas",
            "Sucursal2",
            "Barrio2",
            1,
            "21/12/2002"
    };


    Empleado empleado3{
            "Carlos",
            'M',
            "Ciudad1",
            "Artes",
            "Sucursal3",
            "Barrio3",
            1,
            "21/12/2003"
    };


    Empleado empleado4{
            "Janeth",
            'F',
            "Ciudad1",
            "Artes",
            "Sucursal4",
            "Barrio4",
            1,
            "21/12/2004"
    };



    Empleado empleado5{
            "Marcelo",
            'M',
            "Ciudad1",
            "Artes",
            "Sucursal5",
            "Barrio5",
            1,
            "21/12/2005"
    };


    MultilistaEmpleados multilista(6);

    multilista.AgregarEmpleado(empleado1);
    multilista.AgregarEmpleado(empleado2);
    multilista.AgregarEmpleado(empleado3);
    multilista.AgregarEmpleado(empleado4);
    multilista.AgregarEmpleado(empleado5);

    multilista.ModificarCategoria(1,4,4);

    multilista.ImprimirEmpleadosPorNumHijos(3,4);

    return 0;
}
