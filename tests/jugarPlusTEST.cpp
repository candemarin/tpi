// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(jugarPlusTEST, colocarJugadasMinasEnBorde){
    tablero t = {
            { cMINA,  cMINA,  cMINA, cMINA, cMINA },
            { cMINA, cVACIA, cVACIA, cVACIA,  cMINA },
            { cMINA, cVACIA,  cVACIA, cVACIA, cMINA },
            { cMINA, cVACIA, cVACIA, cVACIA, cMINA },
            { cMINA,  cMINA, cMINA,  cMINA, cMINA },
    };
    jugadas j = {};

    pos p = {2, 2};

    banderitas b = {};
    jugadas res = {{{1,2},3}, {{1, 3},4}, {{1, 1},4}, {{2,1},3}, {{2, 2},0}, {{2, 3},3}, {{3,2},3}, {{3,3},4}, {{3,1},4}};

    jugarPlus(t, b, p, j);
    ASSERT_TRUE(j == res);
}

TEST(jugarPlusTEST, colocarJugadas){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };
    jugadas j = {};

    pos p = {2, 3};

    banderitas b = {};
    jugadas res = {{{1,2},2}, {{1, 3},0}, {{1, 4},0}, {{2, 2},1}, {{2, 4},0}, {{3,2},2}, {{3,3},1}, {{3,4},0}, {{0,2},1},
                   {{0,3},0}, {{0,4},0}, {{4,3},1}, {{4,4},0}};

    jugarPlus(t, b, p, j);
    ASSERT_TRUE(j == res);
}