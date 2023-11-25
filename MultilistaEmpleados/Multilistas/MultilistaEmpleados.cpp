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
    CSucursal = new Cabecera<std::string>[max];
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
    CSexo[0] = {'M', -1};
    CSexo[1] = {'F', -1};


    //Cabecera para organizar los atributos que tengan string
    CActividadLaboral[0] = {"", -1};
    CCiudadNacimiento[0] = {"", -1};
    CBarrio[0] = {"", -1};
    CSucursal[0] = {"", -1};

    //Cabecera para organizar por numero de hijos
    CNumeroHijos[0] = {"Sin Hijos", -1};
    CNumeroHijos[1] = {"1 a 2", -1};
    CNumeroHijos[2] = {"3 a 4", -1};
    CNumeroHijos[3] = {"Mas de 4", -1};

    //Cabecera para edad
    CEdad[0] = {"18 a 24", -1};
    CEdad[1] = {"25 a 35", -1};
    CEdad[2] = {"36 a 45", -1};
    CEdad[3] = {"46 a 60", -1};
    CEdad[4] = {"Mas de 60", -1};

    //Inicializar Sentinelas

    // Inicializar Arboles
    arbolActividad = new RBTree<std::string, int>();
    arbolCiudadNacimiento = new RBTree<std::string, int>();
    arbolBarrio = new RBTree<std::string, int>();
    arbolSucursales = new RBTree<std::string, int>();
}

/**
 * Aqui se agrega un empleado a lista e invoco todos los metodo privados para organizar los datos
 * @param empleado Empleado
 */
void MultilistaEmpleados::AgregarEmpleado(Empleado empleado) {
    empleados[posLibre] = std::move(empleado);

    //Organizar Por Sexo
    OrganizarSexo(posLibre);

    //Organizar Actividad Laboral
    Reorganizar(
            arbolActividad,
            CActividadLaboral,
            &Empleado::actividadLaboral,
            indiceActividadLaboral,
            &Empleado::sigActividadLaboral,
            posLibre);

    //Organizar por ciudad de nacimiento
    Reorganizar(arbolCiudadNacimiento,
                CCiudadNacimiento,
                &Empleado::ciudadNacimiento,
                indiceCiudadNacimiento,
                &Empleado::sigCiudadNacimiento,
                posLibre);

    //Organizar por Barrio
    Reorganizar(arbolBarrio,
                CBarrio,
                &Empleado::barrio,
                indiceBarrio,
                &Empleado::sigBarrio,
                posLibre);


    //Organizar Por nombre De Sucursales
    Reorganizar(arbolSucursales,
                CSucursal,
                &Empleado::sucursalTrabajo,
                indiceSucursal,
                &Empleado::sigNombreSurcursal,
                posLibre);

    // Organizar Por Numero de Hijos
    OrganizarCategoria(CNumeroHijos,
                       posLibre,
                       &Empleado::sigNumHijos,
                       getCabeceraNumHijos(posLibre));

    //Organizar Por edad
    OrganizarCategoria(CEdad,
                       posLibre,
                       &Empleado::sigEdad,
                       getCabeceraEdad(posLibre));


    posLibre++;
    size++;
}

/**
 * Metodo publico donde se modifica un atributo de los string
 * @param num
 * @param nuevoDato
 * @param indice
 */
void MultilistaEmpleados::ModificarAtributo(int num,
                                            std::string &nuevoDato,
                                            int indice) {

    switch (num) {

        case 1:// 1 Actividad Laboral
            CambiarAtributo(arbolActividad,
                            &Empleado::actividadLaboral,
                            nuevoDato,
                            &Empleado::sigActividadLaboral,
                            CActividadLaboral,
                            indice,
                            arbolActividad->findNodo(empleados[indice].actividadLaboral)->otroDato,
                            indiceActividadLaboral);
            break;

        case 2:// 2 Ciudad Nacimiento
            CambiarAtributo(arbolCiudadNacimiento,
                            &Empleado::ciudadNacimiento,
                            nuevoDato,
                            &Empleado::sigCiudadNacimiento,
                            CCiudadNacimiento,
                            indice,
                            arbolCiudadNacimiento->findNodo(empleados[indice].ciudadNacimiento)->otroDato,
                            indiceCiudadNacimiento);
            break;

        case 3:// 3 Barrio
            CambiarAtributo(arbolBarrio, &Empleado::barrio,
                            nuevoDato,
                            &Empleado::sigBarrio,
                            CBarrio, indice,
                            arbolBarrio->findNodo(empleados[indice].barrio)->otroDato,
                            indiceBarrio);
            break;

        case 4:// 4 Sucursales
            CambiarAtributo(arbolSucursales,
                            &Empleado::sucursalTrabajo,
                            nuevoDato,
                            &Empleado::sigNombreSurcursal,
                            CSucursal,
                            indice,
                            arbolSucursales->findNodo(empleados[indice].sucursalTrabajo)->otroDato,
                            indiceSucursal);

        default:// En caso de que se ingrese otro numero
            break;
    }
}

