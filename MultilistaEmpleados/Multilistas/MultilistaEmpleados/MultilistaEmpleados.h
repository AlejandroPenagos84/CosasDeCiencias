#ifndef MULTILISTAEMPLEADOS_H
#define MULTILISTAEMPLEADOS_H
#include "../../Estructuras/Empleado.h"
#include "../../Librerias/Arbol.h"
#include "../../Librerias/Cabecera.h"

class MultilistaEmpleados {
private:
    Empleado *empleados;

    // Arreglos de Cabeceras
    Cabecera<char> *CSexo;
    Cabecera<std::string> *CActividadLaboral;
    Cabecera<std::string> *CCiudadNacimiento;
    Cabecera<std::string> *CBarrio;
    Cabecera<std::string> *CSucursal;
    Cabecera<std::string> *CNumeroHijos;
    Cabecera<std::string> *CEdad;

    // PosicionLibre
    int posLibre;

    // Indices de las cabeceras donde se manejan datos tipo string
    int indiceActividadLaboral;
    int indiceCiudadNacimiento;
    int indiceBarrio;
    int indiceSucursal;

    // Size
    int size;
    // Arboles para los datos tipo string, estos arboles sirven para que en caso
    // de que alguna de los arreglos de cabecera se largo, la busqueda sea optima,
    // en caso de que toque agregar otro elemento a la cabecera o buscar uno que
    // ya se encuentre

    //(Siento que se gasta mas memoria pero asi es más optimo en caso de que las
    //cabecera se vuelvan
    // muy grandes)

    // Aunque ni tanto, pq si solo se agrega un dato a la cabecera, se usará un
    // solo nodo del arbol :v
    RBTree<std::string, int> *arbolActividad;
    RBTree<std::string, int> *arbolCiudadNacimiento;
    RBTree<std::string, int> *arbolBarrio;
    RBTree<std::string, int> *arbolSucursales;

public:
    // Estos son los método publicos, quiza lo haga mas tarde u otro dia, pero
    // tratare de hacer el imprimir mas generico o en caso de que sea necesario
    // entregar una cola o pila o lista, sobretodo al momento de buscar, asi se
    // hará mas chevere y sencillo para las consultas

    explicit MultilistaEmpleados(int);

    //Metodo para agregar un empleado
    void AgregarEmpleado(Empleado);

    //Metodos para modificar atributos de un empleado
    void ModificarAtributo(int,  std::string &, int);
    void ModificarCategoria(int num, int valor, int indice);
    void ModificarS(int num,int indice, std::string nuevoDato);
    void ModificarC(int num,int indice, char nuevoDato);

    //Metodo para obtener el tamaño del arreglo
    int getNumEmpleados() const;

    //Metodos para imprimir datos
    void ImprimirSexo(char);
    void ImprimirActividad(std::string);
    void ImprimirEmpleadosPorNumHijos(int, int);

    //Metodo para eliminar dato
    void Eliminar(int indiceArray);

private:
    // Estos son los métodos privado con los que organizo la informacion en la
    // multilista

    // Método Simples con los que se organizarán los datos
    void OrganizarSexo(int indiceArrayEmpleado);

    void Reorganizar(RBTree<std::string, int> *&arbol,
                     Cabecera<std::string> *&cabecera,
                     std::string Empleado::*atributo,
                     int &indiceAtributo,
                     int Empleado::*siguienteAtributo,
                     int indiceArray);

    void OrganizarCategoria(Cabecera<std::string> *&cabecera,
                            int indiceArray,
                            int Empleado::*siguienteIndice,
                            int indiceCabecera);

    // Metodos para cambiar un atributo, se usa para poder reubicarlo en la lista de cabeceras
    void CambiarAtributo(
            RBTree<std::string, int> *&arbol,// Arbol del atributo
            std::string Empleado::*atributo, // Puntero al atributo
            std::string nuevoValor,          // Valor del nuevo atributo
            int Empleado::*siguienteIndice,  // Puntero al siguiente índice
            Cabecera<std::string> *&cabecera,// Cabecera
            int indiceArrayEmpleado,         // Posición del empleado en el array
            int indiceCabecera,              // Índice de la cabecera
            int &nuevoAtributoIndice);       // Índice que hace referencia a los índices de las
                                             //cabecera
    void CambiarCategoria(
            Cabecera<std::string> *&cabecera,//Cabecera del atributo
            int Empleado::*atributo,         //Atributo que se cambiará
            int valor,
            int Empleado::*siguienteIndice,// Indice del atributo que se cambiará
            int indiceArray,
            int indiceCabeceraAntigua,
            int (MultilistaEmpleados::*getCabecera)(int));

    //Tambien hace de la parte de los metodos de cambiar, solo cambian el atributo
    void CambiarS(std::string Empleado::*atributo, int indiceArray, std::string nuevoDato);
    void CambiarC(char  Empleado::*atributo, int indiceArray, char nuevoDato);

    //Getters que permiten generalizar la obtencion del indice de la cabecera según un rango dado
    int getCabeceraNumHijos(int indiceArray);
    int getCabeceraEdad(int indiceArray);
};

#endif
