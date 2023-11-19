cmake_minimum_required(VERSION 3.26)
project(MultilistaEmpleados)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultilistaEmpleados main.cpp
        Empleado.h
        Multilista.h
        Multilista.cpp
        Librerias/Arbol.h
        Librerias/Cola.h
        Librerias/Cola.h)
