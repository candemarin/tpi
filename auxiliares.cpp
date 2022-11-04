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

    for(int i=0; i < t.size(); i++){
        for (int j = 0; j < t[i].size(); j++) {
            if (!t[i][j]){
                contador += 1;
            }
        }
    }

    return contador;
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


void rellenar(tablero& t, banderitas& b, pos p, jugadas& j){
    vector<vector<int>> hueco(t.size(), vector<int>(t.size(), -1));
    vector<pos> cola = {p};

    cola.reserve(4 * t.size());

    for(auto& x : cola){
        hueco[x.first][x.second] = minasAdyacentes(t, x);

        if(minasAdyacentes(t, x) == 0){
            pos arriba = {x.first, x.second - 1};
            pos derecha = {x.first + 1, x.second};
            pos abajo = {x.first, x.second + 1};
            pos izquierda = {x.first - 1, x.second};

            if(posValida(t.size(), arriba)) cola.push_back(arriba);
            if(posValida(t.size(), derecha)) cola.push_back(derecha);
            if(posValida(t.size(), abajo)) cola.push_back(abajo);
            if(posValida(t.size(), izquierda)) cola.push_back(izquierda);
        }
    }

    for(int r = 0; r < hueco.size(); r++){
        for(int k = 0; k < hueco[r].size(); k++){
            if(hueco[r][k] != -1){
                j.push_back(jugada(pos(r, k), hueco[r][k]));
            }
        }
    }
}


bool es121Vert(jugadas& j, int index){
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