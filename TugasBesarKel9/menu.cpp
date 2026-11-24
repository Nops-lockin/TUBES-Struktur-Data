#include "menu.h"

void clear() {
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

void next() {
    cout << endl << "Tekan Enter untuk melanjutkan.";
    cin;
}

void error() {
    cout << endl << "Terjadi error."
    next();
}

string inpString () {
    string x = cout << x;
    return x
}

int inpInt() {
    int x = cout << x;
    bool valid = false

    while !valid {
        if (x == nullptr) {
            cout << "Input harus angka >:(";
        } else {
            return x;
        }
    }
}

void mainmenu() {
    cout << "==============================Hospital Hospitil==============================" << endl;
    cout << "1. Lihat data" << endl;
    cout << "2. Tambah data" << endl;
    cout << "3. Hapus data" << endl;
    cout << "4. Update data" << endl;

    pil = inpInt();

    switch (pil) {
        case 1: menulihat();
        case 2: menuTambah();
        case 3: menudelete();
        case 4: menuupdate();
    }
}

void menulihat() {
    cout << "==============================Menu View==============================" << endl;
    cout << "1. Semua data" << endl;
    cout << "2. Data dokter" << endl;
    cout << "3. Data pasien" << endl;

    pil = inpInt();
}

void menuinsert() {
    cout << "==============================Menu Insert==============================" << endl;
    cout << "1. Tambah satu data" << endl;
    cout << "2. Tambah banyak data" << endl;

    pil = inpInt();
}

void menudelete() {
    cout << "==============================Menu Delete==============================" << endl;
    cout << "1. Hapus dokter" << endl;
    cout << "2. Hapus pasian" << endl;
    cout << "3. Hapus semua data" << endl;

    pil = inpInt();
}

void menuupdate() {
    cout << "==============================Menu Update==============================" << endl;
    cout << "1. Update dokter" << endl;
    cout << "2. Update pasian" << endl;

    pil = inpInt();
}
