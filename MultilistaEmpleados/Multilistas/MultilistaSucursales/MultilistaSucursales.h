
#ifndef MULTILISTAEMPLEADOS_MULTILISTASUCURSALES_H
#define MULTILISTAEMPLEADOS_MULTILISTASUCURSALES_H
#include "../../Estructuras/Sucursal.h"

class MultilistaSucursales {

private:
    Sucursal* sucursales;

    int posLibre;
    int size;

public:
    explicit MultilistaSucursales(int max);
    void AgregarSucursal(std::string nombre,
                         std::string direccion,
                         std::string barrio,
                         std::string nombreGerente);

    void EliminarSucursal(int indiceArray);
    void ModificarSucursal(int num, std::string nuevoDato,int indiceArray);
};


#endif//MULTILISTAEMPLEADOS_MULTILISTASUCURSALES_H
