#include "fajlkezelofuggvenyek.h"

/*A fuggveny ellenorzi, hogy a fofajlban jelenleg hany sor van*/
int fajlsorok_szama() {
    int sor=0;
    char b;
    /*A FILE *fp pointerrel megnyitjuk olvasasra a jaratok.txt szoveges fajlt*/
    FILE *p;
    p=fopen("jaratok.txt", "r");
    /*Ha nem sikerul megnyitni, akkor exit code 2*/
    if(p==NULL) {
        exit(2);
    }
    /*A for ciklus vegigmegy a szoveges fajlon fajl vege jelig, es megszamolja mennyi enter talalhato meg benne*/
    for(b = getc(p); b != EOF; b = getc(p)) {
        if (b == '\n')
            sor++;
    }
    /*A szoveges fajl bezarasra kerul*/
    fclose(p);
    /*A fuggveny visszater a sorok szamaval*/
    return sor;
}



/*A menuk_kiir fuggveny valositja meg, hogy jaratonkent kiirodjon a konzolos feluletre, hogy melyik menubol mennyit kell felvinni*/
void menuk_kiir() {
    FILE *fp;
    /*Ezekben a valtozokban fog majd tarolodni, hogy az adott jaratra hany menut kell felvinni*/
    int normal = 0;
    int vega = 0;
    int nincs = 0;
    int lakmentes = 0;

    fp=fopen("jaratok.txt", "r");
    /*Amennyiben nem sikerul a fajlt megnyitni olvasashoz, akkor exit code 2*/
    if(fp==NULL)
        exit(2);
    /*Ebbe a sztringbe fognak a fajlbol a megfelelo sorok beolvasodni*/
    char sor[2001];
    /*Ebbe a sztringbe fog beolvasasra kerulni a jaratnak a neve*/
    char *nev;
    int index = 0;
    int r=0;

    for(int i = 0; i < fajlsorok_szama()+1; i++) {          /*A ciklus vegigmegy a sorokon, es a fajl i+1. sora beolvasodik a sor sztringbe*/

        fgets(sor, 2001, fp);

        for(int t=0; sor[t]!='#'; t++) {                    /*A ciklus megnezi, hogy hany karakter hosszu a jarat neve, majd foglalunk egy dinamikus sztringet, melynek hossza a jarat nevenek hossza + 1)*/
            r++;
        }
        nev = (char*) malloc((r+1)*sizeof(char));
        if(nev==NULL) {
            exit(1);
        }

        for(int x=0; sor[x]!='#'; x++) {                    /*A jarat neve az adott sorban az elso # karakter elott talalhato*/
            nev[index++]=sor[x];
        }
        nev[index++]='\0';                                  /*A jarat nevet tarolo sztringet lezaro nullaval zarjuk le*/

        for(int idx=0; sor[idx]!='\0'; idx++) {             /*A ciklus vegigmegy a fajl megadott sorabol beolvasott sztringen es megszamolja, hogy hany '*', '-', '+', ':' karakter talalhato benne*/
            if(sor[idx]=='*') {                             /* '*' = vega menu*/
                vega++;
            }
            else if(sor[idx]=='-') {                        /* '-' = normal menu*/
                normal++;
            }
            else if(sor[idx]=='+') {                        /* '+' = laktozmentes menu*/
                lakmentes++;
            }
            else if(sor[idx]==':') {                        /* ':' = nem kert menut*/
                nincs++;
            }
        }

        printf("A %s -ba/-be tarto jaratra:\n"
               "%d utas kert normal menut\n"
               "%d utas kert vegetarianus menut\n"
               "%d utas kert laktozmentes menut\n"
               "%d utas nem kert menut\n\n", nev, normal, vega, lakmentes, nincs);

        normal=0;               /*A valtozokat kinullazzuk, hiszen nem osszegezzuk oket, hanem csak jaratonkent szamolunk*/
        vega=0;
        nincs=0;
        lakmentes=0;
        index=0;
        r=0;
        free(nev);             /*A jarat nevenek foglalt memoria felszabadul, mivel az ugyis megegyszer lefoglalasra fog kerulni*/
    }
    fclose(fp);
}




/*A jarathozzaad() fuggveny felelos azert, hogy a fajlban egy uj sorba beirodjon a felhasznalo altal megadott jaratnak a neve es egyben a foglalasi terkepe is*/
void jarathozzaad(Jaratoklista *eleje) {
/*A jarat nevenek dinamikusan foglalunk memoriahelyet, melyet a jaratnevbeolvas() fuggveny vegez el, amely a bemenetet is ellenorzi*/
    char *nev=jaratnevbeolvas(eleje);
    FILE *ptr;
    /*A FILE *ptr pointer megnyitja a fofajlt, amely kiegeszitesre fog kerulni*/
    ptr = fopen("jaratok.txt", "a");
    /*Ha nem sikerul megnyitni, akkor exit code 2*/
    if(ptr==NULL)
        exit(2);
    /*Beirodik a fajlba a jarat neve, de elotte elhelyezesre kerul egy enter is, hogy uj sorba irodjon a nev. A '#' karakter valasztja el jarat nevet a foglalasi terkeptol*/
    fprintf(ptr, "\n%s#", nev);
    for (int i = 0; i < 90; i++) {
        /*Beirodik a fajlba a foglalasi terkep is, ami kezdetben csupa 0, hiszen meg nem tortent foglalas*/
        fprintf(ptr, "0");
    }
    /*A foglalasi terkep utan is elhelyezesre kerul egy '#' karakter*/
    fprintf(ptr, "#");
    /*A szoveges fajl bezarodik*/
    fclose(ptr);
    /*A lefoglalt memoriahely felszabadul*/
    free(nev);
}



