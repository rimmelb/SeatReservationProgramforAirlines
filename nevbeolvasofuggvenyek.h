#ifndef NAGYHF_NEVBEOLVASOFUGGVENYEK_H
#define NAGYHF_NEVBEOLVASOFUGGVENYEK_H


#include <stdio.h>
#include <string.h>

#include "utasbeolvaso.h"
#include "fajlkezelofuggvenyek.h"
#include "lancoltlista.h"
#include "ellenorzofuggvenyek.h"
#include "debugmalloc.h"


char *menu_sztringkent(int a);
char *nevbeolvas();
char *jaratnevbeolvas(Jaratoklista *eleje);


#endif
