#include <stdio.h>

#include "utasbeolvaso.h"
#include "fejleckiiro.h"
#include "fajlkezelofuggvenyek.h"
#include "lancoltlista.h"
#include "ellenorzofuggvenyek.h"
#include "debugmalloc.h"


int main(void) {
    /*létrehozásra kerül a láncolt listának a kezdő eleme.
     *A kezdő elemre meghívjuk a beolvasas függvényt, mellyel létrejön a jaratok.txt forrásfájlból a láncolt lista*/

    Jaratoklista *kezdo;
    Jaratoklista *terkep;

    kezdo = beolvasas();

    int valasztas, ujfoglalas, foglalaskereso;

    /*meghivjuk a fejlecetkiir függvényt, mely a RIMMAIR felirat megjelenítésére szolgál*/
    fejlecetkiir();

    printf("\nEz a RIMMAIR legitarsasag adatbazisa!\nMiben segithetunk Onnek?\n");

    /*Ez a do while ciklus szolgál a program alapjának, hiszen a fő funkciók ennek a segítségével érhetők el*/
    do {
        //Ellenorzi, hogy helyes bemenet erkezett-e a fomenuben valo valasztasra
        valasztas = valasztasellenorzo();

        switch (valasztas) {

            //4-es valasztas eseten megjelenitheto a jelenlegi osszes jarat
            case 4: printf("Jelenlegi jaratlista: \n");
                    listanev_kiir(kezdo);
                    break;

            //Az 5-os valasztasnal megtekintheto a felhasznalo altal valasztott jaratnak a foglalasi terkepe
            case 5:
                do{
                    foglalaskereso = terkepkeres_ellenorzo(kezdo);
                    terkep = listaban_keres(kezdo, foglalaskereso);
                    //Ha nem talalta meg a megadott jaratszam alapjan a lancolt listanak az elemet, akkor ujraindul a ciklus
                    if (terkep == NULL) {
                        printf("Helytelen bemenet! Probalja ujra!\n");
                    }
                }while(terkep==NULL);
                kirajzol_foglalas(terkep);
                break;

            /*A 6-os választás esetén a láncolt lista felszabadul a lista_felszabadit segedfuggveny segitsegevel és a program futása befejeződik.*/
            case 6:
                    printf("Koszonjuk latogatasat!\nSzep napot kivanunk!\nRIMMAIR Airlines\nAll Rights Reserved\n");
                    lista_felszabadit(kezdo);
                    return 0;
            /*Az egyes választás szolgál arra, hogy a felhasználó tudjon jegyet foglalni valamelyik jaratra, tovabba a megfelelo sorba elmentesre keruljon az utasnak az adata*/
            case 1:
                /*A do while ciklus arra szolgál, hogy amennyiben a felhasználó szeretné még helyet foglalni, akkor a procedúra újból fusson le.*/
                    do {
                        //Az utas adatai egy strukturaba olvasodnak be
                        Utas a = beolvas(kezdo);

                        //A segedfajlba atmasolodik az utas adataival kiegeszult forrasfajl
                        kiegfajlt_atir(kezdo, &a);

                        //A fofajlba atmasolodik a segedfajl
                        jaratokfajlba_atir();

                        //A lista felszabaditasra kerul
                        lista_felszabadit(kezdo);

                        //A strukturaban dinamikus foglalt sztringek felszabaditasra kerulnek
                        felszabaditas(&a);

                        //A lista ujbol beolvasodik
                        kezdo = beolvasas();
                        printf("Sikeres foglalas!\n");

                        /*A do while ciklus azt a célt szolgálja, hogy a felhasználó jó bemenetet adjon meg*/
                            do {
                                //az ujfoglalasellenorzovel kerul ellenorzesre, hogy a felhasznalo szam bemenetet adott-e meg
                                ujfoglalas = ujfoglalasellenorzo();
                                //Ha nem 2 vagy 1 a bemenet, akkor a ciklus ujraindul
                                        if (ujfoglalas > 2 || ujfoglalas < 1)
                                        printf("Helytelen valasz");
                            } while (ujfoglalas > 2 || ujfoglalas < 1);
                        }while(ujfoglalas != 2);
                    break;

                /*A 2-es lehetőséggel tud a felhasználó új járatot hozzáadni*/
                case 2:
                    //Beolvasodik a jaratnak a neve es a foglalasi terkepe a forrasfajlba
                    jarathozzaad(kezdo);
                    //A lista felszabaditasra kerul
                    lista_felszabadit(kezdo);
                    //A lista kiegeszul az uj jarattal
                    kezdo = beolvasas();
                break;

                /*A 3-as lehetőség választása esetén a program kilistázza a konzolra, hogy a menükből hányat kell felvinni a járatokra.*/
                case 3:
                    menuk_kiir();
                break;

                default:
                printf("Ervenytelen valasz!\n");
                break;
        }
    }while (valasztas != 6);
}