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
        Cabecera<std::string>* CLocalidad;
        Cabecera<std::string>* CActividadLaboral;
        Cabecera<int>* CEdad;
        Cabecera<int>* CNumeroHijos;
        Cabecera<std::string>* {}CSucursal;
        Cabecera<std::string>* CCiudadNacimiento;

        //Variable que servira
        int posLibre;
    public:
        Multilista(int);
        void AgregarEmpleado(Empleado);
        void ImprimirSexo(char);

};


#endif //MULTILISTAEMPLEADOS_MULTILISTA_H
