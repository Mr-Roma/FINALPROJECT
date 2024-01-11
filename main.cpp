#include "header.h"
#include <iostream>
using namespace std;

int main() {
    infotypeSma addSma;
    infotypeSiswa addSiswa;
    infotypeBimbel addBimbel;

    listSma Lsa;
    listBimbel Lb;

    createListSma(Lsa);
    createListBimbel(Lb);

    int x;

    bool loopMenu = true;
    while(loopMenu) {
        x = menu();

        if (x == 1) {
            menuInput(Lsa, Lb);
        } else if (x == 2) {
            menuDelete(Lsa, Lb);
        } else if (x == 3) {
            menuCari(Lsa, Lb);
        } else if (x == 4) {
            menuShow(Lsa, Lb);
        } else if (x == 5) {
            menuBimbelSesuai(Lsa,Lb);
        } else if (x == 6) {
            menuDiscount(Lsa);
        } else if (x == 7) {
            cout << "THANK YOU FOR USE OUR APPLICATION" << endl;
            loopMenu = false;
        } else {
            cout << "Menu not valid" << endl;
        }
    }

    return 0;
}
