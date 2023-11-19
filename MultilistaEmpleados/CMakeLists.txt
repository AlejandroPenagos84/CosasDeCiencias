cmake_minimum_required(VERSION 3.26)
project(MultilistaEmpleados)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultilistaEmpleados main.cpp
        Estructuras/Empleado.h
        Multilistas/MultilistaEmpleados.h
        Multilistas/MultilistaEmpleados.cpp
        Librerias/Arbol.h
        Librerias/Cola.h
        Librerias/Cola.h
        Librerias/Edad.h
        Estructuras/Hijo.h
        Multilistas/MultilistaHijo.h
        Multilistas/MultilistaHijo.cpp
        Librerias/Cabecera.h)
