#include "MultilistaEmpleados.h"

//Probablemente le cambie el nombre de esta clase en un futuro

void MultilistaEmpleados::ImprimirSexo(char sexo) {
    int indiceSexo = (sexo == 'M') ? 0 : 1;

    int indice = CSexo[indiceSexo].indice;

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].sexo << std::endl;
        indice = empleados[indice].sigSexo;
    }
}

void MultilistaEmpleados::ImprimirActividad(std::string ciudad) {

    if (arbolCiudadNacimiento->findNodo((ciudad)) != nullptr) {
        int indiceCabecera = arbolCiudadNacimiento->findNodo(std::move(ciudad))->otroDato;
        int indice = CCiudadNacimiento[indiceCabecera].indice;


        while (indice != -1) {
            std::cout << empleados[indice].nombre << std::endl;
            std::cout << empleados[indice].sexo << std::endl;
            std::cout << empleados[indice].ciudadNacimiento << std::endl;
            indice = empleados[indice].sigCiudadNacimiento;
        }
    } else {
        std::cout << "NO EXISTE" << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << empleados[i].nombre << std::endl;
        std::cout << empleados[i].ciudadNacimiento << std::endl;
        std::cout << empleados[i].sigCiudadNacimiento << std::endl;
    }
}

void MultilistaEmpleados::ImprimirEmpleadosPorNumHijos(int rangoInicio, int rangoFin) {
    int indiceCabecera;

    if (rangoInicio == 0) {
        indiceCabecera = 0;
    } else if (rangoInicio >= 1 && rangoFin <= 2) {
        indiceCabecera = 1;
    } else if (rangoInicio >= 3 && rangoFin <= 4) {
        indiceCabecera = 2;
    } else {
        std::cout << "RANGO INVALIDO" << std::endl;
        return;
    }

    int indice = CNumeroHijos[indiceCabecera].indice;
    /*
    for(int i = 0; i < 5; i++)
    {
        std::cout << empleados[i].nombre << std::endl;
        std::cout << empleados[i].numHijos<<std::endl;
    }*/

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].numHijos << std::endl;
        indice = empleados[indice].sigNumHijos;
    }
}
