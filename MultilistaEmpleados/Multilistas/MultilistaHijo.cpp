#include "MultilistaHijo.h"
#include <iostream>
#include <utility>

MultilistaHijo::MultilistaHijo(int max) {
    // Inicializar arreglo de hijo
    hijos = new Hijo[max];

    // Cabecera de edades
    CEdad = new Cabecera<std::string>[4];

    // Posicion Libre
    posLibre = 0;

    //size
    size = 0;

    // Incializar Cabecera de esades
    CEdad[0] = {"0 a 5", -1};
    CEdad[1] = {"6 a 10", -1};
    CEdad[2] = {"11 a 18", -1};
    CEdad[3] = {"Mas de 18", -1};
}

void MultilistaHijo::AgregarHijo(Hijo hijo) {
    hijos[posLibre] = std::move(hijo);
    OrganizarCategoria(CEdad,
                       posLibre,
                       &Hijo::sigEdad,
                       getCabeceraEdad(posLibre));
    posLibre++;
    size++;
}

void MultilistaHijo::ModificarCategoria(int num, int valor, int indice) {
    if (num == 1) {
        CambiarCategoria(CEdad,
                         &Hijo::edad,
                         valor,
                         &Hijo::sigEdad,
                         indice,
                         getCabeceraEdad(hijos[indice].edad),
                         &MultilistaHijo::getCabeceraEdad);
    }
}

void MultilistaHijo::OrganizarCategoria(Cabecera<std::string> *&cabecera,
                                        int indiceArray,
                                        int Hijo::*siguienteIndice,
                                        int indiceCabecera) {

    if (cabecera[indiceCabecera].indice == -1) {
        cabecera[indiceCabecera].indice = indiceArray;
    } else {
        int indiceC = cabecera[indiceCabecera].indice;
        while (hijos[indiceC].*siguienteIndice != -1)
            indiceC = hijos[indiceC].*siguienteIndice;

        hijos[indiceC].*siguienteIndice = indiceArray;
    }
}

void MultilistaHijo::CambiarCategoria(Cabecera<std::string> *&cabecera,
                                      int Hijo::*atributo,
                                      int valor,
                                      int Hijo::*siguienteIndice,
                                      int indiceArray,
                                      int indiceCabeceraAntigua,
                                      int (MultilistaHijo::*getCabecera)(int)) {
    int indiceAnterior;
    int indiceSiguiente;
    int indiceArreglo = cabecera[indiceCabeceraAntigua].indice;

    indiceAnterior = indiceArreglo;
    indiceSiguiente = hijos[indiceArreglo].*siguienteIndice;

    while (indiceArreglo != indiceArray) {
        indiceAnterior = indiceArreglo;
        indiceArreglo = hijos[indiceArreglo].*siguienteIndice;
        indiceSiguiente = hijos[indiceArreglo].*siguienteIndice;
    }

    hijos[indiceArray].*atributo = valor;

    if (indiceArreglo == cabecera[indiceCabeceraAntigua].indice)
        cabecera[indiceCabeceraAntigua].indice = indiceSiguiente;
    else {
        hijos[indiceArreglo].*siguienteIndice = indiceSiguiente;
    }

    OrganizarCategoria(cabecera,
                       indiceArray,
                       siguienteIndice,
                       (this->*getCabecera)(indiceArray));
}

int MultilistaHijo::getCabeceraEdad(int indiceArray) {
    int edad = hijos[indiceArray].edad;
    int indiceCabecera;

    if (edad >= 0 && edad <= 5)
        indiceCabecera = 0;
    else if (edad >= 6 && edad <= 10)
        indiceCabecera = 1;
    else if (edad >= 11 && edad <= 18)
        indiceCabecera = 2;
    else
        indiceCabecera = 3;

    return indiceCabecera;
}


void MultilistaHijo::ImprimirEdad(int edad1, int edad2) {
    int indiceCabecera;

    if (edad1 >= 0 && edad2 <= 5) {
        indiceCabecera = 0;
    } else if (edad1 >= 6 && edad2 <= 10) {
        indiceCabecera = 1;
    } else if (edad1 >= 11 && edad2 <= 18) {
        indiceCabecera = 2;
    } else if (edad1 > 18 && edad2 >= edad1) {
        indiceCabecera = 3;
    } else {
        std::cout << "RANGO INVALIDO" << std::endl;
        return;
    }

    int indice = CEdad[indiceCabecera].indice;
    while (indice != -1) {
        std::cout << hijos[indice].nombre << std::endl;
        std::cout << hijos[indice].edad << std::endl;
        indice = hijos[indice].sigEdad;
    }
}