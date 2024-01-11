#include "header.h"


int menu(){
    int x;
    cout << "[<>]=====================================================================[<>]" << endl;
	cout << "||         WELCOME TO STUDENT MANAGEMENT IN HIGH SCHOOL APPLICATION        ||"<< endl;
	cout << "[<>]=====================================================================[<>]" << endl;
    cout << "1. Input the Data" << endl; // insert
    cout << "2. Delete the Data" << endl; //delete
    cout << "3. Search the Data" << endl; //search
    cout << "4. Show data" << endl; //show
    cout << "5. Link to Bimble" << endl;
    cout << "6. Discount Details" << endl;
    cout << "7. Exit from the App" << endl;
    cout << "Input the Menu : "; cin >> x;


    return x;
}

void menuInput(listSma &Lsa, listBimbel &Lb) {

    int x;
    adrSma newElmSMA, choosenSMA;
    adrSiswa newElmSiswa;
    adrBimbel newElmBimbel;
    infotypeSma newSMA;
    infotypeSiswa newSiswa;
    infotypeBimbel newBimbel;

    bool loopMenu = true;
    while(loopMenu) {
        cout << endl << "============INPUT MENU============" << endl;
        cout << "1. Input the High School Data" << endl;
        cout << "2. Input the Student Data" << endl;
        cout << "3. Input the Bimble Data " << endl;
        cout << "4. Return to the Menu" << endl;

        cout << "Enter the Menu : "; cin >> x;

        if (x == 1){
            inputSMA(newSMA);
            newElmSMA = createElmSma(newSMA);
            insertLastSma(Lsa, newElmSMA);
        } else if (x == 2) {
            inputSiswa(newSiswa);
            newElmSiswa = createElmSiswa(newSiswa);
            cout << "===Choose High school, that want to choose: " << infoSiswa(newElmSiswa).nama << "===" << endl;
            choosenSMA = pilihSma(Lsa);
            insertLastSiswa(choosenSMA, newElmSiswa);
        } else if (x == 3) {
            inputBimbel(newBimbel);
            newElmBimbel = createElmBimbel(newBimbel);
            insertFirstBimbel(Lb, newElmBimbel);
        }else if(x == 4) {
            loopMenu = false;
        }
    }
}

void menuDelete(listSma Lsa, listBimbel Lb){
    adrSma choosenSMA;
    adrBimbel choosenBimbel;
    adrSiswa choosenSiswa;

    bool loopMenu = true;
    while(loopMenu) {
        int x;
        cout << endl << "============DELETE MENU============" << endl;
        cout << "1. Delete High School Data" << endl;
        cout << "2. Delete Student Data" << endl;
        cout << "3. Delete Bimble Data" << endl;
        cout << "4. Return to the menu" << endl;

        cout << "Input the Menu : "; cin >> x;

        if (x == 1) {
            // Memilih SMA yang akan dipilih
            choosenSMA = pilihSma(Lsa);
            if (choosenSMA != NULL) {
                // Menghapus SMA
                deleteSMA(Lsa, choosenSMA);
            }
        } else if (x == 2) {
            // Memilih SMA yang akan dipilih
            choosenSMA = pilihSma(Lsa);
            if (choosenSMA != NULL) {
                // Memilih Siswa berdasarkan SMA yang dipilih
                choosenSiswa = pilihSiswa(choosenSMA);
                if (choosenSiswa != NULL) {
                    // Menghapus Siswa
                    deleteSiswa(choosenSMA, choosenSiswa);
                }
            }
        } else if (x == 3) {
            // Memilih bimbel yang akan dipilih
            choosenBimbel = pilihBimbel(Lb);
            if (choosenBimbel != NULL) {
               // Menghapus bimbel
            deleteBimbel(Lb, choosenBimbel);
            }
        } else if (x == 4) {
            loopMenu = false;
        }
    }
}

