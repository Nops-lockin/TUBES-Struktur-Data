#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

struct dokter {
    string kode;
    string nama;
    string spesialis;
    int maxPasien;
    int jumlahPasien;
};

struct pasien {
    string kode;
    string nama;
    int umur;
    string diagnosa;

};

typedef struct elmDokter *almDokter;
typedef struct elmPasien *almPasien;

struct elmDokter {
    dokter info;
    almDokter next;
    almDokter prev;
    almPasien firstPasien;
};

struct elmPasien {
    pasien info;
    almPasien next;
    almPasien prev;
};

struct listDokter {
    elmDokter first;
    elmDokter last;
};


void createNewList(listDokter &L);
almDokter createElmDokter(string kode, nama, spesialis, int maxPasien);
almPasien createElmPasien(string kode, nama, int umur, string diagnosa);
bool isEmptyDokter(listDokter L);
bool isEmptyPasien(almDokter p);
void insertElmDokter(listDokter &L, almDokter p); //Insert Last
void insertElmPasien(listDokter &L, string kodeDokter, almPasien q); //Insert Last
void deleteElmPasien(listDokter &L, string kodeDokter, kodePasien);
elmDokter searchDokter(listDokter L, string kodeDokter);
elmPasien searchPasien(almDokter p, string kodePasien);
void printInfo(listDokter L);

#endif // MLL_H_INCLUDED
