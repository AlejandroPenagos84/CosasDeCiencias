#include "Multilista.h"
#include "iostream"
#include <utility>

Multilista::Multilista(int max) {
    empleados = new Empleado[max];
    CSexo = new Cabecera<char>[2];
    CActividadLaboral = new Cabecera<std::string>[max];
    CNumeroHijos = new Cabecera<std::string>[4];
    CBarrio = new Cabecera<std::string>[max];
    CEdad = new Cabecera<int>[5];
    CCiudadNacimiento = new Cabecera<std::string>[max];
    CSucursal = new Cabecera<std::string >[max];

    // Inicializar Posicion Libre
    posLibre = 0;

    // Inicializar Indices
    indiceActividadLaboral = 0;
    indiceCiudadNacimiento = 0;
    indiceBarrio = 0;
    indiceSucursal = 0;
  //Inicializar Arreglos
    //Cabecera para organizar por sezo
    CSexo[0] = {'M',-1};
    CSexo[1] = {'F',-1};


    //Cabecera para organizar los atributos que tengan string
    CActividadLaboral[0] = {"",-1};
    CCiudadNacimiento[0] = {"",-1};
    CBarrio[0] = {"",-1};
    CSucursal[0] = {"",-1};

    //Cabecera para organizar por numeros
    CNumeroHijos[0] = {"Sin Hijos",-1};
    CNumeroHijos[1] = {"1 a 2",-1};
    CNumeroHijos[2] = {"3 a 4",-1};
    CNumeroHijos[3] = {"Mas de 4",-1};

    // Inicializar Arboles
    arbolActividad = new RBTree<std::string,int>();
    arbolCiudadNacimiento = new RBTree<std::string,int>();
    arbolBarrio = new RBTree<std::string,int>();
    arbolSucursales = new RBTree<std::string,int>();
}

void Multilista::AgregarEmpleado(Empleado empleado)
{
    empleados[posLibre] = std::move(empleado);

    //Organizar Por Sexo
    OrganizarSexo();
    //Organizar Actividad Laboral
    OrganizarPorAtributo(arbolActividad,
                         CActividadLaboral,
                         &Empleado::actividadLaboral,
                         indiceActividadLaboral,
                         &Empleado::sigActividadLaboral);

    //Organizar por ciudad de nacimiento
    OrganizarPorAtributo(arbolCiudadNacimiento,
                         CCiudadNacimiento,
                         &Empleado::ciudadNacimiento,
                         indiceCiudadNacimiento,
                         &Empleado::sigCiudadNacimiento);

    //Organizar por Barrio
    OrganizarPorAtributo(arbolBarrio,
                         CBarrio,
                         &Empleado::barrio,
                         indiceBarrio,
                         &Empleado::sigBarrio);


    //Organizar Por nombre De Sucursales
    OrganizarPorAtributo(arbolSucursales,
                         CSucursal,
                         &Empleado::sucursalTrabajo,
                         indiceSucursal,
                         &Empleado::sigNombreSurcursal);

    OrganizarNumeroHijos();
    posLibre++;
}

void Multilista::OrganizarSexo()
{
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
}

void Multilista::OrganizarPorAtributo(
        RBTree<std::string,int>*& arbol,
        Cabecera<std::string>*& cabecera,
        std::string Empleado::*atributo,
        int& indiceAtributo,
        int Empleado::*sigAtributo)
{
    int indiceC = 0;
    if (arbol->findNodo(empleados[posLibre].*atributo) != nullptr)
    {
        indiceC = cabecera[arbol->findNodo(empleados[posLibre].*atributo)->otroDato].indice;
        while (empleados[indiceC].*sigAtributo != -1)
            indiceC = empleados[indiceC].*sigAtributo;
        empleados[indiceC].*sigAtributo = posLibre;
    }
    else
    {
        cabecera[indiceAtributo].atributo = empleados[posLibre].*atributo;
        cabecera[indiceAtributo].indice = posLibre;
        arbol->Insert(arbol, arbol->createNodo(empleados[posLibre].*atributo, indiceAtributo));
        indiceAtributo++;
    }
}

void Multilista::ImprimirSexo(char sexo)
{
    int indiceSexo = (sexo == 'M') ? 0 : 1;

    int indice = CSexo[indiceSexo].indice;

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].sexo << std::endl;
        indice = empleados[indice].sigSexo;
    }
}

void Multilista::ImprimirActividad(std::string ciudad) {

    if(arbolCiudadNacimiento->findNodo((ciudad))!= nullptr)
    {
        int indiceCabecera = arbolCiudadNacimiento->findNodo(std::move(ciudad))->otroDato;
        int indice = CCiudadNacimiento[indiceCabecera].indice;

        while (indice != -1) {
            std::cout << empleados[indice].nombre << std::endl;
            std::cout << empleados[indice].sexo << std::endl;
            std::cout << empleados[indice].ciudadNacimiento<< std::endl;
            indice = empleados[indice].sigCiudadNacimiento;
        }
    }else
    {
        std::cout<<"NO EXISTE"<<std::endl;
    }

}

void Multilista::OrganizarNumeroHijos() {
    int numHijos = empleados[posLibre].numHijos;
    int indiceCabecera;

    if (numHijos == 0)
        indiceCabecera = 0;
    else if (numHijos >= 1 && numHijos <= 2)
        indiceCabecera = 1;
    else if (numHijos >= 3 && numHijos <= 4)
        indiceCabecera = 2;
    else
        indiceCabecera = 3;

    if (CNumeroHijos[indiceCabecera].indice == -1) {
        CNumeroHijos[indiceCabecera].indice = posLibre;
    } else {
        int indiceC = CNumeroHijos[indiceCabecera].indice;
        while (empleados[indiceC].sigNumHijos != -1)
            indiceC = empleados[indiceC].sigNumHijos;

        empleados[indiceC].sigNumHijos = posLibre;
    }
}

void Multilista::ImprimirEmpleadosPorNumHijos(int rangoInicio, int rangoFin) {
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

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].sexo << std::endl;
        std::cout << empleados[indice].ciudadNacimiento << std::endl;
        std::cout << empleados[indice].numHijos << std::endl;
        indice = empleados[indice].sigNumHijos;
    }
}
