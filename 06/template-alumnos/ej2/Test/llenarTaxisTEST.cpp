#include "../llenarTaxis.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(llenarTaxixTest,todosIguales){
    int g1,g2,g3;
    g1 = g2 = g3 = 3;
    int res1 = llenarTaxis1(g1,g2,g3);
    int res2 = llenarTaxis2(g1,g2,g3);
    int res3 = llenarTaxis3(g1,g2,g3);

    EXPECT_EQ(res1,5);
    EXPECT_EQ(res2,5);
    EXPECT_EQ(res3,5);
}

TEST(llenarTaxixTest,g2Par){
int g1,g2,g3;
g1 = g3 = 3;
g2 = 4;
int res1 = llenarTaxis1(g1,g2,g3);
int res2 = llenarTaxis2(g1,g2,g3);
int res3 = llenarTaxis3(g1,g2,g3);

EXPECT_EQ(res1,5);
EXPECT_EQ(res2,5);
EXPECT_EQ(res3,5);
}

TEST(llenarTaxixTest,g2ImparDemasIguales){
    int g1,g2,g3;
    g1 = g3 = 3;
    g2 = 5;
    int res1 = llenarTaxis1(g1,g2,g3);
    int res2 = llenarTaxis2(g1,g2,g3);
    int res3 = llenarTaxis3(g1,g2,g3);

    EXPECT_EQ(res1,6);
    EXPECT_EQ(res2,6);
    EXPECT_EQ(res3,6);
}

TEST(llenarTaxixTest,g2ImparDemasDist1o2){
    int g1,g2,g3;
    g3 = 3;
    g1 = 1;
    g2 = 5;
    int res1 = llenarTaxis1(g1,g2,g3);
    int res2 = llenarTaxis2(g1,g2,g3);
    int res3 = llenarTaxis3(g1,g2,g3);

    EXPECT_EQ(res1,6);
    EXPECT_EQ(res2,6);
    EXPECT_EQ(res3,6);
}