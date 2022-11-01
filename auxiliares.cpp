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

bool mismasJugadas(jugadas j1, jugadas j2) {
    bool mismasJug = false;
    int cantidad =0;
    for (int i =0; i< j1.size(); i++) {
        for (int r= 0; r < j2.size(); r++) {
            if ((j1[i] == j2[r])) cantidad++;
        }
    } if (cantidad == j1.size()) mismasJug =  true;
            return mismasJug;
}

bool esAdyacente121(jugadas j, pos p) {
    bool esAdy121 = false;

    if (esAdyVertical121(j,p) || esAdyHorizontal121(j,p)) esAdy121 = true;

    return esAdy121;
}

bool esAdyVertical121(jugadas j, pos p) {
    bool esAdyV121 = false;

    for(int i=-1; i <=1; i++) {
        if (i != 0 && ((estaEnJugadas({p.first-1, p.second+i},1,j) && estaEnJugadas({p.first-1, p.second},2,j)) ||
                       (estaEnJugadas({p.first+1, p.second+i},1,j) && estaEnJugadas({p.first+1, p.second},2,j)))) esAdyV121 = true;
    }
    return esAdyV121;
}

bool esAdyHorizontal121(jugadas j, pos p) {
    bool esAdyH121 = false;

    for(int i=-1; i <=1; i++) {
        if (i != 0 && ((estaEnJugadas({p.first+i, p.second-1},1,j) && estaEnJugadas({p.first, p.second-1},2,j)) ||
                       (estaEnJugadas({p.first+i, p.second+1},1,j) && estaEnJugadas({p.first, p.second+1},2,j)))) esAdyH121 = true;
    }
    return esAdyH121;
}