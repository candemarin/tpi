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

            if((i != 0 || j !=0) && posValida(t.size(), posActual) && hayMina(t, posActual)){
                cantMinasAdyacentes++;
            }
        }
    }

    return cantMinasAdyacentes;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    auto posIt = busquedaLineal(b, p);

    if(posIt != b.end()){
        b.erase(posIt);
    } else {
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/

bool perdio(tablero& t, jugadas& j){
    auto it = j.begin();

    while(it != j.end() && !hayMina(t, it->first)){
        it++;
    }

    return it != j.end();
}
/******++++**************************** EJERCICIO gano ***********+++***********************/

bool gano(tablero& t, jugadas& j) {
    return !perdio(t, j) && cantSinMinas(t) == j.size();
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/

void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j){
    if(minasAdyacentes(t, p) != 0){
        j.push_back(jugada(p, minasAdyacentes(t, p)));
    } else {
        rellenar(t, b, p, j);
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    for(int i = 0; i < j.size(); i++){
        if(j[i].second == 2){
            bool condicion121 =
                    (es121Hor(j, i) && sugerenciaValidaHor(t, b, j, i , p)) ||
                    (es121Vert(j, i ) && sugerenciaValidaVert(t, b, j, i, p));

            if(condicion121){
                return true;
            }
        }
    }

    return false;
}

