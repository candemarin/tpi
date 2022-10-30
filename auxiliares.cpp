//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool posValida(unsigned long tableroSize, pos p){
    return (0 <= p.first && p.first < tableroSize) && (0 <= p.second && p.second < tableroSize);
}

bool estaEnJugadas(pos p, int m, jugadas j) {
    bool esta = false;
    for (int i=0; i < j.size(); i++) {
        if (j[i].first == p && j[i].second == m) esta = true;
    } return esta;
}

bool tieneBanderita(pos p, banderitas b) {
    bool tiene = false;
    for (int i=0; i < b.size(); i++) {
        if (b[i] == p) tiene = true;
    } return tiene;
}