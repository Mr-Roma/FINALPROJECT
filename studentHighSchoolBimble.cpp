#include "header.h"

void createListSma(listSma &Lsa){
    firstSma(Lsa) = NULL;
}
void createListBimbel(listBimbel &Lb){
    firstBimbel(Lb) = NULL;
}

adrSma createElmSma (infotypeSma x){
    adrSma SMA = new elmSma;
    infoSma(SMA) = x;
    firstSiswa(SMA) = NULL;
    nextSma(SMA) = NULL;
    return SMA;
}
adrSiswa createElmSiswa (infotypeSiswa x){
    adrSiswa S = new elmSiswa;
    infoSiswa(S) = x;
    nextSiswa(S) = NULL;
    S->bimbel = NULL;
    return S;
}
adrBimbel createElmBimbel (infotypeBimbel x){
    adrBimbel B = new elmBimbel;
    infoBimbel(B) = x;
    nextBimbel(B) = NULL;
    return B;
}


void insertFirstSma(listSma &Lsa, adrSma SMA){
    if(firstSma(Lsa) == NULL){
        firstSma(Lsa) = SMA;
    }else{
        nextSma(SMA) = firstSma(Lsa);
        firstSma(Lsa) = SMA;
    }
}
void insertLastSma(listSma &Lsa, adrSma SMA){
    adrSma Q;
    if(firstSma(Lsa) == NULL){
        firstSma(Lsa) = SMA;
    }else{
        Q = firstSma(Lsa);
        while(nextSma(Q) != NULL){
            Q = nextSma(Q);
        }
        nextSma(Q) = SMA;
    }
}
void insertLastSiswa(adrSma &Lsa, adrSiswa S){
    adrSiswa Q;

    if(firstSiswa(Lsa) == NULL){
        firstSiswa(Lsa) = S;
    }else{
        Q = firstSiswa(Lsa);
        while(nextSiswa(Q) != NULL){
            Q = nextSiswa(Q);
        }
        nextSiswa(Q) = S;
    }
}
void insertlastBimbel(listBimbel &Lb, adrBimbel B){
    if(firstBimbel(Lb) == NULL){
        firstBimbel(Lb) = B;
    }else{
        adrBimbel Q = firstBimbel(Lb);
        while(nextBimbel(Q) != NULL){
            Q = nextBimbel(Q);
        }
        nextBimbel(Q) = B;
    }
}
void insertFirstBimbel(listBimbel &Lb, adrBimbel B){
    if(firstBimbel(Lb) == NULL){
        firstBimbel(Lb) = B;
    }else{
        nextBimbel(B) = firstBimbel(Lb);
        firstBimbel(Lb) = B;
    }
}

adrSiswa searchSmaSiswa(listSma Lsa, string nama){
    adrSma P = firstSma(Lsa);
    while(P != NULL){
         adrSiswa S = firstSiswa(P);
         while(S!=NULL){
            if(infoSiswa(S).nama == nama){
                return S;
            }
            S = nextSiswa(S);
        }
        P = nextSma(P);
    }
    return NULL;
} // Mencari siswa di seluruh sma, return address siswa jika ketemu

adrSiswa searchSiswaSma(adrSma p, string nama){
    adrSiswa S = firstSiswa(p);
    while(S!=NULL){
        if(infoSiswa(S).nama == nama){
            return S;
        }
        S = nextSiswa(S);
    }
    return NULL;
} // Mencari siswa di sma tertentu, return address siswa�jika�ketemu

adrSma searchSma(listSma Lsa, string nama) {
    adrSma p = firstSma(Lsa);

    if (p == NULL) {
        return NULL;
    } else {
        while (p != NULL) {
            if (infoSma(p).nama == nama) {
                return p;
            }
            p = nextSma(p);
        }
        return NULL;
    }
}
adrBimbel searchBimbel(listBimbel Lb, string nama) {
    adrBimbel p = firstBimbel(Lb);

    if (p == NULL) {
        return NULL;
    } else {
        while (p != NULL) {
            if (infoBimbel(p).nama == nama) {
                return p;
            }
            p = nextBimbel(p);
        }
        return NULL;
    }
}

void countSiswaSma(listSma Lsa){
    int i;
    adrSma P = firstSma(Lsa);
    while(P != NULL){
        i = 0;
        adrSiswa S = firstSiswa(P);
        while(S != NULL){
            i++;
        }
        S = nextSiswa(S);
    }
    cout << "High School" << infoSma(P).nama << "have" << i << "Students" << endl;
    P = nextSma(P);
} //menghitung siswa berdasarkan SMA, return jumlah siswa di SMA itu

