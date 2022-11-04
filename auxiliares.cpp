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

bool hayMina(tablero& t, pos p){
    return t[p.first][p.second];
}

int cantSinMinas(tablero& t){
    int contador = 0;

    for (int i=0; i < t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            if (!t[i][j]){
                contador += 1;
            }
        }
    }

    return contador;
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

bool posEnJugadas(tablero &t, jugadas &j, pos p) {
    return busquedaLineal(j, {p, minasAdyacentes(t, p)}) != j.end();
}

bool es121Vert(tablero& t, jugadas& j, int index){
    pos arriba = {j[index].first.first, j[index].first.second - 1};
    pos abajo = {j[index].first.first, j[index].first.second + 1};

    return busquedaLineal(j, {arriba, 1}) != j.end() && busquedaLineal(j, {abajo, 1}) != j.end();
}

bool es121Hor(jugadas& j, int index){
    pos izq = {j[index].first.first - 1, j[index].first.second};
    pos der = {j[index].first.first + 1, j[index].first.second};

    return busquedaLineal(j, {izq, 1}) != j.end() && busquedaLineal(j, {der, 1}) != j.end();
}

bool sugerenciaValidaVert(tablero& t, banderitas& b, jugadas& j, int index, pos& p){
    pos sug1 = {j[index].first.first - 1, j[index].first.second};
    pos sug2 = {j[index].first.first + 1, j[index].first.second};

    if (posValida(t.size(), sug1) && !posEnJugadas(t, j, sug1) && busquedaLineal(b, sug1) == b.end()){
        p = sug1;
        return true;
    } else if (posValida(t.size(), sug2) && !posEnJugadas(t, j, sug2) && busquedaLineal(b, sug2) == b.end()){
        p = sug2;
        return true;
    }

    return false;
}

bool sugerenciaValidaHor(tablero&t, banderitas& b, jugadas& j, int index, pos& p){
    pos sug1 = {j[index].first.first, j[index].first.second - 1};
    pos sug2 = {j[index].first.first, j[index].first.second + 1};

    if (posValida(t.size(), sug1) && !posEnJugadas(t, j, sug1) && busquedaLineal(b, sug1) == b.end()){
        p = sug1;
        return true;
    } else if (posValida(t.size(), sug2) && !posEnJugadas(t, j, sug2) && busquedaLineal(b, sug2) == b.end()){
        p = sug2;
        return true;
    }

    return false;
}