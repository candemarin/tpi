//
// Este archivo contiene las declaraciones de las funciones (no el código).
// Tienen que coincidir exactamente con el código que se encuentra en ejercicios.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

/*
 * Complejidad: O(1)
 * Justificación: El único ciclo de esta función se ejecuta exactamente 9 veces.
 */

int minasAdyacentes(tablero& t, pos p);

/*
 * Complejidad: O(n)
 * Justificación: El algoritmo hace una busqueda lineal y todos los demás pasos tienen complejidad O(1).
 *
 * Dado que el vector banderitas no está ordenado de ninguna manera, no se puede realizar una busqueda binaria.
 * Concluimos que no hay posibles mejoras.
 */

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b);

/*
 * Complejidad: O(n)
 * Justificación: En el peor de los casos el algoritmo recorre cada uno de los elemenos de jugadas una sola vez.
 *
 * Como en el caso anterior, jugadas no es un vector ordenado de ninguna manera. Además dada la especificación,
 * la posición con mina podría estar en cualquier parte del vector.
 */

bool perdio(tablero& t, jugadas& j);

/*
 * Complejidad: O(n)
 * Justificación: cantSinMinas recorre el tablero una sola vez, entonces tiene complejidad O(n). En el peor de los casos
 * gano ejecuta la función perdio una vez y cantSinMinas una vez. Ambas tienen complejidad O(n).
 */

bool gano(tablero& t, jugadas& j);

/*
 * Complejidad: O(?)
 */

void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j);

/*
 * Complejidad: O(n^2)
 * Justificación: La función recorre una sola vez el vector jugadas y por cada elemento realiza varias busquedas lineales.
 *
 * Una primera mejora sería ordenar mediante quick sort de complejidad O(n * log n) y luego buscar linealmente patrones
 * 121. Esto tendría complejidad O(n * log n + n) = O(n * log n)
 */

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p);
