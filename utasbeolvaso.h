#ifndef UTASBEOLVASO_H
#define UTASBEOLVASO_H

#include <stdio.h>
#include <string.h>

#include "ellenorzofuggvenyek.h"
#include "lancoltlista.h"
#include "debugmalloc.h"

typedef struct Utas {
    char *nev;
    int nap;
    int ev;
    int honap;
    int menu;
    char *szemelyiig;
    int jaratszam;
    char *ulohely;
}Utas;

int ertekke(char *a);

void felszabaditas(Utas *a);

Utas beolvas(Jaratoklista *eleje);


#endif