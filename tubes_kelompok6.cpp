#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_AKUN = 100;
const double BUNGA = 0.02;

// Array paralel untuk menyimpan data akun
string nama[MAX_AKUN];
string noRekening[MAX_AKUN];
double saldo[MAX_AKUN];
int jumlahAkun = 0;

// Fungsi mencari akun berdasarkan nomor rekening
int cariAkun(string noRek) {
    for (int i = 0; i < jumlahAkun; i++) {
        if (noRekening[i] == noRek)
            return i;
    }
    return -1;
}

// Fungsi tambah akun baru
void tambahAkun() {
    if (jumlahAkun >= MAX_AKUN) {
        cout << "Kapasitas akun penuh!\n";
        return;
    }

    cout << "\n=== Buat Akun Baru ===\n";
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, nama[jumlahAkun]);
    cout << "Masukkan Nomor Rekening: ";
    cin >> noRekening[jumlahAkun];
    cout << "Masukkan Saldo Awal: Rp ";
    cin >> saldo[jumlahAkun];

    jumlahAkun++;
    cout << "Akun berhasil dibuat!\n";
}

// Fungsi setor uang
void setorUang() {
    string noRek;
    double jumlah;
    cout << "\n=== Setor Uang ===\n";
    cout << "Masukkan Nomor Rekening: ";
    cin >> noRek;

    int index = cariAkun(noRek);
    if (index == -1) {
        cout << "Nomor rekening tidak ditemukan!\n";
        return;
    }

    cout << "Masukkan jumlah setor: Rp ";
    cin >> jumlah;

    saldo[index] += jumlah;
    saldo[index] += saldo[index] * BUNGA; // bunga otomatis
    cout << "Setoran berhasil! Saldo sekarang: Rp "<< fixed << setprecision(2) << saldo[index] << endl;
}

// Fungsi tarik uang
void tarikUang() {
    string noRek;
    double jumlah;
    cout << "\n=== Tarik Uang ===\n";
    cout << "Masukkan Nomor Rekening: ";
    cin >> noRek;

    int index = cariAkun(noRek);
    if (index == -1) {
        cout << "Nomor rekening tidak ditemukan!\n";
        return;
    }

    cout << "Masukkan jumlah tarik: Rp ";
    cin >> jumlah;

    if (jumlah > saldo[index]) {
        cout << "Saldo tidak cukup!\n";
        return;
    }

    saldo[index] -= jumlah;
    saldo[index] += saldo[index] * BUNGA; // bunga otomatis
    cout << "Penarikan berhasil! Saldo sekarang: Rp "<< fixed << setprecision(2) << saldo[index] << endl;
}

// Fungsi lihat saldo
void lihatSaldo() {
    string noRek;
    cout << "\n=== Lihat Saldo ===\n";
    cout << "Masukkan Nomor Rekening: ";
    cin >> noRek;

    int index = cariAkun(noRek);
    if (index == -1) {
        cout << "Nomor rekening tidak ditemukan!\n";
        return;
    }

    cout << "Nama Pemilik: " << nama[index] << endl;
    cout << "Nomor Rekening: " << noRekening[index] << endl;
    cout << "Saldo Saat Ini: Rp " << fixed << setprecision(2)<<saldo[index] << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Daftar Akun Baru\n";
        cout << "2. Setor Uang\n";
        cout << "3. Tarik Uang\n";
        cout << "4. Lihat Saldo\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahAkun();
            break;
        case 2:
            setorUang();
            break;
        case 3:
            tarikUang();
            break;
        case 4:
            lihatSaldo();
            break;
        case 5:
            cout << "Terima kasih telah menggunakan layanan kami!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
