#include "flight.h"

int main() {
    flightNetwork N;
    initNetwork(N);
    int pilihan;
    string startID, destID;
    int flightTime;

    do {
        cout << "\nMenu Jaringan Penerbangan:" << endl;
        cout << "1. Tambah Bandara" << endl;
        cout << "2. Tambah Rute Penerbangan" << endl;
        cout << "3. Tampilkan Jaringan Penerbangan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Masukkan Nama Bandara: ";
            getline(cin, startID);
            addAirport(N, startID);
            break;
        case 2:
            cout << "Masukkan Bandara Asal: ";
            getline(cin, startID);
            cout << "Masukkan Bandara Tujuan: ";
            getline(cin, destID);
            cout << "Masukkan Waktu Penerbangan (menit): ";
            cin >> flightTime;
            cin.ignore();
            addRoute(N, startID, destID, flightTime);
            break;
        case 3:
            cout << "\n========= Rute Jalur Penerbangan =========\n"
            printNetwork(N);
            break;
        case 0:
            cout << "Terima kasih telah menggunakan aplikasi jaringan penerbangan dan sampai jumpa!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