void menuCari(listSma Lsa, listBimbel Lb){
    string keyword;
    adrSma sma;
    adrSiswa siswa;
    adrBimbel bimbel;
    int x;

    bool loopMenu = true;
    while(loopMenu) {
        cout << endl << "============SEARCH MENU============" << endl;
        cout << "1. Search the Hight School Data" << endl;
        cout << "2. Search Student in especific High School" << endl;
        cout << "3. Search Student data in all High School" << endl;
        cout << "4. Search for Bimble Data" << endl;
        cout << "5. Return to Menu" << endl;

        cout << "Input the Menu : "; cin >> x;

        if (x == 1) {
            cout << "Input the High School name that wanna search for : "; cin >> keyword;
            sma = searchSma(Lsa, keyword);

            if (sma != NULL) {
                cout << endl << "High School found!" << endl;
                cout << "High School Name : " << infoSma(sma).nama << endl;
                cout << "High School Adrress : " << infoSma(sma).alamat << endl;
                cout << "High School Capacities: " << infoSma(sma).kapasitas << endl;
            } else {
                cout << endl << "High School not found!" << endl;
            }

        } else if (x == 2) {
            cout << endl << "===Choose High School===" << endl;
            sma = pilihSma(Lsa);

            cout << endl << "Student name that wanna search in " << infoSma(sma).nama << " : ";
            cin >> keyword;

            siswa = searchSiswaSma(sma, keyword);

            if (siswa != NULL) {
                cout << endl << "Student found!" << endl;
                cout << "Student Name : " << infoSiswa(siswa).nama << endl;
                cout << "Sex : " << infoSiswa(siswa).jk << endl;
                cout << "Major : " << infoSiswa(siswa).jurusan << endl;
                cout << "Age : " <<  infoSiswa(siswa).umur << endl;
                cout << "Ranking : " << infoSiswa(siswa).ranking << endl;
                cout << "Bimble : ";

                if (siswa->bimbel != NULL) {
                    cout << infoBimbel(siswa->bimbel).nama << endl;
                } else {
                    cout << "Not exist!" << endl;
                }
            } else {
                cout << "Student not found!" << endl;
            }
        } else if (x == 3) {
            cout << endl << "Student Name that gonna search : ";
            cin >> keyword;

            siswa = searchSmaSiswa(Lsa, keyword);

            if (siswa != NULL) {
                cout << endl << "Student Found!" << endl;
                cout << "Student Name : " << infoSiswa(siswa).nama << endl;
                cout << "Sex: " << infoSiswa(siswa).jk << endl;
                cout << "Major : " << infoSiswa(siswa).jurusan << endl;
                cout << "Age : " <<  infoSiswa(siswa).umur << endl;
                cout << "Ranking : " << infoSiswa(siswa).ranking << endl;
                cout << "Bimble : ";

                if (siswa->bimbel != NULL) {
                    cout << infoBimbel(siswa->bimbel).nama << endl;
                } else {
                    cout << "Not Exist" << endl;
                }
            } else {
                cout << "Student not Found!" << endl;
            }

        } else if (x == 4) {
            cout << endl << "Bimble name that wanna search for : ";
            cin >> keyword;

            bimbel = searchBimbel(Lb, keyword);

            if (bimbel != NULL) {
                cout << endl << "Bimble found!" << endl;
                cout << "Bimble Name : " << infoBimbel(bimbel).nama << endl;
                cout << "Bimble Major : " << infoBimbel(bimbel).jurusan << endl;
                cout << "Bimble Price : " << infoBimbel(bimbel).harga << endl;
            } else {
                cout << endl << "Bimble not found!" << endl;
            }

        } else if (x == 5) {
            loopMenu = false;
        } else {
            cout << endl << "Output not sinchronize!" << endl;
        }
    }

}

void menuShow(listSma Lsa, listBimbel Lb){
    adrSma sma;
    adrBimbel bimbel;

    int x;

    bool loopMenu = true;
    while(loopMenu) {
        cout << endl << "============SHOW MENU============" << endl;
        cout << "1. Show High School Data" << endl;
        cout << "2. Show Student Data" << endl;
        cout << "3. Show Bimble Data" << endl;
        cout << "4. Show Student Data in specific High School" << endl;
        cout << "5. Show Student Data in specific Bimble" << endl;
        cout << "6. Show all member in Bimble Data" << endl;
        cout << "7. Kembali ke Menu" << endl;

        cout << "Input the Menu : "; cin >> x;

        if (x == 1){
            showAllSMA(Lsa);
        } else if (x == 2) {
            showAllSiswa(Lsa);
        } else if (x == 3) {
            showAllBimbel(Lb, Lsa);
        } else if (x == 4) {
            cout << endl << "Choose High School that wanna printed the Student Data" << endl;
            sma = pilihSma(Lsa);

            if(sma != NULL) {
                showSMAandSiswa(sma);
            } else {
                cout << "High School List empty!" << endl;
            }

        } else if (x == 5) {
            cout << endl << "Choose Bimble that wanna printed the Student Data" << endl;
            bimbel = pilihBimbel(Lb);

            if(bimbel != NULL) {
                showAnggotaBimbel(bimbel, Lsa);
            } else {
                cout << endl << "Bimble list empty!" << endl;
            }

        } else if (x == 6) {
            showBimbelandSiswa(Lb, Lsa);
        } else if (x == 7) {
            loopMenu = false;
        }
    }
}


void inputSMA(infotypeSma &SMA){
    cout << endl << "============INPUT HIGH SCHOOL============" << endl;
    cout << "High School Name : ";
    cin >> SMA.nama;
    cout << "High School Address : ";
    cin >> SMA.alamat;
    cout << "High School Capacities : ";
    cin >> SMA.kapasitas;
}

