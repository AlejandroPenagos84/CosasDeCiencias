
#ifndef MULTILISTAHIJO_H
#define MULTILISTAHIJO_H
#include "Hijo.h"
#include "Librerias/Cabecera.h"

class MultilistaHijo {
    private:
        Hijo* hijos;
        int posLibre;
        Cabecera<std::string>* CEdad;

    public:
        explicit MultilistaHijo(int);
        void AgregarHijo(Hijo);
        void ImprimirEdad(int,int);

    private:
        void OrganizarEdad();

};


#endif
