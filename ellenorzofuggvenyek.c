#include "ellenorzofuggvenyek.h"

//A fuggveny feladata, hogy az bemenetrol erkezo sztringekben ne legyen olyan karakter, ami a fajl beolvasasnal fontos
bool szovegbeolvaso_fuggvenyek_ellenoriz(char *a) {
    char s[5]="+:*-";
    for(int i=0; a[i]!='\0'; i++) {
        if(strchr(s, a[i]) != NULL) {
            return false;
        }
    }
    return true;
}

/*Ellenorzi, hogy amikor az egyik jarat foglalasi terkepet szeretne megtekinteni, akkor biztosan biztosan szam bemenet erkezett-e*/
int terkepkeres_ellenorzo(Jaratoklista *eleje) {
    int szam;
    int Szambeolvas;
    do {
        //Megjelenitesre kerul az osszes jarat neve es sorszama
        listanev_kiir(eleje);
        printf("Valasszon, hogy melyik jarat foglalasi terkepet szeretne megtekinteni!\n"
               "Valasztas modja: Szammal!\n");
        /*Mivel a scanf visszateresi erteke 1, ezert a scanf beepitett fuggvenyt atadjuk egy valtozonak*/
        Szambeolvas = scanf("%d", &szam);
        /*Ha a beolvasas sikertelen, azaz a valtozo erteke nem 1*/
        while(Szambeolvas!=1) {
            printf("Helytelen bemenet! Probalja ujra!\n");
            /*Akkor a maradek beerkezett bemenet enterig olvasodjon be, de ne tarolodjon el*/
            scanf("%*[^\n]");
            /*Ezt kovetoen ujra beolvasasra kerul az adat*/
            Szambeolvas = scanf("%d", &szam);
        }
        /*A ciklus addig tart, ameddig a beolvasas nem sikeres*/
    }while(Szambeolvas!=1);
    return szam;

}

/*Ellenorzi, hogy a jarat valasztasanal biztosan szam bemenet erkezett-e*/
int jaratellenorzo() {
    int szam;
    int Szambeolvas;
    do {
        Szambeolvas = scanf("%d", &szam);           /*Mivel a scanf visszateresi erteke 1, ezert a scanf beepitett fuggvenyt atadjuk egy valtozonak*/

        while(Szambeolvas!=1) {                             /*Ha a beolvasas sikertelen, azaz a valtozo erteke nem 1*/
            printf("Helytelen bemenet! Probalja ujra!\n");
            scanf("%*[^\n]");                       /*Akkor a maradek beerkezett bemenet enterig olvasodjon be, de ne tarolodjon el*/
            Szambeolvas = scanf("%d", &szam);       /*Ezt kovetoen ujra beolvasasra kerul az adat*/
        }
    }while(Szambeolvas!=1);                             /*A ciklus addig tart, ameddig a beolvasas nem sikeres*/

    return szam;

}

//Ellenorzi, hogy a fomenuben jo bemenet erkezett-e a valasztasnal
int valasztasellenorzo() {
    int szam;
    int Szambeolvas;
    do {
        printf("\n1 - Jegyfoglalas\n"
               "2 - Uj jarat hozzaadasa\n"
               "3 - Menuk jaratonkent\n"
               "4 - Jelenlegi jaratok listaja\n"
               "5 - Tetszoleges jarat foglalasi terkepenek megjelenitese\n"
               "6 - Kilepes\n");

        Szambeolvas = scanf("%d", &szam);
        while(Szambeolvas!=1) {
            printf("Helytelen bemenet! Probalja ujra!\n"
                   "1 - Jegyfoglalas\n"
                   "2 - Uj jarat hozzaadasa\n"
                   "3 - Menuk jaratonkent\n"
                   "4 - Jelenlegi jaratok listaja\n"
                   "5 - Tetszoleges jarat foglalasi terkepenek megjelenitese\n"
                   "6 - Kilepes\n");
            scanf("%*[^\n]");
            Szambeolvas = scanf("%d", &szam);
        }
    }while(Szambeolvas!=1);

    return szam;

}

//Ellenorzi, hogy szam erkezett-e a bemenetrol akkor, amikor a program felajanlja, hogy foglal-e a felhasznalo masnak is
int ujfoglalasellenorzo() {
    int szam;
    int Szambeolvas;
    do {
        printf("Szeretne meg masnak is foglalni? 1-igen, 2-nem\n");
        Szambeolvas = scanf("%d", &szam);
        while(Szambeolvas!=1) {
            printf("Helytelen bemenet! Probalja ujra!\nSzeretne meg masnak is foglalni? 1-igen, 2-nem\n");
            scanf("%*[^\n]");
            Szambeolvas = scanf("%d", &szam);
        }
    }while(Szambeolvas!=1);

    return szam;

}

