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
    indiceActividadLaboral = 0;

    CSexo[0] = {'M',-1};
    CSexo[1] = {'F',-1};

    //Un arbol para manejar la actividad laboral
    //Realmente no lo veo tan necesario, como maximo se agrerán
    CActividadLaboral[0] = {"",-1};
    arbolActividad = new RBTree<std::string,int>();
}

void Multilista::AgregarEmpleado(Empleado empleado)
{
    empleados[posLibre] = std::move(empleado);


    //Cabecera por Sexo
    // Ya organiza por sexo
    int indiceSexo = (empleados[posLibre].sexo == 'M')? 0:1;


    if(CSexo[indiceSexo].indice == -1)
        CSexo[indiceSexo].indice = posLibre;
    else
    {
        int indice = CSexo[indiceSexo].indice;

        while(empleados[indice].sigSexo != -1)
            indice = empleados[indice].sigSexo;

        empleados[indice].sigSexo = posLibre;
    }

    //Cabecera Actividad Laboral
    int indiceC = 0;
    if(CActividadLaboral[indiceActividadLaboral].atributo != "")
    {
        CActividadLaboral[indiceActividadLaboral].atributo = empleados[posLibre].actividadLaboral;
        CActividadLaboral[indiceActividadLaboral].indice = posLibre;
        arbolActividad->Insert(arbolActividad,arbolActividad->createNodo(empleados[posLibre].actividadLaboral,indiceActividadLaboral));
        indiceActividadLaboral++;
    } else {
        std::cout<<arbolActividad->findNodo(empleados[posLibre].actividadLaboral)<<std::endl;
        if(arbolActividad->findNodo(empleados[posLibre].actividadLaboral)!= nullptr)
        {
            indiceC = CActividadLaboral[arbolActividad->findNodo(empleados[posLibre].actividadLaboral)->otroDato].indice;
            while(empleados[indiceC].sigActividadLaboral != -1)
                indiceC = empleados[indiceC].sigActividadLaboral;

            empleados[indiceC].sigActividadLaboral = posLibre;
        }else{
            CActividadLaboral[indiceActividadLaboral].atributo = empleados[posLibre].actividadLaboral;
            CActividadLaboral[indiceActividadLaboral].indice = posLibre;
            arbolActividad->Insert(arbolActividad,arbolActividad->createNodo(empleados[posLibre].actividadLaboral,indiceActividadLaboral));
            indiceActividadLaboral++;
        }

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

void Multilista::ImprimirActividad(std::string actividad) {
    int indiceCabecera = arbolActividad->findNodo(std::move(actividad))->otroDato;
    int indice = CActividadLaboral[indiceCabecera].indice;

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].sexo << std::endl;
        std::cout << empleados[indice].actividadLaboral<< std::endl;
        indice = empleados[indice].sigActividadLaboral;
    }
}