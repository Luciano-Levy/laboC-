#include "../contandoDragones.h"
#include "gtest/gtest.h"

TEST(contandoDragonesTest, coprimos){
    int res  = contandoDragones(10,3,2,5);
    EXPECT_EQ(res,2);
}

TEST(contandoDragonesTest, noCoprimos){
    int res  = contandoDragones(10,4,2,8);
    EXPECT_EQ(res,4);
}