//A fuggveny ellenorzi, hogy jo bemenet erkezett-e a szuletesi ev megadasanal
int szuletesievellenorzo() {

    int szam;
    int Szambeolvas;
    do {
        printf("Szuletesi ev (eeee. formatum): \n");
        Szambeolvas = scanf("%d", &szam);
        while(Szambeolvas!=1) {
            printf("Helytelen bemenet! Probalja ujra!\nSzuletesi ev (eeee. formatum): \n");
            scanf("%*[^\n]");
            Szambeolvas = scanf("%d", &szam);
        }
    }while(Szambeolvas!=1);

    return szam;

}

//A szuletesihonapellenorzo() ellenorzi, hogy a honap megadasanal a bemenetre biztosan szam erkezett-e
int szuletesihonapellenorzo() {

    int szam;
    int Szambeolvas=0;
    do {
        printf("Szuletesi honap (hh. formatum): \n");
        Szambeolvas = scanf("%d", &szam);
        while(Szambeolvas!=1) {
            printf("Helytelen bemenet! Probalja ujra!\nSzuletesi honap (hh. formatum): \n");
            scanf("%*[^\n]");
            Szambeolvas = scanf("%d", &szam);
        }
    }while(Szambeolvas!=1);

    return szam;

}

//A szuletesinapellenorzo() ellenorzi, hogy biztosan szam erkezett-e a bemenetre a szuletesi nap beolvasasakor
int szuletesinapellenorzo() {
    int szam;
    int Szambeolvas;
    do {
        printf("Szuletesi nap (nn.formatum): \n");
        Szambeolvas = scanf("%d", &szam);
        while(Szambeolvas!=1) {
            printf("Helytelen bemenet! Probalja ujra!\nSzuletesi nap (nn.formatum): \n");
            scanf("%*[^\n]");
            Szambeolvas = scanf("%d", &szam);
        }
    }while(Szambeolvas!=1);

    return szam;

}

/*A menuellenorzo() ellenorzi, hogy biztosan szam erkezett-e a bemenetre, amikor menut valaszt a felhasznalo*/
int menuellenorzo() {
    int szam;
    int Szambeolvas;
    do {
        printf("Milyen menut szeretne? (a menuk sorszamat adja meg!)\n"
               "1. vegetarianus\n"
               "2. normal\n"
               "3. laktozmentes\n"
               "4. nem szeretnek\n");

        Szambeolvas = scanf("%d", &szam);
        while(Szambeolvas!=1) {
            printf("Helytelen bemenet! Probalja ujra!\n"
                   "Milyen menut szeretne? (a menuk sorszamat adja meg!)\n"
                   "1. vegetarianus\n"
                   "2. normal\n"
                   "3. laktozmentes\n"
                   "4. nem szeretnek\n");
            scanf("%*[^\n]");
            Szambeolvas = scanf("%d", &szam);
        }
    }while(Szambeolvas!=1);

    return szam;

}

/*Az ulohelyellenorzo() fuggveny akkor hivodik meg, amikor a ulohely beolvasasra kerul sor*/
char *ulohelyellenorzo() {

    char uj[3];

    do {
        printf("Hova szeretne helyet foglalni? A megadas modja: a sornak megfelelo NAGYbetu es az oszlopnak megfelelo szam!\n");

        /*A bemenetre erkezo szovegnek az elso ket karaktere olvasodik be, mivel eleve csak annyi karakterre van szuksegunk*/
        scanf("%2s", uj);

        /*Amennyiben a sztring elso eleme nem nagybetu es a masodik eleme nem 1 es 6 koze esik*/
        while (uj[0] < 'A' || uj[0] > 'O' || uj[1]>'6' || uj[1]<'1') {
            printf("Helytelen bemenet! Probalja ujra!\nHova szeretne helyet foglalni? A megadas modja: a sornak megfelelo NAGYbetu es az oszlopnak megfelelo szam!\n");

            /*Kovetkezo enterig beolvasodik a maradek szoveg, de nem kerul elmentesre, a felhasznalo meg egyszer megadja az altala valasztott ulohelyet, ami beolvasodik*/
            scanf("%*[^\n]");
            scanf("%2s", uj);
        }
    }while(uj[0] < 'A' || uj[0] > 'Z' || uj[1]>'6' || uj[1]<'1');
    /*A do while ciklus addig, fut ameddig a feltetelek nem teljesulnek*/

    /*Ha teljesul, akkor visszater egy dinamikusan foglalt sztringgel, ami tartalmazza a felhasznalo altal megadott ulohelyet*/
    uj[2]='\0';
    char *visszater = (char*) malloc(3*sizeof(char));
    if(visszater == NULL)
        exit(1);

    strcpy(visszater, uj);
    /*
    int idx=0;
    for(int i=0; uj[i]!='\0'; i++) {
        visszater[idx++]=uj[i];
    }
    visszater[idx++]='\0';
     */

    return visszater;

}


