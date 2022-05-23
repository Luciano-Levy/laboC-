#include "../electores.h"
#include "gtest/gtest.h"

TEST(electoresTest,Invalidas){
    int res = validarVotante(-3, 3,22);
    EXPECT_EQ(res,4);
}

TEST(electoresTest,NOVOTA){
    int res = validarVotante(2016,3,22);
    EXPECT_EQ(res,0);
}
TEST(electoresTest,OBLIGATORIA){
    int res = validarVotante(2000,3,22);
    EXPECT_EQ(res,2);
}
TEST(electoresTest,OPCIONAL){
    int res = validarVotante(1943,3,22);
    EXPECT_EQ(res,3);
}