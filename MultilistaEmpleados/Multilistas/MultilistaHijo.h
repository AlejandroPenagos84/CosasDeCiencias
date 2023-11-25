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
    void ModificarCategoria(int num, int valor, int indice);
    void ImprimirEdad(int, int);

private:
    void OrganizarCategoria(Cabecera<std::string> *&cabecera,
                            int indiceArray,
                            int Hijo::*siguienteIndice,
                            int indiceCabecera);

    void CambiarCategoria(
            Cabecera<std::string> *&cabecera,//Cabecera del atributo
            int Hijo::*atributo,             //Atributo que se cambiará
            int valor,
            int Hijo::*siguienteIndice,// Indice del atributo que se cambiará
            int indiceArray,
            int indiceCabeceraAntigua,
            int (MultilistaHijo::*getCabecera)(int));
    int getCabeceraEdad(int indiceArray);

};

#endif
