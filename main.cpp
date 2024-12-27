#include "flight.h"

int main() {
    flightNetwork N;
    initNetwork(N);
    int pilihan;
    string startID, destID;
    int flightTime, price;

    do {
        cout << "==============================================";
        cout << "\n--- Selamat Datang Di Aplikasi Penerbangan ---" << endl;
        cout << "==============================================" << endl;
        cout << "1. Tambah Bandara" << endl;
        cout << "2. Tambah Rute Penerbangan" << endl;
        cout << "3. Tampilkan Jaringan Penerbangan" << endl;
        cout << "4. Tampilkan Rute Dari Harga Terendah Ke Termahal" << endl;
        cout << "5. Tampilkan Rute Dari Tercepat Ke Terlama" << endl;
        cout << "6. Cari Jalur Terpendek" << endl;
        cout << "7. Hapus Rute Penerbangan" << endl;
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
                cout << "Masukkan Harga Tiket: ";
                cin >> price;
                cin.ignore();
                addRoute(N, startID, destID, flightTime, price);
                break;
            case 3:
                cout << "\n========= Rute Jalur Penerbangan =========" << endl;
                printNetwork(N);
                break;
            case 4:
                cout << "\n========= Rute Dari Harga Terendah Ke Termahal =========" << endl;
                printRoutesByPrice(N);
                break;
            case 5:
                cout << "\n========= Rute Dari Tercepat Ke Terlama =========" << endl;
                printRoutesByTime(N);
                break;
            case 6:
                cout << "Masukkan Bandara Asal: ";
                getline(cin, startID);
                cout << "Masukkan Bandara Tujuan: ";
                getline(cin, destID);
                dfsShortestRoute(N, startID, destID);
                break;
            case 7:
                cout << "Masukkan Bandara Asal: ";
                getline(cin, startID);
                cout << "Masukkan Bandara Tujuan: ";
                getline(cin, destID);
                deleteRoute(N, startID, destID);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi kami dan sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
