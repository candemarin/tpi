//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p){
    int cantMinasAdyacentes = 0;

    for(int i=-1; i <=1; i++){
        for(int j=-1; j<=1; j++){
            pos posActual = {p.first + i, p.second + j};

            if((i != 0 || j !=0) && posValida(t.size(), posActual) && t[posActual.first][posActual.second])
                cantMinasAdyacentes++;
        }
    }

    return cantMinasAdyacentes;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    auto posIt = busqueda_lineal(b, p);

    if(posIt != b.end()){
        b.erase(posIt);
    } else {
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool perdio = false;
    for (int i=0; i < j.size(); i++) {
        int p1 = (j[i].first).first;
        int p2 = (j[i].first).second;
        if (t[p1][p2]) perdio = true;
    } return perdio;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    int posSinMinas =0;
    bool gano = false;
    if (!perdio(t,j)) {
    for (int i=0; i < t.size(); i++)
        for (int r=0; r < t[0].size(); r++)
        if (!t[i][r]) posSinMinas++;
        if (posSinMinas == j.size()) gano = true; // uso j.size porque todas las jugadas son validas  y no tienen minas
        } return gano;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    j.push_back({p, minasAdyacentes(t, p)});
    for (int w = -1; w <= 1; w++) {
        for (int y = -1; y <= 1; y++) {
            while (minasAdyacentes(t, p) == 0 && p.first < t.size() && p.second < t[0].size()) {
                for (int i = -1; i <= 1; i++) {
                    for (int r = -1; r <= 1; r++) {
                        pos posActual = {p.first + i, p.second + r};
                        if ((i != 0 || r != 0) && posValida(t.size(), p) && !t[posActual.first][posActual.second] &&
                            !estaEnJugadas(p, minasAdyacentes(t, p), j) && !tieneBanderita(p, b))
                            j.push_back({posActual, minasAdyacentes(t, p)});
                    }
                }
                p = {p.first + w, p.second + y};
            }
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    bool sugerencia = false;
    if (!estaEnJugadas(p, minasAdyacentes(t, p), j) && !tieneBanderita(p, b) && esAdyacente121(j,p)) sugerencia = true;
    return sugerencia;
}

