#ifndef MULTILISTAEMPLEADOS_MULTILISTACIUDAD_H
#define MULTILISTAEMPLEADOS_MULTILISTACIUDAD_H
#include "../../Estructuras/Ciudad.h"

class MultilistaCiudad {
private:
    Ciudad* ciudades;

    int posLibre;
    int size;

public:
    explicit MultilistaCiudad(int max);
    void AgregarCiudad(std::string nombre);
    void EliminarCiudad(int indiceArray);
    void ModificarCiudad(int num, std::string  nuevoDato, int indiceArray);
};


#endif//MULTILISTAEMPLEADOS_MULTILISTACIUDAD_H
