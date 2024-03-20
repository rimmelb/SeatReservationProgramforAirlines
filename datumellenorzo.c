#include "datumellenorzo.h"


/*Ellenorzi, hogy a bemenetkent erkezett ev szokoev-e*/
bool szokoev(int ee) {
    if ((ee % 400 == 0 || ee % 4 == 0) && ee % 100 != 0) {
        return true;
    }
    return false;
}

/*Ellenorzi, hogy a bemenetkent erkezett honap harminc napbol all-e*/
bool harmincnapos(int h) {
    if(h == 4 || h == 6 || h == 9 || h == 11) {
        return true;
    }
    return false;
}


/*Ellenorzi, hogy a bemenetkent erkezett honap harmincegy napbol all-e*/
bool harmincegynapos(int h) {
    if(h == 1 || h == 3 || h == 5 || h == 7 || h == 8 || h == 10 || h == 12) {
        return true;
    }
    return false;
}


/*Ellenorzi, hogy a felhasznalo egyaltalan megfelelo honapot adott-e meg*/
bool honap_ervenyes(int h) {

    if(h>0 && h<13) {
        return true;
    }
    return false;
}


/*Ellenorzi, hogy a bemenetkent erkezett ev 1900 es 2023 kozott van-e*/
bool ev_ervenyes(int ee) {
    if(ee<1900 || ee>2022) {
        return false;
    }
    return true;
}


/*Ez a fuggveny hivodik meg az utasbeolvaso.c modulban a datum ellenorzesere*/
int jodatum (int ev, int honap, int nap) {

    /*Ha teljesul, hogy a bemenetkent erkezett ev szokoev is egyben*/
    if (ev_ervenyes(ev) != false) {

        /*Ha jo honapot adott meg*/
        if (szokoev(ev) == true) {

            if (honap_ervenyes(honap) == true) {
                /*Ha harmincegy napos a honap*/
                if (harmincegynapos(honap) == true) {
                    /*Ha a megadott nap is megfelelo*/
                    if (nap > 0 && nap < 32) {
                        return 1;
                    } else {
                        /*Ha a megadott nap, nem megfelelo*/
                        return 4;
                    }
                }
                    /*Ha harmincnapos a honap*/
                else if (harmincnapos(honap) == true) {
                    /*Ha a megadott nap is megfelelo*/
                    if (nap > 0 && nap < 31) {
                        return 1;
                    } else {
                        /*Ha nem megfelelo a megadott nap*/
                        return 4;
                    }
                }

                /*Ha a megadott honap a februar*/
                if (honap == 2) {
                    /*Mivel a szokoev teljesul, itt elfogadhato a 29-e is*/
                    if (nap > 0 && nap < 30) {
                        return 1;
                    }
                        /*Ha nem megfelelo napot adott meg*/
                    else {
                        return 4;
                    }
                }
            }
            else
                /*Ha nem megfelelo honapot adott meg*/
                return 3;
        }

        else {
            /*Innentol ugyanaz a logika, mint a fo 'if' agnal, kivetel a februar vizsgalatanal*/
            if (honap_ervenyes(honap) == true) {
                /*Ha februar*/
                if (honap == 2) {
                    /*Akkor a 29-e nem engedelyezett*/
                    if (nap > 0 && nap < 29) {
                        return 1;
                    } else
                        return 4;

                }
                else if (harmincegynapos(honap) == true) {

                    if (nap > 0 && nap < 32) {
                        return 1;
                    }
                    else {
                        return 4;
                    }
                }
                else if (harmincnapos(honap) == true) {

                    if (nap > 0 && nap < 31) {
                        return 1;
                    }
                    else {
                        return 4;
                    }
                }
            }
            else {
                return 3;
            }
        }
    }

    else
    {
        /*Ha az ev bemenet nem ervenyes*/
        return 2;
    }
}