void inputSiswa(infotypeSiswa &S){
    cout << endl << "============INPUT STUDENT============" << endl;
    cout << "Student Name: ";
    cin >> S.nama;
    cout << "Age: ";
    cin >> S.umur;
    cout << "Sex: ";
    cin >> S.jk;
    cout << "Major: ";
    cin >> S.jurusan;
    cout << "Ranking: ";
    cin >> S.ranking;

}

void inputBimbel(infotypeBimbel &B){
    cout << endl << "============INPUT BIMBLE============" << endl;
    cout << "Bimble Name: ";
    cin >> B.nama;
    cout << "Bimble Major: ";
    cin >> B.jurusan;
    cout << "Bimnble Price: ";
    cin >> B.harga;
}

adrSma pilihSma(listSma Lsa) {
    adrSma p = firstSma(Lsa);
    int x;
    int i = 1;

    if (p == NULL) {
        cout << endl << "High School List empty!" << endl;
        return NULL;
    } else {
        while(p != NULL) {
            cout << i << ". " << infoSma(p).nama << endl;
            p = nextSma(p);
            i++;
        }

        cout << "Choose High School Number : "; cin >> x;

        i = 1;
        p = firstSma(Lsa);
        while(i < x && p != NULL) {
            p = nextSma(p);
            i++;
        }
        return p;
    }
}

adrSiswa pilihSiswa(adrSma p) {
    int x;
    int i = 1;

    adrSiswa q = firstSiswa(p);
    if (q == NULL) {
        cout << endl << "Student List empty!" << endl;
        return NULL;
    } else {
        while(q != NULL) {
            cout << i << ". " << infoSiswa(q).nama << endl;
            q = nextSiswa(q);
            i++;
        }

        cout << "Choose Student Number : "; cin >> x;

        i = 0;
        q = firstSiswa(p);
        while (i < x-1 && q != NULL) {
            q = nextSiswa(q);
            i++;
        }

        return q;
    }
}

adrBimbel pilihBimbel(listBimbel Lb) {
    int x;
    int i = 1;

    adrBimbel p = firstBimbel(Lb);

    if (p == NULL) {
        cout << endl << "Bimble list empty!" << endl;
        return NULL;
    } else {
        while(p != NULL) {
            cout << i << ". " << infoBimbel(p).nama << endl;
            p = nextBimbel(p);
            i++;
        }

        cout << "Choose Bimble Number : "; cin >> x;

        i = 0;
        p = firstBimbel(Lb);
        while(i<x-1 && p != NULL) {
            p = nextBimbel(p);
            i++;
        }

        return p;
    }
}

void menuDiscount(listSma Lsa){
    cout << endl << "============DISCOUNT MENU============" << endl;
    cout << endl << "Choose High School" << endl;
    adrSma sma = pilihSma(Lsa);

    cout << endl << "Choose Student" << endl;
    adrSiswa siswa = pilihSiswa(sma);

    int hargaDibayar = discount(siswa);

    if (hargaDibayar != 0) {
        int hargaSeharusnya = infoBimbel(siswa->bimbel).harga;
        int diskon = hargaSeharusnya - hargaDibayar;

        cout << endl << "Bimble Name : " << infoBimbel(siswa->bimbel).nama << endl;
        cout << "Price to Pay: " << hargaDibayar << endl;
        cout << "Price before discount : " << hargaSeharusnya << endl;
        cout << "Discount got : " << diskon << endl;
    }

}

void menuBimbelSesuai(listSma &Lsa, listBimbel &Lb) {
    string nama;
    int i = 1;
    int x;
    adrSma sma;
    adrBimbel p;
    adrSiswa siswa;

    cout << endl << "============BIMBLE DATA============" << endl;

    cout << endl << "Choose High School" << endl;
    sma = pilihSma(Lsa);

    cout << endl << "Choose Student from "<< infoSma(sma).nama << endl;

    siswa = pilihSiswa(sma);

    string jurusan = infoSiswa(siswa).jurusan;
    cout << endl << "Bimble that can follow is : " << endl;

    p = firstBimbel(Lb);
    while (p != NULL){
        if (infoBimbel(p).jurusan == jurusan) {
            cout << i << ". " <<infoBimbel(p).nama << endl;
        }
        p = p->nextBimbel;
        i++;
    }

    cout << "Bimble order that choose: ";
    cin >> x;

    adrBimbel b = urutanBimbel(Lb, x-1);
    siswa -> bimbel = b;

    cout << endl << infoSiswa(siswa).nama << " Exist in Bimble " << infoBimbel(siswa->bimbel).nama << endl;
}


