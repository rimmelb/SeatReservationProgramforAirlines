cmake_minimum_required(VERSION 3.23)
project(NAGYHF C)

set(CMAKE_C_STANDARD 99)

add_executable(NAGYHF main.c fajlkezelofuggvenyek.h utasbeolvaso.h fejleckiiro.h datumellenorzo.h utasbeolvaso.c fajlkezelofuggvenyek.c fejleckiiro.c datumellenorzo.c lancoltlista.h lancoltlista.c ellenorzofuggvenyek.c ellenorzofuggvenyek.h nevbeolvasofuggvenyek.c nevbeolvasofuggvenyek.h)


