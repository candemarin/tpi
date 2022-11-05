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


bool posEnJugadas(tablero &t, jugadas &j, pos p) {
    return busquedaLineal(j, {p, minasAdyacentes(t, p)}) != j.end();
}

bool posEnBanderitas(banderitas& b, pos p){
    return busquedaLineal(b, p) != b.end();
}


void rellenar(tablero& t, banderitas& b, pos p, jugadas& j){
    vector<vector<int>> hueco(t.size(), vector<int>(t.size(), -1));
    vector<pos> cola = {p};

    cola.reserve(4 * t.size());

    for(int i = 0; i < cola.size(); i++){
        pos x = cola[i];
        hueco[x.first][x.second] = minasAdyacentes(t, x);

        if(minasAdyacentes(t, x) == 0){
            // Recorre pos adyacentes a x y va agregando a la cola las que cumplen las condiciones
            for(int r = -1; r <= 1; r++){
                for(int k = -1; k <= 1; k++){
                    pos posActual = {x.first + r, x.second + k};

                    if(posValida(t.size(), posActual) && busquedaLineal(cola, posActual) == cola.end()){
                        cola.push_back(posActual);
                    }
                }
            }
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

bool sugerencia121Valida(tablero& t, banderitas& b, jugadas& j, int index, pos& p){
    // Verifica si es 121 horizontal
    pos izq = {j[index].first.first, j[index].first.second - 1};
    pos der = {j[index].first.first, j[index].first.second + 1};

    bool es121Hor =
            busquedaLineal(j, {izq, 1}) != j.end() &&
            busquedaLineal(j, {der, 1}) != j.end();

    // Busca una sugerencia 121 horizontal válida
    if(es121Hor){
        pos sug1 = {j[index].first.first - 1, j[index].first.second};
        pos sug2 = {j[index].first.first + 1, j[index].first.second};

        if (posValida(t.size(), sug1) && !posEnJugadas(t, j, sug1) && !posEnBanderitas(b, sug1)){
            p = sug1;
            return true;
        } else if (posValida(t.size(), sug2) && !posEnJugadas(t, j, sug2) && !posEnBanderitas(b, sug2)){
            p = sug2;
            return true;
        }
    }

    // Verifica si es 121 vertical
    pos arriba = {j[index].first.first - 1, j[index].first.second};
    pos abajo = {j[index].first.first + 1, j[index].first.second};

    bool es121Ver =
            busquedaLineal(j, {arriba, 1}) != j.end() &&
            busquedaLineal(j, {abajo, 1}) != j.end();

    // Busca una sugerencia 121 veritcal válida
    if(es121Ver){
        pos sug1 = {j[index].first.first, j[index].first.second - 1};
        pos sug2 = {j[index].first.first, j[index].first.second + 1};

        if (posValida(t.size(), sug1) && !posEnJugadas(t, j, sug1) && busquedaLineal(b, sug1) == b.end()){
            p = sug1;
            return true;
        } else if (posValida(t.size(), sug2) && !posEnJugadas(t, j, sug2) && busquedaLineal(b, sug2) == b.end()){
            p = sug2;
            return true;
        }
    }

    return false;
}



/*
 * Usadas solo en TESTS
 */

int apariciones(jugada& elem, jugadas& v){
    int contador = 0;
    for(auto& x : v){
        if(x == elem) contador++;
    }
    return contador;
}

bool esPermutacion(jugadas& v, jugadas& w){
    if(v.size() != w.size()){
        return false;
    }

    for(auto& x : v){
        if(apariciones(x, v) != apariciones(x, w)){
            return false;
        }
    }

    return true;
}