void countSiswaBimbel(listBimbel Lb, listSma Lsa){
    int i;
    adrBimbel B = firstBimbel(Lb);
    while(B != NULL){
        adrSma P = firstSma(Lsa);
        while(P != NULL){
            i = 0;
            adrSiswa S = firstSiswa(P);
            while(S != NULL){
                if(B == S->bimbel){
                    i++;
                }
              S = nextSiswa(S);
            }
            P = nextSma(P);
        }
        cout << "Bimble" << infoBimbel(B).nama << "have" << i << "Students" << endl;
        B = nextBimbel(B);
    }
} //menghitung siswa berdasarkan bimbel, return jumlahnya

int discount(adrSiswa siswa){
    if (siswa->bimbel != NULL) {
        int harga = infoBimbel(siswa->bimbel).harga;
            if (siswa->infoSiswa.ranking == 1) {
                harga = 0.7 * harga ;
            } else if (siswa->infoSiswa.ranking == 2) {
                harga = 0.75 * harga;
            } else if (siswa->infoSiswa.ranking == 3) {
                harga = 0.8 * harga;
            }
            return harga;
    } else {
        cout << endl << "Student not exist in Bimble" << endl;
        return 0;
    }

}

adrBimbel urutanBimbel(listBimbel Lb, int x){
    adrBimbel b = firstBimbel(Lb);
    for (int i = 0; i < x; i ++) {
        b = nextBimbel(b);
    }
    return b;
}

void deleteFirstSma(listSma &Lsa, adrSma &p){
    adrSiswa q;
    if(firstSma(Lsa) == NULL){
        cout << "There is no data" << endl;
    } else if(nextSma(firstSma(Lsa)) == NULL) {
        while(firstSiswa(firstSma(Lsa)) != NULL) {
            deleteFirstSiswa(firstSma(Lsa), q);
        }

        p = firstSma(Lsa);
        firstSma(Lsa) = NULL;
    } else {
        while(firstSiswa(firstSma(Lsa)) != NULL) {
            deleteFirstSiswa(firstSma(Lsa), q);
        }

        p = firstSma(Lsa);
        firstSma(Lsa) = nextSma(p);
        nextSma(p) = NULL;
    }
}

void deleteFirstSiswa(adrSma &Lsi, adrSiswa &p){
    if(firstSiswa(Lsi) == NULL){
        cout << "There is no data" << endl;
    }else if(nextSiswa(firstSiswa(Lsi)) == NULL){
        p = firstSiswa(Lsi);
        cout << infoSiswa(p).nama << endl;
        firstSiswa(Lsi) = NULL;
    }else{
        p = firstSiswa(Lsi);
        firstSiswa(Lsi) = nextSiswa(p);
        nextSiswa(p) = NULL;

    }
}

void deleteFirstBimbel(listBimbel &Lb, adrBimbel &p){
    if(firstBimbel(Lb) == NULL){
        cout << "There is no data" << endl;
    }else if(nextBimbel(firstBimbel(Lb)) == NULL){
        p = firstBimbel(Lb);
        firstBimbel(Lb) = NULL;
    }else{
        p = firstBimbel(Lb);
        firstBimbel(Lb) = nextBimbel(p);
        nextBimbel(p) = NULL;

    }
}

void deleteLastSma(listSma &Lsa, adrSma &p){
    adrSiswa q;

    if(firstSma(Lsa) == NULL){
        cout << "There is no data" << endl;
    }else if(nextSma(firstSma(Lsa)) == NULL){
        while(firstSiswa(nextSma(firstSma(Lsa))) != NULL) {
            deleteFirstSiswa(nextSma(firstSma(Lsa)), q);
        }

        p = firstSma(Lsa);
        firstSma(Lsa) = NULL;
    }else{
        while(firstSiswa(nextSma(firstSma(Lsa))) != NULL) {
            deleteFirstSiswa(nextSma(firstSma(Lsa)), q);
        }

        adrSma Q = firstSma(Lsa);
        while(nextSma(nextSma(Q)) != NULL){
            Q = nextSma(Q);
        }
        nextSma(Q) = NULL;
    }
}


void deleteLastSiswa(adrSma &Lsa, adrSiswa &p) {
    if (firstSiswa(Lsa) == NULL) {
        cout << "There is no data" << endl;
    } else if (nextSiswa(firstSiswa(Lsa)) == NULL) {
        p = firstSiswa(Lsa);
        firstSiswa(Lsa) = NULL;
    } else {
        adrSiswa Q = firstSiswa(Lsa);
        while (nextSiswa(nextSiswa(Q)) != NULL) {
            Q = nextSiswa(Q);
        }
        p = nextSiswa(Q);
        nextSiswa(Q) = NULL;
    }
}


