#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

Mahasiswa sikc[30];
int pos = -1;

void tampilkanData(int p) {
    if (p >= 0 && p <= pos) {
        cout << "NIM: " << sikc[p].nim 
             << " | Nama: " << sikc[p].nama 
             << " | Alamat: " << sikc[p].alamat 
             << " | IPK: " << sikc[p].ipk << endl;
    } else {
        cout << "Data tidak ditemukan pada posisi " << p << endl;
    }
}

void masukanData() {
    if (pos + 1 < 30) {
        pos++;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukan NIM: ";
        getline(cin, sikc[pos].nim);
        cout << "Masukan Nama: ";
        getline(cin, sikc[pos].nama);
        cout << "Masukan Alamat: ";
        getline(cin, sikc[pos].alamat);
        cout << "Masukan IPK: ";
        cin >> sikc[pos].ipk;
    } else {
        cout << "Data penuh, tidak bisa menambahkan data baru." << endl;
    }
}

void perbaikanData(int p) {
    if (p >= 0 && p <= pos) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Perbaikan Nama: ";
        getline(cin, sikc[p].nama);
        cout << "Perbaikan Alamat: ";
        getline(cin, sikc[p].alamat);
        cout << "Perbaikan IPK: ";
        cin >> sikc[p].ipk;
    } else {
        cout << "Data tidak ditemukan pada posisi " << p << endl;
    }
}

void create() {
    char lagi = 'y';
    while (lagi == 'y' || lagi == 'Y') {
        masukanData();
        cout << "Data berhasil ditambahkan." << endl;
        cout << "Apakah Anda ingin menambahkan data lagi? (y/n): ";
        cin >> lagi;
    }
}

void menu() {
    int pilihan;
    do {
        cout << "\n=== Menu Program ===\n";
        cout << "1. Tambah Data Baru (Create)\n";
        cout << "2. Tampilkan Data (Read)\n";
        cout << "3. Perbaiki Data (Update)\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                create();
                break;
            case 2: {
                int index;
                cout << "Masukkan indeks data yang ingin ditampilkan (0-" << pos << "): ";
                cin >> index;
                tampilkanData(index);
                break;
            }
            case 3: {
                int index;
                cout << "Masukkan indeks data yang ingin diperbaiki (0-" << pos << "): ";
                cin >> index;
                perbaikanData(index);
                break;
            }
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 4);
}

int main() {
    menu();
    return 0;
}
