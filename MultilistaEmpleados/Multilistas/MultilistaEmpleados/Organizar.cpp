#include "MultilistaEmpleados.h"

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