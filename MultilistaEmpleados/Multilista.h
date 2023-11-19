#ifndef MULTILISTAEMPLEADOS_MULTILISTA_H
#define MULTILISTAEMPLEADOS_MULTILISTA_H
#include "Empleado.h"
#include "Librerias/Arbol.h"
#include "Librerias/Cabecera.h"


class Multilista {
    private:
        Empleado* empleados;

        // Arreglos de Cabeceras
        Cabecera<char>* CSexo;
        Cabecera<std::string>* CActividadLaboral;
        Cabecera<std::string>* CCiudadNacimiento;
        Cabecera<std::string>* CBarrio;
        Cabecera<std::string>* CSucursal;
        Cabecera<std::string>* CNumeroHijos;
        Cabecera<std::string>* CEdad;

        // PosicionLibre
        int posLibre;

        //Indices de las cabeceras donde se manejan datos tipo string
        int indiceActividadLaboral;
        int indiceCiudadNacimiento;
        int indiceBarrio;
        int indiceSucursal;


        // Arboles para los datos tipo string, estos arboles sirven para que en caso de que alguna
        // de los arreglos de cabecera se largo, la busqueda sea optima, en caso de que toque agregar otro elemento
        // a la cabecera o buscar uno que ya se encuentre

        //(Siento que se gasta mas memoria pero asi es más optimo en caso de que las cabecera se vuelvan
        // muy grandes)

        //Aunque ni tanto, pq si solo se agrega un dato a la cabecera, se usará un solo nodo del arbol :v
        RBTree<std::string ,int>* arbolActividad;
        RBTree<std::string ,int>* arbolCiudadNacimiento;
        RBTree<std::string, int>* arbolBarrio;
        RBTree<std::string, int>* arbolSucursales;

    public:
    // Estos son los método publicos, quiza lo haga mas tarde u otro dia, pero tratare de hacer
    // el imprimir mas generico o en caso de que sea necesario entregar una cola o pila o lista,
    // sobretodo al momento de buscar, asi se hará mas chevere y sencillo para las consultas

        explicit Multilista(int);
        void AgregarEmpleado(Empleado);
        int getNumEmpleados() const;
        void ImprimirSexo(char);
        void ImprimirActividad(std::string);
        void ImprimirEmpleadosPorNumHijos(int,int);

    private:
    // Estos son los métodos privado con los que organizo la informacion en la multilista
        void OrganizarSexo();
        void OrganizarPorAtributo(  RBTree<std::string,int>*&,
                                    Cabecera<std::string>*&,
                                    std::string Empleado::*,
                                    int&,
                                    int Empleado::*);
        void OrganizarNumeroHijos();
        void OrganizarEdad();
};
#endif //MULTILISTAEMPLEADOS_MULTILISTA_H
