#include "utasbeolvaso.h"
#include "nevbeolvasofuggvenyek.h"
#include "datumellenorzo.h"

/*A függvény a bemenetre érkező sztringet, mely a felhasználó által választott ülőhelyet tartalmazza, egy értékké alakítja át,
 * mellyel a láncolt listában kiválasztott elemnek (járatnak) a foglalásokat tartalmazó tömbjében tudunk keresni.*/
int ertekke(char *a) {
    int osszeg = 0;
    /*Az if, else if szerkezettel megvizsgálja, hogy a sztring első eleme nagy vagy kicsi és ennek függvényében vonja ki a kis 'a' vagy nagy 'A' betűt,
     * mellyel valójában a karakterkódok közötti különbséget kapjuk meg és azt adjuk hozzá egy már létrehozott intigerhez*/
    if (a[0] >= 'A' && a[0] <= 'Z') {
        osszeg += a[0]-'A';
    }
    else if (a[0] >= 'a' && a[0] <= 'z') {
        osszeg += a[0]-'a';
    }
    /*Mivel soronként 6 hely van, ezért be kell szoroznunk 6-tal a sorszámot*/
    osszeg *= 6;
    /*Az összeghez hozzáadjuk a sztring második elemének a karakterkódjának és a 0 karakterkódjának a különbségét*/
    osszeg += (a[1]-'0');
    /*Végül megkapjuk a pontos ülőhelyet számként. Például ha a sztring azt tartalmazta, hogy A2, akkor a visszatérési érték 2.*/
    return osszeg;
}

//A fuggveny felszabaditja az Utas strukturaban dinamikusan foglalt sztringeket
void felszabaditas(Utas *a) {
    free(a->ulohely);
    free(a->szemelyiig);
    free(a->nev);
}

