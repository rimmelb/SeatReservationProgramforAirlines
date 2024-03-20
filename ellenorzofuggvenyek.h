#ifndef NAGYHF_ELLENORZOFUGGVENYEK_H
#define NAGYHF_ELLENORZOFUGGVENYEK_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "debugmalloc.h"
#include "lancoltlista.h"

bool szovegbeolvaso_fuggvenyek_ellenoriz(char *a);
int terkepkeres_ellenorzo(Jaratoklista *eleje);
int valasztasellenorzo();
int jaratellenorzo();
int ujfoglalasellenorzo();
int szuletesievellenorzo();
int szuletesihonapellenorzo();
int szuletesinapellenorzo();
int menuellenorzo();
char *ulohelyellenorzo();
char *szemelyiigellenorzo();
bool jaratnev_compare(Jaratoklista *eleje, char *jaratnev);


#endif //NAGYHF_ELLENORZOFUGGVENYEK_H
