#include "../puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(puntajeTest,menoryTres){
    int n = 9;
    int res = puntaje(n);

    EXPECT_EQ(res,28);
}
TEST(puntajeTest,mayorNoTres){
    int n = 13;
    int res = puntaje(n);

    EXPECT_EQ(res,3);
}