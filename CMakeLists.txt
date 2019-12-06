cmake_minimum_required(VERSION 3.15)
project(MICajero)

set(CMAKE_CXX_STANDARD 17)

add_executable(MICajero main.cpp CCajero.cpp CCajero.h CProducto.cpp CProducto.h Variables.h CMenu.cpp CMenu.h)