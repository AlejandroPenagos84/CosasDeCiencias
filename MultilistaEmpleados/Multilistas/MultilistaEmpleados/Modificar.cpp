#include "MultilistaEmpleados.h"

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
