#ifndef MULTILISTAEMPLEADOS_MULTILISTAPAISES_H
#define MULTILISTAEMPLEADOS_MULTILISTAPAISES_H
#include "../../Estructuras/Pais.h"

class MultilistaPaises {
private:
    Pais* paises;

    int posLibre;
    int size;

public:
    explicit MultilistaPaises(int max);
    void AgregarPais(std::string nombre);
    void EliminarPais(int indiceArray);
    void ModificarPais(int num, std::string nuevoDato, int indiceArray);
};


#endif
