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

void addRoute(flightNetwork &N, string fromAirportID, string toAirportID, int flightTime) {
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
            cout << " (" << destAirportID(r) << ", " << flightTime(r) << " mins)";
            r = nextRoute(r);
        }
        cout << endl;
        a = nextAirport(a);
    }
}