/*Ezzel a fuggvennyel tortenik meg a segedfajlba atiras*/
void kiegfajlt_atir(Jaratoklista *eleje, Utas *a) {
    FILE *fp;
    FILE *g;
    /*A ket pointerrel megnyitasra kerul a ket szoveges fajl. A kiegeszito.txt-be ir a program, mig a jaratok.txt-bol olvas*/
    g = fopen("kiegeszito.txt", "w");
    fp = fopen("jaratok.txt", "r");

    /*Ha valamelyik szoveges fajlt nem sikerul megnyitni, akkor exit code 2*/
    if(g == NULL || fp == NULL) {
        exit(2);
    }
    //A hashtag egy sztringbe kerul
    char s[2];
    s[0]='#';
    s[1]='\0';

    //Az utas szuletesi ideje egy sztringbe kerul
    char datum[20];

    sprintf(datum, "%d.%d.%d", a->ev, a->honap, a->nap);

    //A menuhoz tartozo betujel egy dinamikus sztringbe kerul
    char *menu = menu_sztringkent(a->menu);

    //Az utas osszes adata egy sztringbe kerul
    char utasadat[150];

    sprintf(utasadat, "%s%s%s%s%s%s%s%s%s%s", a->nev, s, datum, s, a->szemelyiig, s, menu, s, a->ulohely, s);

    char sor[1000];

    char ujsor[1000];

    int idx=0;

    int osszes = fajlsorok_szama()+1;

    //Az enter is egy sztringbe kerul
    char enter[2];
    enter[0]='\n';
    enter[1]='\0';

    //A ciklus vegigmegy a fajl osszes soran
    for (int r = 0; r < osszes; r++) {
                        //Ha a jaratszam (-1, mivel az r nullatol indul) megegyezik a beolvasott sor szamaval
                        if (r == (a->jaratszam-1)) {
                        /*Beolvasodik a fajl megfelelo sora*/
                        fgets(sor, 1000, fp);
                        //Az elso hashtagig beolvasodik a jarat neve
                        for(int i=0; sor[i]!='#'; i++) {
                                    ujsor[idx++]=sor[i];
                        }
                        /*A jarat neve utan '#'*/
                        strcat(ujsor, s);
                    //Megkeresi a jaratszam alapjan a megfelelo lancolt listat, hogy annak a foglalasi terkepe frissitesre keruljon
                    Jaratoklista *megfelelo = listaban_keres(eleje, a->jaratszam);

                    /*Az uj foglalasi terkep bekerul az uj sorba, utana megint '#'*/
                    strcat(ujsor, megfelelo->foglalas);
                    strcat(ujsor, s);

                    /*Az idx valtozot megnoveljuk 92-vel, mivel 92 = 90 darab ulohely + 2 darab '#' karakter*/
                    idx+=92;

                    /*ujsor hossza egy v valtozonak adodik at*/
                    int v=strlen(ujsor);

                    /*Amig az eredetileg beolvasott sorban a ciklus nem er el az enterig, addig atmasolodik az uj sorba az eredeti sorbol azoknak az utasoknak az adatai, akik korabban foglaltak*/
                    while(sor[v] != '\n') {
                        ujsor[idx++]=sor[v];
                        v++;
                    }

                    /*Ezutan kerul hozza a mostani utas adata '#' karakterekkel elvalasztva, majd egy enter*/
                    strcat(ujsor, utasadat);

                    //Ha az utolso sorba olvasodik be, akkor nincs enter, kulonben ures sor keletkezik
                    if(r == osszes - 1) {
                        fprintf(g, "%s", ujsor);
                    }
                    //Ha nem akkor egy enter adodik a sztring vegere
                    else {
                        strcat(ujsor, enter);
                        fprintf(g, "%s", ujsor);
                    }
                }
        else
            {
            /*A tobbi sor csak szimplan atmasolodik a kiegeszito.txt-be*/
            fgets(sor, 1000, fp);
            fprintf(g, "%s", sor);
        }
    }
    free(menu);
    /*A fuggveny vegen bezarasra kerulnek a szoveges fajlok*/
    fclose(fp);
    fclose(g);
}





/*Ez a fuggveny vegzi el a segedfajlbol az fofajlba torteno atirast, miutan az utasnak az adatai a kiegeszito fajlba beolvasodtak*/
void jaratokfajlba_atir() {
    FILE *d;
    FILE *r;

    /*A ket pointerrel megnyitasra kerulnek a szoveges fajlok. A kiegeszito.txt-bol beolvas, mig a jaratok.txt fo szoveges fajlt felulirja*/
    d=fopen("kiegeszito.txt", "r");
    r=fopen("jaratok.txt", "w");

    /*Ha valamelyik fajlt nem sikerul megnyitni, akkor exit code 2*/
    if(d==NULL || r==NULL)
        exit(2);


    char c=fgetc(d);
    /*Amig a fajlbol beolvasott karakter nem er el a fajl vege jelig, addig a kiegeszito.txt-bol a szoveg karakterenkent atirodik a jaratok.txt-be*/
    while(c!=EOF) {
        fputc(c, r);
        c=fgetc(d);
    }
    /*A ket szoveges fajl bezarodik*/
    fclose(d);
    fclose(r);
}

