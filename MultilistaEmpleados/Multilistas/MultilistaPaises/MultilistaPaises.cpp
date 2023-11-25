#include "MultilistaPaises.h"

MultilistaPaises::MultilistaPaises(int max)
{
    paises = new Pais[max];

    posLibre = 0;

    size = 0;
}

void MultilistaPaises::AgregarPais(std::string nombre)
{

    Pais pais(nombre);
    pais.ciudades = new MultilistaCiudad(20);

    posLibre++;
    size++;
}

void MultilistaPaises::EliminarPais(int indiceArray)
{
    paises[indiceArray].estado = false;
    size--;
}

void MultilistaPaises::ModificarPais(int num, std::string  nuevoDato, int indiceArray)
{
    if(num==1)
    {
        paises[indiceArray].nombre = nuevoDato;
    }
}