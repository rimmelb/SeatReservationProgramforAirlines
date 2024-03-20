#ifndef FAJLKEZELOFUGGVENYEK_H
#define FAJLKEZELOFUGGVENYEK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lancoltlista.h"
#include "nevbeolvasofuggvenyek.h"
#include "ellenorzofuggvenyek.h"
#include "debugmalloc.h"
#include "utasbeolvaso.h"

int fajlsorok_szama();
void menuk_kiir();
void jarathozzaad(Jaratoklista *eleje);
void jaratokfajlba_atir();
void kiegfajlt_atir(Jaratoklista *eleje, Utas *a);
#endif
