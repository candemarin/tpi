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

TEST(minasAdyacentesTEST, ceroMinasAdyacentes){
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

TEST(minasAdyacentesTEST, tableroCompleto){
    tablero t = {{true, false, true, true},
                 {false, true, false, true},
                 {false, false, false, true},
                 {true, true, false, false}};

    vector<vector<int>> valores = {{1, 3, 3, 2},
                                   {2, 2, 5, 3},
                                   {3, 3, 4, 1},
                                   {1, 1, 2, 1}};

    for(int i = 0; i < t.size() - 1; i++){
        for(int j = 0; j < t[i].size() - 1; j++){
            pos p = {i, j};
            EXPECT_EQ(minasAdyacentes(t, p), valores[i][j]);
        }
    }
}