void deleteLastBimbel(listBimbel &Lb, adrBimbel &p){
    if(firstBimbel(Lb) == NULL){
        cout << "There is no data" << endl;
    }else if(nextBimbel(firstBimbel(Lb))== NULL){
        p = firstBimbel(Lb);
        firstBimbel(Lb) = NULL;
    }else{
        adrBimbel Q = firstBimbel(Lb);
        while(nextBimbel(nextBimbel(Q)) != NULL){
            Q = nextBimbel(Q);
        }
        nextBimbel(Q) = NULL;
    }
}

void deleteAfterSma(adrSma &p, adrSma &prec, adrSma &del){

    adrSiswa q;
    while(firstSiswa(p) != NULL) {
        deleteFirstSiswa(p, q);
    }

    cout << "Enter" << endl;

    nextSma(prec) = nextSma(p);
    nextSma(p) = NULL;
    del = p;
}

void deleteAfterSiswa(adrSiswa &p, adrSiswa &prec, adrSiswa &del) {
    nextSiswa(prec) = nextSiswa(p);
    nextSiswa(p) = NULL;
    del = p;
}

void deleteAfterBimbel(adrBimbel &p, adrBimbel &prec, adrBimbel &del) {
    nextBimbel(prec) = nextBimbel(p);
    nextBimbel(p) = NULL;
    del = p;
}

void showAllSiswa(listSma Lsa){
    adrSma P = firstSma(Lsa);
    while(P != NULL){
        cout << endl << "==High School " << infoSma(P).nama << "==" << endl;
        adrSiswa S = firstSiswa(P);
        while(S != NULL){
            cout << endl << "Student Name : " << infoSiswa(S).nama << endl;
            cout << "Sex : " << infoSiswa(S).jk << endl;
            cout << "Major : " << infoSiswa(S).jurusan << endl;
            cout << "Age : " <<  infoSiswa(S).umur << endl;
            cout << "Rank : " << infoSiswa(S).ranking << endl;
            cout << "Bimble : ";

            if (S->bimbel != NULL) {
                cout << infoBimbel(S->bimbel).nama << endl;
            } else {
                cout << "There is no data" << endl;
            }
            S = nextSiswa(S);
        }
        P = nextSma(P);
    }
}
void DisconnectStudentBimble(listSma &Lsa, listBimbel &Lb, adrBimbel deletedBimbel) {
    adrSma currentSma = firstSma(Lsa);

    // Iterate through all SMAs
    while (currentSma != NULL) {
        adrSiswa currentSiswa = firstSiswa(currentSma);

        // Iterate through all students in the current SMA
        while (currentSiswa != NULL) {
            // Check if the student's bimble is the one being deleted
            if (currentSiswa->bimbel == deletedBimbel) {
                currentSiswa->bimbel = NULL; // Disconnect the student from the deleted bimble
            }

            currentSiswa = nextSiswa(currentSiswa);
        }

        currentSma = nextSma(currentSma);
    }
}

void showAllSMA(listSma Lsa){
    adrSma P = firstSma(Lsa);
    while(P != NULL){

        cout << endl << "High School : " << infoSma(P).nama << endl;
        cout << "High School Address : " << infoSma(P).alamat << endl;
        cout << "High School capacities : " << infoSma(P).kapasitas << endl;

        int jumlah = 0;
        adrSiswa S = firstSiswa(P);
        while(S != NULL){
            jumlah++;
            S = nextSiswa(S);
        }
        cout << "Total Students : " << jumlah << endl;
        P = nextSma(P);
    }
}

void showAllBimbel(listBimbel Lb, listSma Lsa){
    adrBimbel B = firstBimbel(Lb);
    while(B != NULL){

        cout << endl << "Bimble Name : " << infoBimbel(B).nama << endl;
        cout << "Bimble Major : " << infoBimbel(B).jurusan << endl;
        cout << "Bimble Price : " << infoBimbel(B).harga << endl;
        int counts = 0;

        adrSma P = firstSma(Lsa);
        while(P != NULL){
            adrSiswa S = firstSiswa(P);
            while(S != NULL){
                if(S->bimbel == B){
                    counts++;
                }
                S = nextSiswa(S);
            }
            P = nextSma(P);
        }
        cout << "Total members : " << counts << endl;
        B = nextBimbel(B);
    }
}



void showSMAandSiswa(adrSma sma){
    adrSiswa S = firstSiswa(sma);

    if (S != NULL) {
        cout << endl << "Student list on " << infoSma(sma).nama << endl;
        while(S != NULL){
            cout << endl << "Student Name : " << infoSiswa(S).nama << endl;
            cout << "Sex : " << infoSiswa(S).jk << endl;
            cout << "Major : " << infoSiswa(S).jurusan << endl;
            cout << "Age : " <<  infoSiswa(S).umur << endl;
            cout << "Rank : " << infoSiswa(S).ranking << endl;
            cout << "Bimble : ";

            if (S->bimbel != NULL) {
                cout << infoBimbel(S->bimbel).nama << endl;
            } else {
                cout << "There is no data" << endl;
            }
            S = nextSiswa(S);
        }
    } else {
        cout << endl << "There is no student are exist on" << infoSma(sma).nama << endl;
    }
}

