#include "lancoltlista.h"
#include "fajlkezelofuggvenyek.h"

/*Ez a fuggveny felelos azert, hogy letrejojjon a lancolt lista*/
Jaratoklista *beolvasas(void) {

    char sor[1000];
    /*A File *fp pointerrel megnyitasra erul a fo szoveges fajl, amibol beolvasunk*/
        FILE *fp = fopen("jaratok.txt", "r");
    /*HA nem sikerul megnyitni, akkor exit code 2*/
        if(fp == NULL) {
        exit(2);
        }
    /*Ez valtozoban eltaroljuk a fajlsorok szamat. 1-et meg hozzaadunk, mivel a ciklusban a valtozo 0-tol indul*/
        int osszes = fajlsorok_szama()+1;

        int idx = 0;

    /*A lista kezdo pointere*/
        Jaratoklista *lista = NULL;

        for (int i = 0; i < osszes; i++) {
    /*A fajbol beolvasodik az i.edik sor, majd a while ciklus megszamolja, hogy az elso '#' karakterig hany karakter van*/
            fgets(sor, 1000, fp);

                while(sor[idx]!='#') {
                    idx++;
                }
                /*A lista uj elemenek letrehozasa*/
                Jaratoklista *uj;

                /*A lista elemenek lefoglalunk egy megfelelo meretu memoriateruletet*/
                uj = (Jaratoklista*) malloc(sizeof(Jaratoklista));
                /*Ha nem sikerul a foglalas, akkor exit code 1*/
                if(uj==NULL) {
                exit(1);
                }
            /*Lefoglalasra kerul a lancolt lista megfelelo elemehez tartozo nev sztringnek a memoriaterulet. A sztring a jarat nevet fogja tartalmazni*/
            uj->nev = (char*) malloc((idx+1) * sizeof(char));

            /*Ha nem sikerul a memoriateruletet lefoglalni, akkor exit code 1*/
            if(uj->nev==NULL) {
            exit(1);
            }

            /*Lefoglalasra kerul a lista megfelelo elemehez tartozo foglalas sztringnek is a memoriaterulet. A sztring a jarat foglalasi terkepet fogja tartalmazni*/
            uj->foglalas = (char*) malloc(91 * sizeof(char));

            /*Ha nem sikerul a memoriateruletet lefoglalni, akkor exit code 1*/
            if(uj->foglalas == NULL) {
            exit(1);
            }

            /*Beolvasodik a sorbol a dinamikusan lefoglalt sztringekbe a megfelelo tartalom. Elso '#' karakterig jarat neve, majd a foglalasi terkep*/
            sscanf(sor, "%[^#]#%90[^#]", uj->nev, uj->foglalas);

            /*A listaelemhez tartozo jaratszam valtozoba bekerul a jaratnak a szama*/
            uj->jaratszam = i + 1;
            /*Itt zajlik a lista felepitese*/
            uj->kov = lista;
            lista = uj;
            /*Kinullazodik az idx valtozo, hogy a ciklusban a kovetkezo sor beolvasasanal is mukodjon a jarat nevenek a beolvasasa es a memoriafoglalas*/
            idx = 0;
        }
    /*Bezarodik a szoveges fajl*/
    fclose(fp);
    /*A fuggveny visszater a lancolt listaval*/
    return lista;
}


/*Ez a fuggveny felelos azert, hogy a konzolos feluleten a fomenuben az elso valasztas eseten kiirodjon a lancolt listaban tarolt osszes jaratszam + jaratnev*/
void listanev_kiir(Jaratoklista *eleje) {

    /*Ha elert a vegere, akkor return*/
    if(eleje == NULL)
        return;

    /*A fuggveny addig hivja meg sajat magat, amig a lancolt lista vegere nem er*/
    listanev_kiir(eleje->kov);

    /*A fuggveny kiirja az elso elemet, majd a tovabbiakat*/
    printf("%d %s\n", eleje->jaratszam, eleje->nev);
}


/*A fuggveny felelos azert, hogy megkeresse a lancolt listaban azt az elemet, melynek a megfelelo parametere megegyezik azzal a szammal, amit atadtunk a fuggvenynek*/
Jaratoklista *listaban_keres(Jaratoklista *eleje, int szam) {

    Jaratoklista *mozgo;
    /*A ciklus vegigmegy a lancolt listan az elso elemtol*/
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
        /*Ha a lancolt listanak az adott elemehez tartozo jaratszam megegyezik a fuggvenynek parameterkent atadott szammal*/
        if (mozgo->jaratszam == szam) {
            /*adja vissza azt a listaelemet*/
            return mozgo;
        }
    }
    /*NULL-t returnol, ha a ciklus nem talalta meg*/
    return NULL;
}


/*A fuggveny felelos a listaelemhez tartozo foglalasi terkep megfelelo kirajzolasaert*/
void kirajzol_foglalas(Jaratoklista *eleje) {

    char c='A';
    /*Kiirodik a konzolos feluletre az oszlopszam*/
                for(int i=0; i<6; i++) {
                    printf("%d", i+1);
                    }
    printf("\n");
    //Majd kiirasra kerul soronkent a foglalasi terkep: 15 sor es 6 szek
                for(int i = 0; i < 15; i++) {
                        for(int z = 0; z < 6; z++) {
                            //Ha az adott hely foglalt,akkor +, ha nem akkor -
                        printf("%c", eleje->foglalas[(i*6)+z] & 1 ? 'X' : '+');     //i*6+z = sorok szama*6+ules szama a sorban balrol
                        }
                        //Kiirodik a sorhoz tartozo karakter
                printf(" %c", c);
                printf("\n");
                //Noveljuk a karakternek az erteket, igy pl A-bol B lesz
                c++;
                }
}

//Felszabaditja a lista elemeit es az azokban dinamikusan foglalt sztringeket
void lista_felszabadit(Jaratoklista *eleje) {
    //Raallit egy pointert a lista elejere
    Jaratoklista *mozgo = eleje;
    //Amig nem er a vegere
    while (mozgo != NULL) {
        //Raallit egy pointert a lista kovetkezo elemere
        Jaratoklista *kov = mozgo->kov;
        //Felszabaditja a lista elemeben dinamikusan foglalt elemeket
                free(mozgo->nev);
                free(mozgo->foglalas);
                free(mozgo);
        //Tovabblep a kovetkezo listaelemre
        mozgo = kov;
    }
}