/*A fuggveny arra szolgal, hogy beolvassuk a felhasznalo adatait, majd fajlba tudjuk azt menteni!*/
Utas beolvas(Jaratoklista *eleje) {
    Utas uj;
/*A v valtozoval tudjuk ellenorzi, hogy hany jarat van jelenleg*/
    int v=fajlsorok_szama();

    /*Ez a listaelem lesz az, amelyet a felhasznalo kivalaszt, es kesobb modositja*/
    Jaratoklista *megfelelo;

    char c='0';
    /*A ciklus addig megy, ameddig a felhasznalo altal kivalasztott jaraton talal ulohelyet*/
    do {
        do {
            /*kiirja a listat*/
            listanev_kiir(eleje);

            printf("Melyik jaratra szeretne foglalni?\n");
            /*meghivja a jaratellenorzo() fuggvenyt, amely ellenorzi, hogy a bemenet biztosan szam-e*/
            uj.jaratszam = jaratellenorzo();
            /*ha nem a jelenlegi jaratok kozul valaszt, a ciklus ujraindul*/
            if (uj.jaratszam < 1 || uj.jaratszam > v+1) {
                printf("Ervenytelen valasz!\n");
            }
        } while (uj.jaratszam < 1 || uj.jaratszam > v+1);
        /*megkeresi a felhasznalo altal valasztott jaratot*/
        megfelelo = listaban_keres(eleje, uj.jaratszam);
        /*ha a felhasznalo altal valasztott jaraton minden hely betelt, akkor az egesz ciklus ujraindul*/
        if(strchr(megfelelo->foglalas, c) == NULL) {
            printf("Sajnos a jaratunk betelt! Kerem valasszon masik jaratot!\n");
        }
        /*Ha talalt a jaraton ures helyet, akkor kilep a ciklusbol a megfelelo listaelemmel es a strukturaban tarolt jaratszammal*/
    }while(strchr(megfelelo->foglalas, c) == NULL);

    //Az utas neve a megfelelo formatumban beolvasodik. A nevbeolvas fuggveny egy dinamikusan foglalt sztringgel ter vissza
    uj.nev = nevbeolvas();

    int x;

    /*Ez a ciklus szolgal a szuletesi ido beolvasasara*/
    do {
        printf("Kerem a szuletesi datumot!\n");

        /*Mindharom fuggveny figyel arra, hogy megfelelo bemenet erkezzen, azaz ebben az esetben szam*/
        uj.ev = szuletesievellenorzo();
        uj.honap = szuletesihonapellenorzo();
        uj.nap = szuletesinapellenorzo();

        /*egy valtozoba meghivodik a jodatum fuggveny, amely leellenorzi, hogy a parametereknek megfelelo szuletesi datum erkezett-e*/
        x = jodatum(uj.ev, uj.honap, uj.nap);

        switch (x) {
            /*Ha a jodatum(..) fuggveny visszateresi erteke 1, akkor a ciklus veget er, es a strukturaba elmentesre kerulnek a megfelelo szamok*/
            case 1:
                break;
            /*A jodatum(..) fuggveny visszateresi erteke 2, az azt jelenti, hogy rossz szuletesi evet utott be*/
            case 2:
                printf("1900 elott biztos nem szuletett, mint ahogy 2022 utan sem!\n");
                break;
            /*A jodatum(..) fuggveny visszateresi erteke 3, az azt jelenti, hogy rossz szuletesi honapot utott be*/
            case 3:
                printf("Rossz bemenet a honap eseteben!\n");
                break;
            /*A jodatum(..) fuggveny visszateresi erteke 3, az azt jelenti, hogy a korabban megadott honapban biztos nem szuletett azon a napon (peldaul szeptember 32-en)*/
            case 4:
                printf("Az adott honapban, mar ha jo bemenetet adott meg honapnak, biztos nem szulethetett ezen a napon!\n");
                break;
            case 0: printf("Helytelen bemenet!\n");
            break;

            default: printf("Ervenytelen valasz!\n");
        }
        /*Amig nem 1 a visszateresi ertek, addig a ciklus ujraindul*/
    } while (x != 1);

    /*A szemelyiigazolvany-szamot a szemelyiigellenorzo() fuggvennyel olvassuk be es ellenorizzuk egyben*/
    uj.szemelyiig = szemelyiigellenorzo();

    do {
        /*A menut szamokkal valasztjuk ki. A menuellenorzo() fuggveny segitsegevel tortenik meg a beolvasas es ellenorzes*/
        uj.menu = menuellenorzo();

        switch (uj.menu) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("Ervenytelen valasz!\n");
                break;
        } while (uj.menu < 0 || uj.menu > 4);
        /*Amig nem erkezett megfelelo bemenet, addig a ciklus ujraindul*/
    } while (uj.menu < 0 || uj.menu > 4);

    int b;

    /*A ciklus arra szolgal, hogy a beolvassuk a felhasznalo altal kivant ulohelyet*/
    do {
        //Kirajzolja a megfelelo jaratnak a foglalasi terkepet
        kirajzol_foglalas(megfelelo);
        //Beolvasasra kerul egy dinamikusan foglalt sztringbe az ulohely
        uj.ulohely = ulohelyellenorzo();
        //Az ulohely ertekke alakul at, hogy a foglalasokat tartalmazo tombben tudjon keresni, -1, mivel a tomb nullatol indexelodik
        b = ertekke(uj.ulohely) - 1;
        //Ha a kivalasztott hely foglalt
        //Ha nem sztringgel ter vissza a fuggveny, akkor az is legyen kezelve
        if(uj.ulohely == NULL) {
            printf("Nem sikerult lefoglalni, probalja ujra!\n");
        }
        if (megfelelo->foglalas[b] == '1') {
            printf("A foglalas sikertelen, mivel ez a hely mar foglalt!\n");
            //Ha nem NULL-val ter vissza, akkor szabaditsa fel a memoriateruletet
            if(uj.ulohely != NULL) {
                free(uj.ulohely);
                b = 0;
            }
        }
    /*
        //Ha nagyobb szam jott, mint a foglalasi terkepnek a legszelso indexei
        else if (b > 89 || b < 0) {
                printf("A bemenet nem megfelelo, mivel ez a hely nem letezik!\n");
                //Ha nem NULL-val ter vissza, akkor szabaditsa fel a memoriateruletet
                if(uj.ulohely != NULL) {
                    free(uj.ulohely);
                    b = 0;
                }
            }
*/
        //Amig nem sikerul helyet talalni, addig fusson a ciklus
    }while (megfelelo->foglalas[b] != '0');

    /*A felhasznalo altal foglalt helyet foglaltta tesszuk a tovabbi felhasznalok szamara*/
    for(int i = 0; megfelelo->foglalas[i] != '\0'; i++) {
        if (i == b) {
            /*A sztringben a megfelelo '0' atirodik '1'-re*/
            megfelelo->foglalas[i] = '1';
        }
    }
    //A fuggveny visszater az utasnak az adataival
    return uj;
}