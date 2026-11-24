#include "MLL.h"

void createNewList(listDokter &L) {
    L.first = nullptr;
    L.last = nullptr;
}
almDokter createElmDokter(string kode, nama, spesialis, int maxPasien) {
    almDokter p = new elmDokter;

    p->info.kode = kode;
    p->info.nama = nama;
    p->info.spesialis = spesialis;
    p->info.maxPasien = maxPasien;
    p->info.jumlahPasien = 0;

    p->next = nullptr;
    p->prev = nullptr;
    p->firstPasien = nullptr;

    return p;

}

almPasien createElmPasien(string kode, nama, int umur, string diagnosa) {
    almPasien p = new elmPasien;

    p->info.kode = kode;
    p->info.nama = nama;
    p->info.umur = umur;
    p->info.diagnosa = diagnosa;

    p->next = nullptr;
    p->prev = nullptr;

    return p;
}

bool isEmptyDokter(listDokter L) {
    return L.first == nullptr && L.last == nullptr;
}

bool isEmptyPasien(almDokter p) {
    return p->firstPasien == nullptr;
}


void insertElmDokter(listDokter &L, almDokter p) {
    if (isEmptyDokter(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void insertElmPasien(listDokter &L, string kodeDokter, almPasien q) {
    almDokter p;
    almPasien searchAlm;

    p = searchDokter(L, kodeDokter);
    if (p != nullptr && p->info.jumlahPasien < p->info.maxPasien) {
        if (isEmptyPasien(p)) {
            p->firstPasien = q;
            (p->info.jumlahPasien)++;
        } else {
            searchAlm = p->firstPasien;
            while(searchAlm->next != nullptr) {
                searchAlm = searchAlm->next;
            }
            searchAlm->next = q;
            q->prev = searchAlm;
            (p->info.jumlahPasien)++;
        }
    } else {
        cout << "File Dokter Tidak Ditemukan!" << endl;
    }


}
void deleteElmPasien(listDokter &L, string kodeDokter, kodePasien) {
    elmDokter p;
    elmPasien q;
    elmPasien prec;

    p = searchDokter(L, kodeDokter);
    q = searchPasien(p, kodePasien);

    if (p != nullptr) {
        if (q == p->firstPasien) {
            (q->next)->prev = nullptr;
            p->firstPasien = q->next;
            q->next = nullptr;
            q = nullptr;
        } else if (q->next == nullptr) {
            prec = q->prev;
            prec->next = nullptr;
            q->prev = nullptr;
            q = nullptr;
        } else if (q != nullptr) {
            prec = q->prev;
            prec->next = q->next;
            (q->next)->prev = prec;
            q->next = nullptr;
            q->prev = nullptr;
        } else {
            cout << "Pasien Tidak Ditemukan" << endl;
        }
    } else {
        cout << "Dokter Tidak Ditemukan" << endl;
    }

}
elmDokter searchDokter(listDokter L, string kodeDokter) {
    almDokter p, found;

    p = L.first;
    found = nullptr;
    while (p != nullptr && found == nullptr) {
        if (p->info.kode == kodeDokter) {
            found = p;
        }
        p = p->next;
    }

    return found;
}
elmPasien searchPasien(almDokter p, string kodePasien) {
    almPasien q, found;

    q = p->firstPasien;
    found = nullptr;
    while (q != nullptr && found == nullptr) {
        if (q->info.kode == kodePasien) {
            found = q;
        }
        q = q->next;
    }

    return found;
}

void printInfo(listDokter L) {
    cout << "==============================================================" << endl;
    cout << "                  DAFTAR DOKTER DAN PASIEN                    " << endl;
    cout << "==============================================================" << endl;

    if (isEmptyDokter(L)) {
        cout << "  (Data dokter masih kosong)" << endl;
        cout << "==============================================================" << endl;
        return;
    }

    almDokter p = L.first;
    int noDokter = 1;

    while (p != NULL) {
        // hitung jumlah pasien
        int jumlah = 0;
        almPasien q = p->firstPasien;
        while (q != NULL) {
            jumlah++;
            q = q->next;
        }

        cout << "[" << noDokter << "] Dokter    : " << p->info.nama
             << " (" << p->info.kode << ")" << endl;
        cout << "    Spesialis : " << p->info.spesialis << endl;
        cout << "    Pasien    : " << jumlah << " / " << p->info.maxPasien << endl;

        if (isEmptyPasien(p)) {
            cout << "    (Belum ada pasien)" << endl;
        } else {
            cout << "    ----------------------------------------------------------" << endl;
            cout << "    " << left
                 << setw(4)  << "No"
                 << setw(8)  << "Kode"
                 << setw(20) << "Nama"
                 << setw(7)  << "Umur"
                 << "Diagnosa" << endl;
            cout << "    ----------------------------------------------------------" << endl;

            q = p->firstPasien;
            int noPasien = 1;
            while (q != NULL) {
                cout << "    " << left
                     << setw(4)  << noPasien
                     << setw(8)  << q->info.kode
                     << setw(20) << q->info.nama
                     << setw(7)  << q->info.umur
                     << q->info.diagnosa << endl;
                q = q->next;
                noPasien++;
            }
            cout << "    ----------------------------------------------------------" << endl;
        }

        cout << endl;
        p = p->next;
        noDokter++;
    }

    cout << "==============================================================" << endl;
}
