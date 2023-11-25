cmake_minimum_required(VERSION 3.26)
project(MultilistaEmpleados)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultilistaEmpleados main.cpp
        Estructuras/Empleado.h
        Multilistas/MultilistaEmpleados/MultilistaEmpleados.h
        Multilistas/MultilistaEmpleados/MultilistaEmpleados.cpp
        Librerias/Arbol.h
        Librerias/Cola.h
        Librerias/Cola.h
        Librerias/Edad.h
        Estructuras/Hijo.h
        Multilistas/MultilistaHijos/MultilistaHijo.h
        Multilistas/MultilistaHijos/MultilistaHijo.cpp
        Librerias/Cabecera.h
        Multilistas/MultilistaEmpleados/Organizar.cpp
        Multilistas/MultilistaEmpleados/Modificar.cpp
        Multilistas/MultilistaEmpleados/Imprimir.cpp
        Estructuras/Sucursal.h
        Estructuras/Ciudad.h
        Estructuras/Pais.h
        Multilistas/MultilistaCiudades/MultilistaCiudad.h
        Multilistas/MultilistaPaises/MultilistaPaises.h
        Multilistas/MultilistaSucursales/MultilistaSucursales.h)
