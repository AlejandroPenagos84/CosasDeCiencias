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


void MultilistaEmpleados::Eliminar(int indiceArray) {
    empleados[indiceArray].estado = false;
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

