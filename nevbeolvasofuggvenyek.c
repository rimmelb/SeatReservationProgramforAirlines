#include "nevbeolvasofuggvenyek.h"


//A fuggveny megkapja a felhasznalo altal megadott sorszamot, amit a menuvalasztasnal megadott, es visszater egy dinamikusan foglalt sztringgel, ami a menuhoz tartozo kulonleges karaktert tartalmazza
char *menu_sztringkent(int a) {
    //ketelemu dinamikus sztring
    char *uj;
    uj=(char*) malloc(sizeof(char)*2);
    //Ha nem sikerul memoriahelyet foglalni, akkor exit code 1
    if(uj==NULL) {
        exit(1);
    }

    switch (a) {
        case 1: sprintf(uj, "*");     /*Ha a bemenet '*', akkor a felhasznalo vegetarianus menut kert*/
            break;
        case 2: sprintf(uj, "-");     /*Ha a bemenet '-', akkor a felhasznalo normal menut kert*/
            break;
        case 3: sprintf(uj, "+");     /*Ha a bemenet '+', akkor a felhasznalo laktozmentes menut kert*/
            break;
        case 4: sprintf(uj, ":");     /*Ha a bemenet ':', akkor a felhasznalo nem kert menut*/
            break;
        default:
            printf("Ervenytelen valasz!\n");
            break;
    }
    //Visszater a dinamikusan foglalt sztringgel
    return uj;


}



//A fuggveny felelos azert, hogy helyes bemenet erkezzen az utas nevenek, es az utas teljes neve egy dinamikusan foglalt sztringben keruljen eltarolasra a fajlba mentesig
char *nevbeolvas() {

    int Szovegbeolvas;
    char s[51];

    do {
        printf("Kerem a vezeteknevet: \n");
        //Ha a beolvasas sikeres, akkor a Szovegbeolvas valtozo erteke 1
        Szovegbeolvas = scanf("%s", s);

        //A ciklus ellenorzi, hogy az elso betu nagybetu-e, tovabba, hogy van-e benne '#' vagy '+' vagy '-' vagy '*' vagy ':' karakter
        while (s[0] < 'A' || s[0] > 'Z' || strchr(s, '#') != NULL || szovegbeolvaso_fuggvenyek_ellenoriz(s) == false) {

            //Ha belep a ciklusba akkor addig ott marad, amig a feltetelek nem teljesulnek
            printf("Helytelen bemenet! Probalja ujra!\nKerem a vezeteknevet: \n");

            //Beolvassa a karaktereket az enterig, de nem menti el oket
            scanf("%*[^\n]");

            //A felhasznalo ujra megprobalkozhat a nevenek a megadasaval, melyet a ciklusfeltetel majd megint ellenorizni fog
            Szovegbeolvas = scanf("%s", s);
        }
        //A ciklus addig fut, ameddig a belso ciklusba mar nem lep be
    } while(Szovegbeolvas != 1);

    int Szoveg2beolvas;

    char d[51];
    //Ugyanazzal a logikaval mukodik, mint az elozo do - while ciklus
    do {
        printf("Kerem a keresztnevet: \n");
        Szoveg2beolvas = scanf("%s", d);
        while (d[0] < 'A' || d[0] > 'Z' || strchr(d, '#') != NULL || szovegbeolvaso_fuggvenyek_ellenoriz(d)==false) {
            printf("Helytelen bemenet! Probalja ujra!\nKerem a keresztnevet: \n");
            scanf("%*[^\n]");
            Szoveg2beolvas = scanf("%s", d);
        }
    }while(Szoveg2beolvas != 1);

    //Az utas nevenek lefoglalasra kerul egy dinamikus sztring. Meret = vezeteknev es keresztnev hosszanak osszege + enter a ketto kozott + lezaro nulla
    char *uj = (char*) malloc((strlen(s) + strlen(d) + 2)*sizeof(char));
    //Ha nem sikerul foglalni, akkor exit code 1
    if (uj == NULL)
        exit(1);

    //a kovetkezo ciklusok felelosek azert, hogy beolvasodjon az utasnak a neve a dinamikus sztringbe
    int idx = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        uj[idx++] = s[i];
    }
    uj[idx++]=' ';
    for (int i = 0; d[i] != '\0'; i++) {
        uj[idx++] = d[i];
    }
    uj[idx++] = '\0';

    //Visszater a dinamikusan foglalt sztringgel, mely az utas nevet tartalmazza
    return uj;
}


