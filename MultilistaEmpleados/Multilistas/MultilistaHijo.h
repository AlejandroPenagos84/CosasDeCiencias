#ifndef MULTILISTAHIJO_H
#define MULTILISTAHIJO_H
#include "../Estructuras/Hijo.h"
#include "../Librerias/Cabecera.h"

class MultilistaHijo {
private:
    Hijo *hijos;
    int posLibre;
    Cabecera<std::string> *CEdad;
    int size;

public:
    explicit MultilistaHijo(int);
    void AgregarHijo(Hijo);
    void ImprimirEdad(int, int);

private:
    void OrganizarEdad();
};

#endif
