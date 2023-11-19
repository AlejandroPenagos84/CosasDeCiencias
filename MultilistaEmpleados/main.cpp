#include <iostream>
#include "Empleado.h"
#include "Multilista.h"
int main() {
    // Crear un objeto Empleado con nombre y sexo inicializados
    Empleado empleadoInicializado1{
             "Juan",
             'M',
             "Artes"
    };

    Empleado empleadoInicializado2{
            "Maria",
            'F',
            "Ingenieria"
    };

    Empleado empleadoInicializado3{
            "Carlos",
            'M',
            "Matematicas"
    };

    Empleado empleadoInicializado4{
            "Janeth",
            'F',
            "Artes"
    };

    Empleado empleadoInicializado5{
            "Marcelo",
            'M',
            "Artes"
    };

    Multilista multilista(6);

    multilista.AgregarEmpleado(empleadoInicializado1);
    multilista.AgregarEmpleado(empleadoInicializado2);
    multilista.AgregarEmpleado(empleadoInicializado3);
    multilista.AgregarEmpleado(empleadoInicializado4);
    multilista.AgregarEmpleado(empleadoInicializado5);

    multilista.ImprimirActividad("Artes");
    // Imprimir los valores para verificar

    return 0;
}
