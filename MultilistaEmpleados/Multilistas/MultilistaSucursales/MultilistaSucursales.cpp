#include "MultilistaSucursales.h"

#include <utility>

MultilistaSucursales::MultilistaSucursales(int max)
{
    // Inicializar el arreglo de sucursales
    sucursales = new Sucursal[max];

    posLibre = 0;
    size = 0;
}

void MultilistaSucursales::AgregarSucursal(std::string nombre,
                                           std::string direccion,
                                           std::string barrio,
                                           std::string nombreGerente)
{
    Sucursal sucursal(nombre,
                      direccion,
                      barrio,
                      nombreGerente);

    sucursal.empleados = new MultilistaEmpleados(40);

    sucursales[posLibre] = sucursal;

    posLibre++;
    size++;
}

void MultilistaSucursales::EliminarSucursal(int indiceArray)
{
    sucursales[indiceArray].estado = false;
    size--;
}

void MultilistaSucursales::ModificarSucursal(int num, std::string nuevoDato,int indiceArray)
{
    switch (num) {
        case 1:
            sucursales[indiceArray].nombre = std::move(nuevoDato);
            break;
        case 2:
            sucursales[indiceArray].direccion = std::move(nuevoDato);
            break;
        case 3:
            sucursales[indiceArray].barrio = std::move(nuevoDato);
            break;
        case 4:
            sucursales[indiceArray].nombreGerente = std::move(nuevoDato);
            break;
        default:
            break;
    }
}