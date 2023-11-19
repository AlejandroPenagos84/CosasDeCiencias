#include "Multilista.h"
#include "iostream"
#include <utility>

Multilista::Multilista(int max) {
    empleados = new Empleado[max];
    CSexo = new Cabecera<char>[2];
    CActividadLaboral = new Cabecera<std::string>[max];
    CNumeroHijos = new Cabecera<int>[4];
    CLocalidad = new Cabecera<std::string>[max];
    CEdad = new Cabecera<int>[5];
    CCiudadNacimiento = new Cabecera<std::string>[max];

    posLibre = 0;

    CSexo[0] = {'M',-1};
    CSexo[1] = {'F',-1};

    RBTree<char,int> arbolActividad;//Un arbol para manejar la actividad laboral
    //Realmente no lo veo tan necesario, como maximo se agrerán

}

void Multilista::AgregarEmpleado(Empleado empleado)
{
    empleados[posLibre] = std::move(empleado);

    int indiceSexo = (empleados[posLibre].sexo == 'M')? 0:1;
    //Cabecera por Sexo
    // Ya organiza por sexo

    if(CSexo[indiceSexo].indice == -1)
    {
            CSexo[indiceSexo].indice = posLibre;
            empleados[posLibre].sigSexo = -1;
    }
    else
    {
        int indice = CSexo[indiceSexo].indice;

        while(empleados[indice].sigSexo != -1)
            indice = empleados[indice].sigSexo;

        empleados[indice].sigSexo = posLibre;
        empleados[posLibre].sigSexo = -1;
    }
    posLibre++;
}


void Multilista::ImprimirSexo(char sexo) {
    int indiceSexo = (sexo == 'M') ? 0 : 1;

    int indice = CSexo[indiceSexo].indice;

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].sexo << std::endl;
        indice = empleados[indice].sigSexo;
    }
}