/**
 * Metodo publico donde se modifica un atributo de las categorias
 * @param num
 * @param valor
 * @param indice
 */
void MultilistaEmpleados::ModificarCategoria(int num, int valor, int indice) {
    switch (num) {
        case 1:
            CambiarCategoria(CNumeroHijos,
                             &Empleado::numHijos,
                             valor,
                             &Empleado::sigNumHijos,
                             indice,
                             getCabeceraNumHijos(empleados[indice].numHijos),
                             &MultilistaEmpleados::getCabeceraNumHijos);
            break;

        case 2:
            CambiarCategoria(CEdad,
                             &Empleado::edad,
                             valor,
                             &Empleado::sigEdad,
                             indice,
                             getCabeceraEdad(empleados[indice].edad),
                             &MultilistaEmpleados::getCabeceraEdad);
            break;

        default:
            break;
    }
}

void MultilistaEmpleados::ModificarS(int num, int indice, std::string nuevoDato)
{
    switch (num) {
        case 1:
            CambiarS(&Empleado::nombre,indice,std::move(nuevoDato));
            break;

        case 2:
            CambiarS(&Empleado::apellido,indice,std::move(nuevoDato));
            break;

        case 3:
            CambiarS(&Empleado::tipoIdentificacion,indice,std::move(nuevoDato));
            break;

        case 4:
            CambiarS(&Empleado::numIdentificacion,indice,std::move(nuevoDato));
            break;

        case 5:
            CambiarS(&Empleado::telefonoCelular,indice,std::move(nuevoDato));
            break;

        case 6:
            CambiarS(&Empleado::telefonoFijo,indice,std::move(nuevoDato));
            break;

        case 7:
            CambiarS(&Empleado::email,indice,std::move(nuevoDato));
            break;

        case 8:
            CambiarS(&Empleado::paisNacimiento,indice,std::move(nuevoDato));
            break;

        case 9:
            CambiarS(&Empleado::ciudadResidencia,indice,std::move(nuevoDato));
            break;

        case 10:
            CambiarS(&Empleado::direccion,indice,std::move(nuevoDato));
            // Procesar direccion
            break;

        default:
            // Opción por defecto, si no coincide con ninguna de las anteriores
            break;
    }

}

void MultilistaEmpleados::ModificarC(int num, int indice, char nuevoDato) {
    switch (num) {
        case 1:
            CambiarC(&Empleado::sexo, indice, (nuevoDato));
            break;

        case 2:
            CambiarC(&Empleado::tieneHijos, indice, nuevoDato);
            break;
        default:
            break;
    }
}

void MultilistaEmpleados::CambiarS(std::string Empleado::*atributo, int indiceArray, std::string nuevoDato)
{
    empleados[indiceArray].*atributo = std::move(nuevoDato);
}

void MultilistaEmpleados::CambiarC(char Empleado::*atributo, int indiceArray, char nuevoDato)
{
    empleados[indiceArray].*atributo = nuevoDato;
}

void MultilistaEmpleados::OrganizarSexo(int indiceArrayEmpleado) {
    int indiceSexo = (empleados[indiceArrayEmpleado].sexo == 'M') ? 0 : 1;


    if (CSexo[indiceSexo].indice == -1)
        CSexo[indiceSexo].indice = indiceArrayEmpleado;
    else {
        int indice = CSexo[indiceSexo].indice;

        while (empleados[indice].sigSexo != -1)
            indice = empleados[indice].sigSexo;

        empleados[indice].sigSexo = indiceArrayEmpleado;
    }
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

        empleados[indiceCabecera].*siguienteAtributo = indiceArray;
    } else {
        cabecera[indiceAtributo].atributo = empleados[indiceArray].*atributo;
        cabecera[indiceAtributo].indice = indiceArray;
        arbol->Insert(arbol, arbol->createNodo(empleados[indiceArray].*atributo,
                                               indiceAtributo));
        indiceAtributo++;
    }
}

