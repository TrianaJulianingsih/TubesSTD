#include "flight.h"

int main() {
    flightNetwork N;
    initNetwork(N);
    int pilihan;
    string startID, destID;
    int flightTime, price, maxDistance, maxPrice;

    do {
        cout << "==============================================";
        cout << "\n--- Selamat Datang Di Aplikasi Penerbangan ---" << endl;
        cout << "==============================================" << endl;
        cout << "1. Tambah Bandara" << endl;
        cout << "2. Tambah Rute Penerbangan" << endl;
        cout << "3. Tampilkan Jaringan Penerbangan" << endl;
        cout << "4. Cari Rute Berdasarkan Jarak Terpendek" << endl;
        cout << "5. Cari Rute Berdasarkan Harga Terendah" << endl;
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
            cout << "Masukkan Bandara Asal: ";
            getline(cin, startID);
            cout << "Masukkan Bandara Tujuan: ";
            getline(cin, destID);
            cout << "Masukkan Batas Maksimal Harga: ";
            cin >> price;
            cout << "Masukkan Batas Maksimal Jarak (menit): ";
            cin >> maxDistance;
            cin.ignore();
            updateAirportStatus(N);
            searchByShortestTime(N, startID, destID, maxPrice, maxDistance);
            break;
        case 5:
            cout << "Masukkan Bandara Asal: ";
            getline(cin, startID);
            cout << "Masukkan Bandara Tujuan: ";
            getline(cin, destID);
            cout << "Masukkan Batas Maksimal Harga: ";
            cin >> maxPrice;
            cout << "Masukkan Batas Maksimal Jarak (menit): ";
            cin >> maxDistance;
            searchByLowestPrice(N, startID, destID, maxPrice, maxDistance);
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
