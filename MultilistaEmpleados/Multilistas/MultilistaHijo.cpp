#include "MultilistaHijo.h"

#include <utility>

MultilistaHijo::MultilistaHijo(int max) {
    // Inicializar arreglo de hijo
    hijos = new Hijo[max];

    // Cabecera de edades
    CEdad = new Cabecera<std::string>[4];


    //Posicion Libre
    posLibre = 0;

    //Incializar Cabecera de esades
    CEdad[0] = {"0 a 5",-1};
    CEdad[1] = {"6 a 10",-1};
    CEdad[2] = {"11 a 18",-1};
    CEdad[3] = {"Mas de 18",-1};
}


void MultilistaHijo::AgregarHijo(Hijo hijo) {
    hijos[posLibre] = std::move(hijo);
    OrganizarEdad();
    posLibre++;
}

void MultilistaHijo::OrganizarEdad()
{
    int edad = hijos[posLibre].edad;
    int indiceCabecera = (edad >= 0 && edad <= 5) ? 0 : ((edad >= 6 && edad <= 10) ? 1 : ((edad >= 11 && edad <= 18) ? 2 : 3));


    if (CEdad[indiceCabecera].indice == -1) {
        CEdad[indiceCabecera].indice = posLibre;
    } else {
        int indiceC = CEdad[indiceCabecera].indice;
        while (hijos[indiceC].sigEdad != -1)
            indiceC = hijos[indiceC].sigEdad;

        hijos[indiceC].sigEdad = posLibre;
    }
}

void MultilistaHijo::ImprimirEdad(int edad1, int edad2) {
    int indiceCabecera;

    if (edad1 >= 0 && edad2 <= 5) {
        indiceCabecera = 0;
    } else if (edad1 >= 6 && edad2 <= 10) {
        indiceCabecera = 1;
    } else if (edad1 >= 11 && edad2 <= 18) {
        indiceCabecera = 2;
    } else if (edad1 >18 && edad2>=edad1){
        indiceCabecera = 3;
    }else {
        std::cout << "RANGO INVALIDO" << std::endl;
        return;
    }

    int indice = CEdad[indiceCabecera].indice;
    while (indice != -1) {
        std::cout << hijos[indice].nombre << std::endl;
        std::cout << hijos[indice].edad<< std::endl;
        indice = hijos[indice].sigEdad;
    }
}