void showBimbelandSiswa(listBimbel Lb, listSma Lsa){
    adrBimbel B = firstBimbel(Lb);
    while(B != NULL){
        // Display tutoring center information
        cout << endl << "===Bimble " << infoBimbel(B).nama << "===" << endl;

        // Iterate through SMAs
        adrSma P = firstSma(Lsa);
        while(P != NULL){
            // Iterate through students in each SMA
            adrSiswa S = firstSiswa(P);
            while(S != NULL){
                if(S->bimbel == B){
                    // Display student information related to the tutoring center
                    cout << "- Name: " << infoSiswa(S).nama << ", Rank: " << infoSiswa(S).ranking << ", High School: " << infoSma(P).nama << endl;
                }
                S = nextSiswa(S);
            }
            P = nextSma(P);
        }
        B = nextBimbel(B);
    }
}

void showAnggotaBimbel(adrBimbel bimbel, listSma Lsa) {
    cout << endl << "Bimble Members" << infoBimbel(bimbel).nama << endl;

    adrSma p = firstSma(Lsa);

    if (p != NULL) {
        while(p != NULL) {
            adrSiswa s = firstSiswa(p);
            while(s != NULL) {
                if(s->bimbel == bimbel) {
                    cout << "- Name: " << infoSiswa(s).nama << ", Rank: " << infoSiswa(s).ranking << ", High School: " << infoSma(p).nama << endl;
                }
                s = nextSiswa(s);
            }
            p = nextSma(p);
        }
    } else {
        cout << endl << "Bimble didn't have members " << endl;
    }
}

void deleteSMA(listSma &Lsa, adrSma &choosenSMA) {
    adrSma lastSMA, precSMA;
    // Mencari SMA Terakhir;
    lastSMA = firstSma(Lsa);
    while(nextSma(lastSMA) != NULL) {
        lastSMA = nextSma(lastSMA);
    }

    // Mencari posisi SMA yang akan dihapus
    if (choosenSMA == firstSma(Lsa)) {
        deleteFirstSma(Lsa, choosenSMA); // Jika posisi SMA diawal
    } else if (choosenSMA == lastSMA) {
        deleteLastSma(Lsa, choosenSMA); // Jika Posisi SMA diakhir
    } else {
        // Mencari prec SMA
        precSMA = firstSma(Lsa);
        while(nextSma(precSMA) != choosenSMA) {
            precSMA = nextSma(precSMA);
        }
        deleteAfterSma(choosenSMA, precSMA, choosenSMA); // Jika posisi SMA ditengah
    }
}


void deleteSiswa(adrSma &choosenSMA, adrSiswa &choosenSiswa) {
    adrSiswa delSiswa, lastSiswa, precSiswa;
    // Mencari Siswa Terakhir
    lastSiswa = firstSiswa(choosenSMA);
    while(nextSiswa(lastSiswa) != NULL) {
        lastSiswa = nextSiswa(lastSiswa);
    }

    // Mencari posisi Siswa yang akan dihapus
    if (choosenSiswa == firstSiswa(choosenSMA)) {
        deleteFirstSiswa(choosenSMA, delSiswa); // JIka posisi Siswa diawal
    } else if (choosenSiswa == lastSiswa) {
        deleteLastSiswa(choosenSMA, delSiswa); // Jika posisi Siswa diakhir
    } else {
        // Mencari prec SMA
        precSiswa = firstSiswa(choosenSMA);
        while(nextSiswa(precSiswa) != choosenSiswa) {
            precSiswa = nextSiswa(precSiswa);
        }
        deleteAfterSiswa(choosenSiswa, precSiswa, delSiswa); // Jika posisi Siswa ditengah
    }

}

void deleteBimbel(listBimbel &Lb, adrBimbel &choosenBimbel) {
    adrBimbel delBimbel, lastBimbel, precBimbel;
    listSma Lsa;

    // Mencari Bimbel terakhir
    lastBimbel = firstBimbel(Lb);
    while(nextBimbel(lastBimbel) != NULL) {
        lastBimbel = nextBimbel(lastBimbel);
    }

    // Mencari posisi Bimbel yang akan dihapus
    if(choosenBimbel == firstBimbel(Lb)) {
        deleteFirstBimbel(Lb, delBimbel);

    } else if (choosenBimbel == lastBimbel) {
        deleteLastBimbel(Lb, delBimbel);

    } else {
        precBimbel = firstBimbel(Lb);
        while(nextBimbel(precBimbel) != choosenBimbel) {
            deleteAfterBimbel(choosenBimbel, precBimbel, delBimbel);

        }
    }

}


