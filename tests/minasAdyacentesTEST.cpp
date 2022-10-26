// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;

TEST(minasAdyacentesTEST, minasEnTodasAdyacentes){
    vector<bool> v1 = {true, true, true};
    vector<bool> v2 = {true, false, true};
    vector<bool> v3 = {true, true, true};
    tablero t = {v1, v2, v3};
    int p1 = 1;
    int p2 = 1;
    pos p = {p1,p2};
EXPECT_EQ(minasAdyacentes(t,p),8);
}

TEST(minasAdyacentesTEST, CeroMinasAdyacentes){
    vector<bool> v1 = {false, false, false};
    vector<bool> v2 = {false, false,false};
    vector<bool> v3 = {false, false, false};
    tablero t = {v1, v2, v3};
    int p1 = 1;
    int p2 = 1;
    pos p = {p1,p2};
    EXPECT_EQ(minasAdyacentes(t,p),0);
}

TEST(minasAdyacentesTEST, pEnBorde){
    vector<bool> v1 = {false, true, false};
    vector<bool> v2 = {false, true,false};
    vector<bool> v3 = {false, false, true};
    tablero t = {v1, v2, v3};
    int p1 = 0;
    int p2 = 0;
    pos p = {p1,p2};
    EXPECT_EQ(minasAdyacentes(t,p),2);
}