//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool posValida(unsigned long tableroSize, pos p);

bool estaEnJugadas(pos p, int m, jugadas j);

bool tieneBanderita(pos p, banderitas b);

bool mismasJugadas(jugadas j1, jugadas j2);

template <typename T>
typename vector<T>::iterator busqueda_lineal(vector<T>& vec, T elem){
    auto it = vec.begin();

    while(it != vec.end() && *it != elem){
        it += 1;
    }

    return it;
}

