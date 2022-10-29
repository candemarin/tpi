// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(cambiarBanderitasTEST, banderitasVacias){
    tablero tab;
    jugadas jug;
    pos p = {1,2};

    banderitas ban = {};
    banderitas res = {p};

    cambiarBanderita(tab, jug, p, ban);
    ASSERT_TRUE(ban == res);
}

TEST(cambiarBanderitasTEST, retirarBanderita){
    tablero tab;
    jugadas jug;
    pos p = {0, 1};

    banderitas ban = {{1,2}, {0, 0}, {0, 1}, {2, 1}};
    banderitas res = {{1,2}, {0, 0}, {2, 1}};

    cambiarBanderita(tab, jug, p, ban);
    ASSERT_TRUE(ban == res);
}

TEST(cambiarBanderitasTEST, retirarBanderitaFinal){
    tablero tab;
    jugadas jug;
    pos p = {2, 1};

    banderitas ban = {{1,2}, {0, 0}, {0, 1}, {2, 1}};
    banderitas res = {{1,2}, {0, 0}, {0, 1}};

    cambiarBanderita(tab, jug, p, ban);
    ASSERT_TRUE(ban == res);
}

TEST(cambiarBanderitasTEST, colocarBanderita){
    tablero tab;
    jugadas jug;
    pos p = {2, 3};

    banderitas ban = {{1,2}, {0, 0}, {0, 1}, {2, 1}};
    banderitas res = {{1,2}, {0, 0}, {0, 1}, {2, 1}, {2, 3}};

    cambiarBanderita(tab, jug, p, ban);
    ASSERT_TRUE(ban == res);
}