void MultilistaEmpleados::OrganizarCategoria(
        Cabecera<std::string> *&cabecera,
        int indiceArray,
        int Empleado::*siguienteIndice,
        int indiceCabecera) {

    if (cabecera[indiceCabecera].indice == -1) {
        cabecera[indiceCabecera].indice = indiceArray;
    } else {
        int indiceC = cabecera[indiceCabecera].indice;
        while (empleados[indiceC].*siguienteIndice != -1)
            indiceC = empleados[indiceC].*siguienteIndice;

        empleados[indiceC].*siguienteIndice = indiceArray;
    }
}

void MultilistaEmpleados::CambiarAtributo(
        RBTree<std::string, int> *&arbol,// Arbol del atributo
        std::string Empleado::*atributo, // Puntero al atributo
        std::string nuevoValor,          // Valor del nuevo atributo
        int Empleado::*siguienteIndice,  // Puntero al siguiente índice
        Cabecera<std::string> *&cabecera,// Cabecera
        int indiceArrayEmpleado,         // Posición del empleado en el array
        int indiceCabecera,              // Índice de la cabecera
        int &nuevoAtributoIndice         // Índice que hace referencia a los índices de las
                                         // cabeceras
) {
    int indiceAnterior;
    int indiceSiguiente;
    int indiceArreglo = cabecera[indiceCabecera].indice;

    indiceAnterior = indiceArreglo;
    indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;

    while (indiceArreglo != indiceArrayEmpleado) {
        indiceAnterior = indiceArreglo;
        indiceArreglo = empleados[indiceArreglo].*siguienteIndice;
        indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;
    }


    empleados[indiceArrayEmpleado].*atributo = std::move(nuevoValor);

    if (indiceArreglo == cabecera[indiceCabecera].indice)
        cabecera[indiceCabecera].indice = indiceSiguiente;
    else
        empleados[indiceAnterior].*siguienteIndice = indiceSiguiente;

    if (cabecera[indiceCabecera].indice == -1) {
        nuevoAtributoIndice--;
        cabecera[indiceCabecera].atributo = "";
    }

    Reorganizar(arbol,
                cabecera,
                atributo,
                nuevoAtributoIndice,
                siguienteIndice,
                indiceArrayEmpleado);
}

void MultilistaEmpleados::CambiarCategoria(Cabecera<std::string> *&cabecera,
                                           int Empleado::*atributo,
                                           int valor,
                                           int Empleado::*siguienteIndice,
                                           int indiceArray,
                                           int indiceCabeceraAntigua,
                                           int (MultilistaEmpleados::*getCabecera)(int)) {
    int indiceAnterior;
    int indiceSiguiente;
    int indiceArreglo = cabecera[indiceCabeceraAntigua].indice;

    indiceAnterior = indiceArreglo;
    indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;

    while (indiceArreglo != indiceArray) {
        indiceAnterior = indiceArreglo;
        indiceArreglo = empleados[indiceArreglo].*siguienteIndice;
        indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;
    }

    empleados[indiceArray].*atributo = valor;

    if (indiceArreglo == cabecera[indiceCabeceraAntigua].indice)
        cabecera[indiceCabeceraAntigua].indice = indiceSiguiente;
    else {
        empleados[indiceArreglo].*siguienteIndice = indiceSiguiente;
    }

    OrganizarCategoria(cabecera,
                       indiceArray,
                       siguienteIndice,
                       (this->*getCabecera)(indiceArray));
}


int MultilistaEmpleados::getCabeceraNumHijos(int indiceArray) {
    int numHijos = empleados[indiceArray].numHijos;
    int indiceCabecera;

    if (numHijos == 0)
        indiceCabecera = 0;
    else if (numHijos <= 2)
        indiceCabecera = 1;
    else if (numHijos <= 4)
        indiceCabecera = 2;
    else
        indiceCabecera = 3;


    return indiceCabecera;
}

int MultilistaEmpleados::getCabeceraEdad(int indiceArray) {
    int edad = empleados[indiceArray].edad;
    int indiceCabecera;

    if (edad >= 18 && edad <= 24)
        indiceCabecera = 0;
    else if (edad >= 25 && edad <= 35)
        indiceCabecera = 1;
    else if (edad >= 36 && edad <= 45)
        indiceCabecera = 2;
    else if(edad >=46 && edad<=60)
        indiceCabecera = 3;
    else
        indiceCabecera = 4;

    return indiceCabecera;

}

int MultilistaEmpleados::getNumEmpleados() const { return size; }

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
