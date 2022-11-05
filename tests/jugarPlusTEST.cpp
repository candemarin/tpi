// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(jugarPlusTEST, colocarJugadasMinasEnBorde){
    tablero t = {
            { cMINA,  cMINA,  cMINA,  cMINA, cMINA },
            { cMINA, cVACIA, cVACIA, cVACIA, cMINA },
            { cMINA, cVACIA, cVACIA, cVACIA, cMINA },
            { cMINA, cVACIA, cVACIA, cVACIA, cMINA },
            { cMINA,  cMINA,  cMINA,  cMINA, cMINA },
    };

    banderitas b = {};
    pos p = {2, 2};
    jugadas j = {};

    jugadas res = {jugada(pos(1,1), 5), jugada(pos(1,2), 3), jugada(pos(1,3), 5),
                    jugada(pos(2,1), 3), jugada(pos(2,2), 0), jugada(pos(2,3), 3),
                    jugada(pos(3,1), 5), jugada(pos(3,2), 3), jugada(pos(3,3), 5)};


    jugarPlus(t, b, p, j);
    ASSERT_TRUE(esPermutacion(j, res));
}

TEST(jugarPlusTEST, colocarJugadas){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };
    banderitas b = {};
    pos p = {2, 3};
    jugadas j = {};

    jugadas res = {jugada({0,2}, 1), jugada({0,3}, 0), jugada({0,4}, 0),
                   jugada({1,2}, 2), jugada({1,3}, 0), jugada({1,4}, 0),
                   jugada({2,2}, 1), jugada({2,3}, 0), jugada({2,4}, 0),
                   jugada({3,2}, 2), jugada({3,3}, 1), jugada({3,4}, 0),
                   jugada({4,3}, 1), jugada({4,4}, 0)};

    jugarPlus(t, b, p, j);
    ASSERT_TRUE(esPermutacion(j, res));
}

TEST(jugarPlusTEST, casoLimite){
    tablero t = {
            {cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA}
    };
    banderitas b = {};
    pos p = {1,1};
    jugadas j = {};


    jugadas res = {jugada({0,0}, 0), jugada({0,1}, 0), jugada({0,2}, 0),
                   jugada({1,0}, 0), jugada({1,1}, 0), jugada({1,2}, 0),
                   jugada({2,0}, 0), jugada({2,1}, 0), jugada({2,2}, 0)};

    jugarPlus(t,b,p,j);

    ASSERT_TRUE(esPermutacion(j, res));
}