#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

#define nextSma(P) P->nextSma
#define nextSiswa(P) P->nextSiswa
#define nextBimbel(P) P->nextBimbel

#define firstSma(L) L.firstSma
#define firstSiswa(L) L->firstSiswa
#define firstBimbel(L) L.firstBimbel

#define infoSma(P) P->infoSma
#define infoSiswa(P) P->infoSiswa
#define infoBimbel(P) P->infoBimbel

using namespace std;

struct infotypeBimbel{
    string nama, jurusan;
    int harga;
};


typedef struct elmBimbel *adrBimbel;

struct elmBimbel{
    infotypeBimbel infoBimbel;
    adrBimbel nextBimbel;
};

struct listBimbel{
    adrBimbel firstBimbel;
};

struct infotypeSiswa{
    string nama, jk, jurusan;
    int umur, ranking;
    adrBimbel bimbel;
};

typedef struct elmSiswa *adrSiswa;

struct elmSiswa{
    infotypeSiswa infoSiswa;
    adrSiswa nextSiswa;
    adrBimbel bimbel;
};

struct infotypeSma{
    string nama, alamat;
    int kapasitas;
};

typedef struct elmSma *adrSma;

struct elmSma{
    infotypeSma infoSma;
    adrSma nextSma;
    adrSiswa firstSiswa;
};

struct listSma{
    adrSma firstSma;
};

void createListSma(listSma &Lsa);
void createListBimbel(listBimbel &Lb);

void daftarBimbel(adrSiswa siswa, adrBimbel bimbel); // connect siswa ke bimbel yg dipilih


adrSma createElmSma (infotypeSma x);
adrSiswa createElmSiswa (infotypeSiswa x);
adrBimbel createElmBimbel (infotypeBimbel x);

void insertFirstSma(listSma &Lsa, adrSma p);
void insertLastSma(listSma &Lsa, adrSma p);
void insertAfterSma(listSma &Lsa, adrSma p, adrSma prec);
void insertLastSiswa(adrSma &Lsa, adrSiswa p);
void insertlastBimbel(listBimbel &Lsi, adrBimbel p);
void insertFirstBimbel(listBimbel &Lb, adrBimbel p);

void deleteFirstSma(listSma &Lsa, adrSma &p);
void deleteLastSma(listSma &Lsa, adrSiswa p);
void deleteAfterSma(adrSma &p, adrSma &prec, adrSma &del);
void deleteFirstSiswa(adrSma &Lsi, adrSiswa &p);
void deleteAfterSiswa(adrSiswa &p, adrSiswa &prec, adrSiswa &del);
void deleteLastSiswa(adrSma &Lsa, adrSiswa &p);
void deletelastBimbel(listBimbel &Lb, adrBimbel &p);
void deleteFirstBimbel(listBimbel &Lb, adrBimbel &p);
void deleteAfterBimbel(listBimbel &Lb, adrBimbel &p, adrBimbel &prec);

void showAllSiswa(listSma Lsa); // 2
void DisconnectStudentBimble(listBimbel Lb, listSma LS, adrBimbel deletedBimbel);
void showAllSMA(listSma Lsa); // 1
void showAllBimbel(listBimbel Lb, listSma Lsa); // 3
void showSMAandSiswa(adrSma sma); //4
void showBimbelandSiswa(listBimbel Lb, listSma Lsa); // 6
void showAnggotaBimbel(adrBimbel bimbel, listSma Lsa); // 5

adrSma searchSma(listSma Lsa, string nama);
adrBimbel searchBimbel(listBimbel Lb, string nama);
adrSiswa searchSmaSiswa(listSma lsa, string nama); // Mencari siswa di seluruh sma, return address siswa jika ketemu
adrSiswa searchSiswaSma(adrSma p, string nama); // Mencari siswa di sma tertentu, return address siswa�jika�ketemu

void countSiswaSma(listSma Lsa); //menghitung siswa berdasarkan SMA, return jumlah siswa di SMA itu
void countSiswaBimbel(listBimbel Lb, listSma Lsa); //menghitung siswa berdasarkan bimbel, return jumlahnya

int discount(adrSiswa siswa);

int menu();
void menuCari(listSma Lsa, listBimbel Lb);
void menuDelete(listSma Lsa, listBimbel Lb);
void menuInput(listSma &Lsa, listBimbel &Lb);
void menuShow(listSma Lsa, listBimbel Lb);

void deleteSMA(listSma &Lsa, adrSma &choosenSMA);
void deleteSiswa(adrSma &choosenSMA, adrSiswa &choosenSiswa);
void deleteBimbel(listBimbel &Lb, adrBimbel &choosenBimbel);

void inputSMA(infotypeSma &x);
void inputSiswa(infotypeSiswa &x);
void inputBimbel(infotypeBimbel &B);
adrSma pilihSma(listSma Lsa);
adrSiswa pilihSiswa(adrSma p);
adrBimbel pilihBimbel(listBimbel Lb);
void menuDiscount(listSma Lsa);
void menuBimbelSesuai(listSma &Lsa, listBimbel &Lb);
adrBimbel urutanBimbel(listBimbel Lb, int x);



#endif // HEADER_H_INCLUDED
