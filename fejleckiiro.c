#include "fejleckiiro.h"

void bitek(unsigned long long *tomb, int meret) {
    for (int i = 0; i < meret; i++) {
        for (int x = 63; x >= 0; x--) { /*A ciklus vegigmegy a tomb adott elemenek osszes bitjen*/
            printf("%c", tomb[i] >> x & 1 ? '#' : ' '); /*Ha a tomb adott elemenek adott bitje 1, akkor megjelenik a megfelelo helyen egy '#', kulonben egy enter*/
        }
        printf("\n");
    }
}

void fejlecetkiir() {
    /*A tommben talalhatoak meg azok a szamok, amelyek a program elejen megjeleno RIMMAIR felirat megjelenitesere szolgalnak. A szamok bitenkenti abrazolasaval lehet ezt elerni*/
    unsigned long long szamok[12] = {17338902580336246784u, 9849491235864715264u, 9559077298775920640u,
                                     9558091173949214720u, 9845476301057171456u, 10421373553651367936u,
                                     16185981079881744384u, 16185981079881744384u, 10421373556860010496u,
                                     9844912804556578816u, 9556682432697733120u, 9412567244621875200u};
    /*A tomb atadasra kerul a fuggvenynek*/
        bitek(szamok, 12);
    }