//Beolvassa a felhasznalo altal megadott uj jaratnevet(kiindulasi pont es uticel) ellenorizteti, hogy letezik-e mar ilyen jarat. Ha nem, akkor visszater egy dinamikusan foglalt sztringgel, ami a jarat nevet tartalmazza
char *jaratnevbeolvas(Jaratoklista *eleje) {

    int Szovegbeolvas;
    //Kiindulasi pont max 50. karakter
    char s[51];
    int Szoveg2beolvas;
    //Az enter bekerul egy sztringbe
    char enter[2];
    enter[0]=' ';
    enter[1]='\0';
    //Uticel max 50 karakter
    char d[51];
    //jaratnev = kiindulasi pont + enter + uticel
    char jaratnev[102];
    do {
        do {
            //Addig fut le a ciklus, ameddig a bemenet elso betuje nem nagybetu, nincs benne '#' karakter, tovabba a menubeolvasashoz fontos karakterek
            printf("Kerem a kiindulasi pontot: \n");
            //Kihasznalja, hogy a sikeres beolvasas visszateresi erteke 1
            Szovegbeolvas = scanf("%s", s);
            //Ha nem megfelelo a bemenet, akkor belep a ciklusba es addig marad bent, amig nem kap a felteteleknek megfelelo bemenetet
            while (s[0] < 'A' || s[0] > 'Z' || strchr(s, '#') != NULL ||
                   szovegbeolvaso_fuggvenyek_ellenoriz(s) == false) {
                printf("Helytelen bemenet! Probalja ujra!\nKerem a kiindulasi pontot: \n");
                scanf("%*[^\n]");
                Szovegbeolvas = scanf("%s", s);
            }
        } while (Szovegbeolvas != 1);

        do {
            //Ugyanazzal a logikaval mukodik, mint az elozo, csak ez az uticel
            printf("Kerem az uticelt: \n");
            Szoveg2beolvas = scanf("%s", d);
            while (d[0] < 'A' || d[0] > 'Z' || strchr(d, '#') != NULL ||
                   szovegbeolvaso_fuggvenyek_ellenoriz(d) == false) {
                printf("Helytelen bemenet! Probalja ujra!\nKerem az uticelt: \n");
                scanf("%*[^\n]");
                Szoveg2beolvas = scanf("%s", d);
            }
        } while (Szoveg2beolvas != 1);

        //Egy sztringbe masolodik at a jarat kiindulasi helye es uticelja + kozottuk enter
    strcpy(jaratnev, s);
    strcat(jaratnev, enter);
    strcat(jaratnev, d);
    //Ha a jaratnev_compare fuggveny talal ilyen jaratot
    if(jaratnev_compare(eleje, jaratnev) == true) {
        printf("Sajnos ez a jarat mar letezik. Kerem probalja ujra!\n");
    }
    //Eddig fut a ciklus, ameddig talal ilyen jaratot
    }while(jaratnev_compare(eleje, jaratnev) == true);

    //A jarat neve egy dinamikus sztringben kerul visszaadasra
    char *uj = (char*) malloc((strlen(s) + strlen(d) + 2)*sizeof(char));

    if (uj == NULL) {
        exit(1);
    }
    int idx = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        uj[idx++] = s[i];
    }
    uj[idx++]=' ';
    for (int i = 0; d[i] != '\0'; i++) {
        uj[idx++] = d[i];
    }
    uj[idx++] = '\0';
    return uj;
}
