#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(baldosaPisoTest,MNDivisibles){
    int M = 8;
    int N = 6;
    int B = 2;
    int res = baldosasDelPiso(M,N,B);

    EXPECT_EQ(res,12);
}

TEST(baldosaPisoTest,MDivisibles){
    int M = 8;
    int N = 5;
    int B = 2;
    int res = baldosasDelPiso(M,N,B);

    EXPECT_EQ(res,12);
}

TEST(baldosaPisoTest,NDivisibles){
    int M = 5;
    int N = 5;
    int B = 2;
    int res = baldosasDelPiso(M,N,B);

    EXPECT_EQ(res,9);
}