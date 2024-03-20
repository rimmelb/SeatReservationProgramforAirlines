#ifndef LANCOLTLISTA_H
#define LANCOLTLISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "debugmalloc.h"

typedef struct Jaratoklista {
    char *nev;
    int jaratszam;
    char *foglalas;
    struct Jaratoklista *kov;
}Jaratoklista;

Jaratoklista *beolvasas(void);

void listanev_kiir(Jaratoklista *eleje);

Jaratoklista *listaban_keres(Jaratoklista *eleje, int szam);

void kirajzol_foglalas(Jaratoklista *eleje);

void lista_felszabadit(Jaratoklista *eleje);


#endif
