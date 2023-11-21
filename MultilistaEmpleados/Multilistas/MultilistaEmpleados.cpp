#include "MultilistaEmpleados.h"
#include "iostream"
#include <utility>

/**
 * En este constructor se inicializa todo, las cabeceras, los arboles y demás
 * @param max Tamaño maximo de los arreglos
 */
MultilistaEmpleados::MultilistaEmpleados(int max) {
    // Se inicializa el arreglo que va contener los empleados
    empleados = new Empleado[max];

    // Se inicializan los arreglos que serán las cabeceras por cada atributo
    CSexo = new Cabecera<char>[2];
    CActividadLaboral = new Cabecera<std::string>[max];
    CCiudadNacimiento = new Cabecera<std::string>[max];
    CBarrio = new Cabecera<std::string>[max];
    CSucursal = new Cabecera<std::string >[max];
    CNumeroHijos = new Cabecera<std::string>[4];
    CEdad = new Cabecera<std::string>[5];



    // Inicializar Posicion Libre
    posLibre = 0;


    //Inicializar Size
    size = 0;
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

    //Cabecera para organizar por numero de hijos
    CNumeroHijos[0] = {"Sin Hijos",-1};
    CNumeroHijos[1] = {"1 a 2",-1};
    CNumeroHijos[2] = {"3 a 4",-1};
    CNumeroHijos[3] = {"Mas de 4",-1};

    //Cabecera para edad
    CEdad[0] = {"18 a 24",-1};
    CEdad[1] = {"25 a 35",-1};
    CEdad[2] = {"36 a 45",-1};
    CEdad[3] = {"46 a 60",-1};
    CEdad[4] = {"Mas de 60",-1};


    // Inicializar Arboles
    arbolActividad = new RBTree<std::string,int>();
    arbolCiudadNacimiento = new RBTree<std::string,int>();
    arbolBarrio = new RBTree<std::string,int>();
    arbolSucursales = new RBTree<std::string,int>();
}

/**
 * Aqui se agrega un empleado a lista e invoco todos los metodo privados para organizar los datos
 * @param empleado Empleado
 */
void MultilistaEmpleados::AgregarEmpleado(Empleado empleado)
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

    // Organizar Por Numero de Hijos
    OrganizarNumeroHijos();

    //Organizar Por edad
    OrganizarEdad();
    posLibre++;
    size++;
}

void MultilistaEmpleados::OrganizarSexo()
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

