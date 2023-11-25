#include "MultilistaCiudad.h"

MultilistaCiudad::MultilistaCiudad(int max)
{
    ciudades = new Ciudad[max];

    posLibre = 0;

    size = 0;
}

void MultilistaCiudad::AgregarCiudad(std::string nombre)
{
    Ciudad ciudad(nombre);
    ciudad.sucursales = new MultilistaSucursales(20);

    posLibre++;
    size++;
}

void MultilistaCiudad::EliminarCiudad(int indiceArray)
{
    ciudades[indiceArray].estado = false;
    size--;
}

void MultilistaCiudad::ModificarCiudad(int num, std::string  nuevoDato, int indiceArray)
{
    if(num==1)
    {
        ciudades[indiceArray].nombre = nuevoDato;
    }
}