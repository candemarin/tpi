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

bool coordenadaValida(int c, int n) { //auxiliar
    return 0 <= c < n;
}

int minasAdyacentes(tablero& t, pos p) {

    int cantMinasAdy = 0;

    for (int i=-1; i <= 1; i++) {
        for (int j=-1; j <= 1; j++) {
                if (coordenadaValida(p.first + i, t.size()) && coordenadaValida(p.second + j, t[0].size()) && (i != 0 || j !=0)
                && t[p.first + i][p.second + j]) cantMinasAdy++;
} } return cantMinasAdy;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    // ...
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
