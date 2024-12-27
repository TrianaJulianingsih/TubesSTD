#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#define firstAirport(G) ((G).firstAirport)
#define nextAirport(A) ((A)->nextAirport)
#define firstRoute(A) ((A)->firstRoute)
#define airportID(A) ((A)->airportID)
#define destAirportID(R) ((R)->destAirportID)
#define routePrice(R) ((R)->price)
#define flightTime(R) ((R)->flightTime)
#define nextRoute(R) ((R)->nextRoute)
#include <iostream>
#include <string>

using namespace std;

typedef struct airport *adrAirport;
typedef struct route *adrRoute;

struct airport {
    string airportID;
    adrAirport nextAirport;
    adrRoute firstRoute;
    bool isBusy;
};

struct route {
    string destAirportID;
    int flightTime;
    adrRoute nextRoute;
    int price;
};

struct flightNetwork {
    adrAirport firstAirport;
};

struct Node {
    string airportID;
    int distance;
    string path;
    Node *next;
};

void createAirport(string newAirportID, adrAirport &a);
void initNetwork(flightNetwork &N);
void addAirport(flightNetwork &N, string newAirportID);
void addRoute(flightNetwork &N, string fromAirportID, string toAirportID, int flightTime, int price);
void printNetwork(flightNetwork &N);
void printRoutesByPrice(flightNetwork &N);
void printRoutesByTime(flightNetwork &N);
void dfsShortestRoute(flightNetwork &N, string startID, string destID);
void deleteRoute(flightNetwork &N, string fromAirportID, string toAirportID);
#endif 
