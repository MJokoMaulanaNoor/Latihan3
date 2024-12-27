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

void update(int p) {
    if (p >= 0 && p <= pos) {
        cout << "\nData Sebelumnya:\n";
        tampilkanData(p);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukan data baru.\n";
        cout << "Masukan Nama: ";
        getline(cin, sikc[p].nama);
        cout << "Masukan Alamat: ";
        getline(cin, sikc[p].alamat);
        cout << "Masukan IPK: ";
        cin >> sikc[p].ipk;
        cout << "Data berhasil diperbarui.\n";
    } else {
        cout << "Data tidak ditemukan pada posisi " << p << endl;
    }
}

void deleteData(int p) {
    if (p >= 0 && p <= pos) {
        cout << "\nData yang akan dihapus:\n";
        tampilkanData(p);

        // Geser data setelah indeks p ke depan
        for (int i = p; i < pos; ++i) {
            sikc[i] = sikc[i + 1];
        }
        pos--; // Kurangi jumlah data
        cout << "Data berhasil dihapus.\n";
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

void read() {
    if (pos >= 0) {
        cout << "\n=== Data Mahasiswa ===\n";
        for (int i = 0; i <= pos; ++i) {
            cout << i + 1 << ". NIM: " << sikc[i].nim
                 << " | Nama: " << sikc[i].nama
                 << " | Alamat: " << sikc[i].alamat
                 << " | IPK: " << sikc[i].ipk << endl;
        }
    } else {
        cout << "Tidak ada data yang tersedia." << endl;
    }
}

void menu() {
    int pilihan;
    do {
        cout << "\n=== Menu Program ===\n";
        cout << "1. Tambah Data Baru (Create)\n";
        cout << "2. Tampilkan Semua Data (Read)\n";
        cout << "3. Perbarui Data (Update)\n";
        cout << "4. Hapus Data (Delete)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                create();
                break;
            case 2:
                read();
                break;
            case 3: {
                int index;
                cout << "Masukkan indeks data yang ingin diperbarui (0-" << pos << "): ";
                cin >> index;
                update(index);
                break;
            }
            case 4: {
                int index;
                cout << "Masukkan indeks data yang ingin dihapus (0-" << pos << "): ";
                cin >> index;
                deleteData(index);
                break;
            }
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 5);
}

int main() {
    menu();
    return 0;
}
