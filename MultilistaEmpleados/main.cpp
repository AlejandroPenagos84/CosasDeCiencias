#include <iostream>
#include "Empleado.h"
#include "Multilista.h"
int main() {
    // Crear un objeto Empleado con nombre y sexo inicializados
    Empleado empleadoInicializado1{
             "Juan",
             'M',
    };

    Empleado empleadoInicializado2{
            "Maria",
            'F',
    };

    Empleado empleadoInicializado3{
            "Carlos",
            'M',
    };

    Empleado empleadoInicializado4{
            "Janeth",
            'F',
    };

    Empleado empleadoInicializado5{
            "Marcelo",
            'M',
    };

    Multilista multilista(6);

    multilista.AgregarEmpleado(empleadoInicializado1);
    multilista.AgregarEmpleado(empleadoInicializado2);
    multilista.AgregarEmpleado(empleadoInicializado3);
    multilista.AgregarEmpleado(empleadoInicializado4);
    multilista.AgregarEmpleado(empleadoInicializado5);

    multilista.ImprimirSexo('M');
    // Imprimir los valores para verificar

    return 0;
}