/*A bemenetellenorzo(char *forras) fuggveny ellenorzi, hogy a megadott sztring, ami a szemelyiigazolvany-szamot tartalmazza, megfelel-e a paramétereknek*/
bool bemenetellenorzo(char *forras) {
    int idx=0;
    /*Meg kell vizsgalni, hogy a bemenet egyaltalan 8 karakter hosszusagu-e. Ha nem, akkor a fuggveny visszateresi erteke hamis*/
    int v = strlen(forras);
        if(v<8) {
            return false;
        }
    if(szovegbeolvaso_fuggvenyek_ellenoriz(forras) == false) {
        return false;
        }
    /*Ellenorzi, hogy a sztring elso 6 eleme nagybetu-e*/
    while(idx<6) {
        if (isdigit(forras[idx]) == true) {         /*Az isalpha(karakter) ellenorzi, hogy betu-e az adott karakter*/
            if (forras[idx] < '1' || forras[idx] > '6' || forras[idx] == '#') {         /*Ha az adott sztringelem nem esik bele a megfelelo parameterekbe, azaz nem nagybetu vagy #, amivel elvalasztjuk a fajlban az adatokat*/
                return false;                           /*A fuggveny visszateresi erteke hamis*/
            }
        }
        else                /*Ha az adott sztringelem nem is betu*/
            return false;
        idx++;
    }
    /*Ez a ciklus, amennyiben nem tert mar vissza a fuggveny, azt vizsgalja, hogy az utolso ket karakter szam-e*/
    while(forras[idx]!='\0') {
        if (isalpha(forras[idx]) == true) {         /*Az isdigit(karakter) fuggvennyel megvizsgaljuk, hogy a karakter szam-e*/
            if (forras[idx] < 'A' || forras[idx] > 'Z' || forras[idx] == '#') {     /*Ha nem szam vagy '#', ami a fajlban az adatok elvalasztasara szolgal*/
                return false;
            }
        } else {
            return false;
        }
        idx++;
    }
    return true;            /*Amennyiben minden parameternek megfelelt a sztring, akkor a fuggveny visszateresi erteke igaz*/
}

/*A szemelyiigellenorzo() fugvennyel kerul beolvasasra a szemelyi igazolvany szam*/
char *szemelyiigellenorzo() {
    /*Memoriahelyet foglalunk, amibe a bemenetre erkezo szemelyiigazolvany-szam fog eltarolodni (6 nagybetu + 2 szam + lezaro nulla = 9)*/
    char *uj=(char*) malloc(9*sizeof(char));
    if(uj==NULL)
        /*Ha nem sikerul foglalni, akkor exit code 1*/
        exit(1);
    do {
        printf("Kerem a szemelyi igazolvany szamat!\nA megadas modja: 6 szam es 2 Nagybetu!\n");
        scanf("%8s", uj);
        /*Amíg a bemenetellenorzo fuggveny visszateresi erteke hamis a parameterkent atadott sztring fuggvenyeben*/
        while ((bemenetellenorzo(uj)==false)) {
            printf("Helytelen bemenet! Probalja ujra!\nKerem a szemelyi igazolvany szamat!\nA megadas modja: 6 szam es 2 Nagybetu!\n");
            scanf("%*[^\n]");                               /*A bemenet levo maradek karakter beolvasodik az enterig, de nem kerul eltarolasra*/
            scanf("%8s", uj);                               /*Ujra beolvassuk a felhasznalo altal megadott karaktereket*/
        }
    /*Amig a bemenetellenorzo() fuggveny visszateresi erteke hamis az atadott sztring fuggvenyeben*/
    }while(bemenetellenorzo(uj)==false);
    return uj;

}

//a fuggveny ellenorzi, hogy a lancolt listaban talalhato-e mar az a jaratnev, ami a bemenetre erkezett
bool jaratnev_compare(Jaratoklista *eleje, char *jaratnev) {
    Jaratoklista *mozgo;
    //Vegigmegy a lista elemein
    for(mozgo=eleje; mozgo!=NULL; mozgo = mozgo->kov) {
        //Ha a listaban levo nev sztring megegyezik a jaratnevvel, akkor igaz a visszateresi ertek
        if(strcmp(jaratnev, mozgo->nev) == 0) {
            return true;
        }
    }
    //Ha nem talalja meg, akkor hamis a visszateresi ertek
    return false;
}
