#include "flight.h"

void createAirport(string newAirportID, adrAirport &a) {
    a = new airport;
    if (a != NULL) {
        airportID(a) = newAirportID;
        nextAirport(a) = NULL;
        firstRoute(a) = NULL;
    }
}

void initNetwork(flightNetwork &N) {
    firstAirport(N) = NULL;
}

void addAirport(flightNetwork &N, string newAirportID) {
    adrAirport newAirport, temp;
    createAirport(newAirportID, newAirport);

    if (firstAirport(N) == NULL) {
        firstAirport(N) = newAirport;
    } else {
        temp = firstAirport(N);
        while (nextAirport(temp) != NULL) {
            temp = nextAirport(temp);
        }
        nextAirport(temp) = newAirport;
    }
}

void addRoute(flightNetwork &N, string fromAirportID, string toAirportID, int flightTime, int price) {
    adrAirport fromAirport = firstAirport(N);
    adrAirport toAirport = NULL;

    while (fromAirport != NULL && airportID(fromAirport) != fromAirportID) {
        fromAirport = nextAirport(fromAirport);
    }

    toAirport = firstAirport(N);
    while (toAirport != NULL && airportID(toAirport) != toAirportID) {
        toAirport = nextAirport(toAirport);
    }

    if (fromAirport != NULL && toAirport != NULL) {
        adrRoute newRoute = new route;
        destAirportID(newRoute) = toAirportID;
        flightTime(newRoute) = flightTime;
        routePrice(newRoute) = price;
        nextRoute(newRoute) = firstRoute(fromAirport);
        firstRoute(fromAirport) = newRoute;
    } else {
        cout << "Bandara " << fromAirportID << " atau " << toAirportID << " tidak ditemukan." << endl;
    }
}

void printNetwork(flightNetwork &N) {
    adrAirport a = firstAirport(N);
    adrRoute r;

    while (a != NULL) {
        cout << airportID(a) << " ->";
        r = firstRoute(a);
        while (r != NULL) {
            cout << " (" << destAirportID(r) << ", " << flightTime(r) << " mins, Rp" << routePrice(r) << ")";
            r = nextRoute(r);
        }
        cout << endl;
        a = nextAirport(a);
    }
}

void searchByDFS(flightNetwork &N, string startAirportID, string targetAirportID, int maxPrice, int maxDistance) {
    adrAirport startAirport = firstAirport(N);

    // Cari bandara awal
    while (startAirport != NULL && airportID(startAirport) != startAirportID) {
        startAirport = nextAirport(startAirport);
    }

    if (startAirport == NULL) {
        cout << "Bandara " << startAirportID << " tidak ditemukan!" << endl;
        return;
    }

    // Stack manual untuk DFS
    const int MAX_STACK_SIZE = 100;
    Node stack[MAX_STACK_SIZE];
    int top = -1;
    top++;
    stack[top] = {startAirport, 0, 0, startAirportID};

    bool found = false;

    while (top >= 0) {
        Node current = stack[top];
        top--;

        // Jika mencapai bandara tujuan
        if (airportID(current.airport) == targetAirportID) {
            cout << "Rute ditemukan: " << current.path << " | Waktu: " << current.totalTime
                 << " menit | Harga: " << current.totalPrice << endl;
            found = true;
            continue;
        }

        // Telusuri rute dari bandara saat ini
        adrRoute r = firstRoute(current.airport);
        while (r != NULL) {
            int newTotalTime = current.totalTime + flightTime(r);
            int newTotalPrice = current.totalPrice + routePrice(r);

            if (newTotalTime <= maxDistance && newTotalPrice <= maxPrice) {
                string newPath = current.path + " -> " + destAirportID(r);

                adrAirport nextAirport = firstAirport(N);
                while (nextAirport != NULL && airportID(nextAirport) != destAirportID(r)) {
                    nextAirport = nextAirport->nextAirport;
                }

                if (nextAirport != NULL && top + 1 < MAX_STACK_SIZE) {
                    // Push ke stack
                    top++;
                    stack[top] = {nextAirport, newTotalTime, newTotalPrice, newPath};
                }
            }
            r = nextRoute(r);
        }
    }

    if (!found) {
        cout << "Tidak ada rute yang memenuhi kriteria!" << endl;
    }
}