void MultilistaEmpleados::OrganizarPorAtributo(
        RBTree<std::string,int>*& arbol,
        Cabecera<std::string>*& cabecera,
        std::string Empleado::*atributo,
        int& indiceAtributo,
        int Empleado::*sigAtributo)
{

    if (arbol->findNodo(empleados[posLibre].*atributo) != nullptr)
    {
        int indiceC = cabecera[arbol->findNodo(empleados[posLibre].*atributo)->otroDato].indice;
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

void MultilistaEmpleados::OrganizarNumeroHijos() {
    int numHijos = empleados[posLibre].numHijos;
    int indiceCabecera = (numHijos == 0) ? 0 : ((numHijos <= 2) ? 1 : ((numHijos <= 4) ? 2 : 3));

    if (CNumeroHijos[indiceCabecera].indice == -1) {
        CNumeroHijos[indiceCabecera].indice = posLibre;
    } else {
        int indiceC = CNumeroHijos[indiceCabecera].indice;
        while (empleados[indiceC].sigNumHijos != -1)
            indiceC = empleados[indiceC].sigNumHijos;

        empleados[indiceC].sigNumHijos = posLibre;
    }
}

void MultilistaEmpleados::OrganizarEdad() {
    int edad = empleados[posLibre].edad;
    int indiceCabecera;

    if (edad >= 18 && edad <= 24)  indiceCabecera = 0;
    else if (edad >= 25 && edad <= 35) indiceCabecera = 1;
    else if (edad >= 36 && edad <= 45) indiceCabecera = 2;
    else if (edad >= 46 && edad <= 60) indiceCabecera = 3;
    else indiceCabecera = 4;

    if (CEdad[indiceCabecera].indice == -1) {
        CEdad[indiceCabecera].indice = posLibre;
    } else {
        int indiceC = CEdad[indiceCabecera].indice;
        while (empleados[indiceC].sigEdad != -1)
            indiceC = empleados[indiceC].sigEdad;

        empleados[indiceC].sigEdad = posLibre;
    }
}

void MultilistaEmpleados::ModificarAtributo(int num,
                                            const std::string &nuevoDato,
                                            int indice) {
    // 1 Actividad Laboral
    if (num == 1)
        CambiarAtributo(arbolActividad,
                        &Empleado::actividadLaboral,
                        nuevoDato,
                        &Empleado::sigActividadLaboral,
                        CActividadLaboral,
                        indice,
                        arbolActividad->findNodo(empleados[indice].actividadLaboral)->otroDato,
                        indiceActividadLaboral);

        // 2 Ciudad Nacimiento
    else if (num == 2)
        CambiarAtributo(arbolCiudadNacimiento,
                        &Empleado::ciudadNacimiento,
                        nuevoDato,
                        &Empleado::sigCiudadNacimiento,
                        CCiudadNacimiento,
                        indice,
                        arbolCiudadNacimiento->findNodo(empleados[indice].ciudadNacimiento)->otroDato,
                        indiceCiudadNacimiento);

        // 3 Barrios
    else if (num == 3)
        CambiarAtributo(arbolBarrio, &Empleado::barrio,
                        nuevoDato,
                        &Empleado::sigBarrio,
                        CBarrio, indice,
                        arbolBarrio->findNodo(empleados[indice].barrio)->otroDato,
                        indiceBarrio);

        // 4 Sucursales
    else if (num == 4)
        CambiarAtributo(arbolSucursales,
                        &Empleado::sucursalTrabajo,
                        nuevoDato,
                        &Empleado::sigNombreSurcursal,
                        CSucursal,
                        indice,
                        arbolSucursales->findNodo(empleados[indice].sucursalTrabajo)->otroDato,
                        indiceSucursal);
}

void MultilistaEmpleados::CambiarAtributo(
        RBTree<std::string, int> *&arbol, // Arbol del atributo
        std::string Empleado::*atributo,  // Puntero al atributo
        std::string nuevoValor,           // Valor del nuevo atributo
        int Empleado::*siguienteIndice,   // Puntero al siguiente índice
        Cabecera<std::string> *&cabecera, // Cabecera
        int indiceArrayEmpleado,          // Posición del empleado en el array
        int indiceCabecera,               // Índice de la cabecera
        int &nuevoAtributoIndice // Índice que hace referencia a los índices de las
        // cabeceras
) {
    int indiceAnterior;
    int indiceSiguiente;
    int indiceArreglo = cabecera[indiceCabecera].indice;

    indiceAnterior = indiceArreglo;
    indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;

    while (indiceArreglo != indiceArrayEmpleado)
    {
        indiceAnterior = indiceArreglo;
        indiceArreglo = empleados[indiceArreglo].*siguienteIndice;
        indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;
    }


    empleados[indiceArrayEmpleado].*atributo = std::move(nuevoValor);

    if (indiceAnterior == cabecera[indiceCabecera].indice) {
        cabecera[indiceCabecera].indice = indiceSiguiente;
    } else {
        empleados[indiceAnterior].*siguienteIndice = indiceSiguiente;
    }

    Reorganizar(arbol,
                cabecera,
                atributo,
                nuevoAtributoIndice,
                siguienteIndice,
                indiceArrayEmpleado);
}

void MultilistaEmpleados::Reorganizar(RBTree<std::string, int> *&arbol,
                                      Cabecera<std::string> *&cabecera,
                                      std::string Empleado::*atributo,
                                      int &indiceAtributo,
                                      int Empleado::*siguienteAtributo,
                                      int indiceArray) {
    if (arbol->findNodo(empleados[indiceArray].*atributo) != nullptr) {
        int indiceCabecera =
                cabecera[arbol->findNodo(empleados[indiceArray].*atributo)->otroDato]
                        .indice;
        while (empleados[indiceCabecera].*siguienteAtributo != -1)
            indiceCabecera = empleados[indiceCabecera].*siguienteAtributo;
        empleados[indiceCabecera].*siguienteAtributo = posLibre;
    } else {
        cabecera[indiceAtributo].atributo = empleados[indiceArray].*atributo;
        cabecera[indiceAtributo].indice = indiceArray;
        arbol->Insert(arbol, arbol->createNodo(empleados[indiceArray].*atributo,
                                               indiceAtributo));
        indiceAtributo++;
    }
}

int MultilistaEmpleados::getNumEmpleados() const {return posLibre;}

void MultilistaEmpleados::ImprimirSexo(char sexo)
{
    int indiceSexo = (sexo == 'M') ? 0 : 1;

    int indice = CSexo[indiceSexo].indice;

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].sexo << std::endl;
        indice = empleados[indice].sigSexo;
    }
}

void MultilistaEmpleados::ImprimirActividad(std::string ciudad) {

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
/*
    for(int i = 0; i < 5; i++)
    {
        std::cout << empleados[i].nombre << std::endl;
        std::cout << empleados[i].ciudadNacimiento<< std::endl;
        std::cout << empleados[i].sigCiudadNacimiento<< std::endl;
    }*/
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

    while (indice != -1) {
        std::cout << empleados[indice].nombre << std::endl;
        std::cout << empleados[indice].sexo << std::endl;
        std::cout << empleados[indice].ciudadNacimiento << std::endl;
        std::cout << empleados[indice].numHijos << std::endl;
        std::cout << empleados[indice].edad<< std::endl;
        indice = empleados[indice].sigNumHijos;
    }
}
