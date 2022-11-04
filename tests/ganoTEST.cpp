// Tests para la función gano.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(ganoTEST, todaviaNoGano){
    // ┌───┬───┬───┬───┬───┐
    // │ * │ * │ 2 │ 1 │ 1 │
    // ├───┼───┼───┼───┼───┤
    // │ 3 │ 3 │ 3 │ * │ 1 │
    // ├───┼───┼───┼───┼───┤
    // │ 1 │ * │ 2 │ 1 │ 1 │
    // ├───┼───┼───┼───┼───┤
    // │ 2 │ 3 │ 2 │ 1 │ 0 │
    // ├───┼───┼───┼───┼───┤
    // │ * │ 2 │ * │ 1 │ 0 │
    // └───┴───┴───┴───┴───┘

    tablero tab = {
            {  cMINA,  cMINA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA,  cMINA, cVACIA },
            { cVACIA,  cMINA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            {  cMINA, cVACIA,  cMINA, cVACIA, cVACIA },
    };

    jugadas jug = {
            jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),
            jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
            jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),
            jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
            jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),
            jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),
            jugada(pos(3, 4), 0),jugada(pos(4, 1), 2),
            jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
    };

    ASSERT_FALSE(gano(tab, jug));
}


TEST(ganoTEST, gano){
    tablero tab = {
            {  cMINA,  cMINA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA,  cMINA, cVACIA },
            { cVACIA,  cMINA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            {  cMINA, cVACIA,  cMINA, cVACIA, cVACIA },
    };

    jugadas jug = {
            jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
            jugada(pos(0, 3), 1),jugada(pos(1, 0), 3),
            jugada(pos(1, 1), 3),jugada(pos(1, 2), 3),
            jugada(pos(1, 4), 1),jugada(pos(2, 0), 1),
            jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),
            jugada(pos(2, 4), 1),jugada(pos(3, 0), 2),
            jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),
            jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),
            jugada(pos(4, 4), 0),
    };

    ASSERT_TRUE(gano(tab, jug));
}