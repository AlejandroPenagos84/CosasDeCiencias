#ifndef MULTILISTAEMPLEADOS_MULTILISTA_H
#define MULTILISTAEMPLEADOS_MULTILISTA_H
#include "Empleado.h"
#include "Librerias/Arbol.h"
template<class T>
struct Cabecera{
    T atributo;
    int indice;
};

class Multilista {
    private:
        Empleado* empleados;

        // Arreglos de Cabeceras
        Cabecera<char>* CSexo;
        Cabecera<std::string>* CBarrio;
        Cabecera<std::string>* CActividadLaboral;
        Cabecera<int>* CEdad;
        Cabecera<std::string>* CNumeroHijos;
        Cabecera<std::string>* CSucursal;
        Cabecera<std::string>* CCiudadNacimiento;


        // PosicionLibre
        int posLibre;

        //Indices de las cabeceras
        int indiceActividadLaboral;
        int indiceCiudadNacimiento;
        int indiceBarrio;
        int indiceSucursal;


        // Arboles
        RBTree<std::string ,int>* arbolActividad;
        RBTree<std::string ,int>* arbolCiudadNacimiento;
        RBTree<std::string, int>* arbolBarrio;
        RBTree<std::string, int>* arbolSucursales;
    public:
        Multilista(int);
        void AgregarEmpleado(Empleado);
        void ImprimirSexo(char);
        void ImprimirActividad(std::string);
        void ImprimirEmpleadosPorNumHijos(int,int);

    private:
        void OrganizarSexo();
        void OrganizarPorAtributo(  RBTree<std::string,int>*&,
                                    Cabecera<std::string>*&,
                                    std::string Empleado::*,
                                    int&,
                                    int Empleado::*);
        void OrganizarNumeroHijos();
};


#endif //MULTILISTAEMPLEADOS_MULTILISTA_H
