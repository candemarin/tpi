// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

tablero tt = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidass = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),
        jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),
};

pos p = {1,1};
banderitas b = {pos(0,0)};

TEST(sugerir121TEST, noHaySugerencia121){
    jugadas jj = jugadasValidass;
    ASSERT_FALSE(sugerirAutomatico121(tt, b, jj, p));
}

tablero tt2 = {
        { cMINA,  cVACIA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidass2 = {
        jugada(pos(0, 2), 1),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 1),jugada(pos(1, 2), 2),
        jugada(pos(2, 0), 0),jugada(pos(2, 2), 1),
        jugada(pos(3, 0), 1),jugada(pos(3, 1), 2),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),
};

pos p2 = {1,1};
banderitas b2 = {pos(0,0)};

TEST(sugerir121TEST, HaySugerencia121Vertical){
    jugadas jj2 = jugadasValidass2;
    ASSERT_TRUE(sugerirAutomatico121(tt2, b2, jj2, p2));
}

tablero t3 = {
        { cVACIA,  cMINA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cVACIA,  cVACIA, cVACIA },
};
jugadas jugadasValidas3 = {
        jugada(pos(0, 4), 1),
        jugada(pos(1, 3), 1),jugada(pos(1, 2), 2),
        jugada(pos(2, 0), 1),jugada(pos(1, 1), 1),
        jugada(pos(3, 0), 1),jugada(pos(3, 1), 1),
        jugada(pos(4, 1), 1),jugada(pos(4, 3), 0),
};

pos p3 = {2,2};
banderitas b3 = {pos(0,0)};

TEST(sugerir121TEST, HaySugerencia121Horizontal){
    jugadas j3 = jugadasValidas3;
    ASSERT_TRUE(sugerirAutomatico121(t3, b3, j3, p3));
}