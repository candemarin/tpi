// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(perdioTEST, noPerdio){
    vector<bool> v1 = {true, false, false};
    vector<bool> v2 = {true, false, false};
    vector<bool> v3 = {true, true, true};
    tablero t = {v1, v2, v3};

    pos p1 = {1,2};
    pos p2 = {0,1};
    pos p3 = {0,2};

    jugadas j = {{p1, minasAdyacentes(t,p1)}, {p2, minasAdyacentes(t,p2)}, {p3, minasAdyacentes(t,p3)}};

    EXPECT_FALSE(perdio(t, j));
}

TEST(perdioTEST, perdio){
    vector<bool> v1 = {true, false, true};
    vector<bool> v2 = {true, false, false};
    vector<bool> v3 = {true, true, true};
    tablero t = {v1, v2, v3};

    pos p1 = {1,2};
    pos p2 = {0,1};
    pos p3 = {0,2};

    jugadas j = {{p1, minasAdyacentes(t,p1)}, {p2, minasAdyacentes(t,p2)}, {p3, minasAdyacentes(t,p3)}};

    EXPECT_TRUE(perdio(t, j));
}