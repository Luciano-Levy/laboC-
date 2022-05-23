#include <iostream>
#include "cases.h"
#include "ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

void printBeginTest(int testNumber, string testName){
    cout << "Corriendo test " << testNumber << " " << testName << endl;
}

void printEndTest(int testNumber, string testName){
    cout << "Finalizado test " << testNumber << " " << testName << endl << endl;
}

bool asegurar(bool estimated, bool expected) {
    return estimated == expected;
}
//////// Ejercicio 1 ////////////////
TEST(Ej1ProductoVectorial,test1){
    vector<int> u = {2,3,4};
    vector<int> v = {4,3,2};
    vector<vector<int> > expected = {
            {8,  6,  4},
            {12,  9,  6},
            {16, 12,  8}
    };
    vector<vector<int> > real = productoVectorial(u,v);
    EXPECT_EQ(expected,real);
}

TEST(Ej1ProductoVectorial,test2){
    vector<int> u = {6,7,8,9};
    vector<int> v = {1,2,3};
    vector<vector<int> > expected = {
            { 6, 12, 18},
            {7, 14, 21},
            {8, 16, 24},
            {9, 18, 27}
    };
    vector<vector<int> > real = productoVectorial(u,v);
    EXPECT_EQ(real,expected);
}

TEST(Ej1ProductoVectorial,test3){
    vector<int> u = {6};
    vector<int> v = {2};
    vector<vector<int> > expected = {
            {12}
    };
    vector<vector<int> > real = productoVectorial(u,v);
    EXPECT_EQ(real,expected);
}

//////// Ejercicio 2 ////////////////
TEST(Ej2Trasponer,test1) {
	vector<vector<int> > vec(4,vector<int>(4,0)), res(4,vector<int>(4,0));
	vec[0][1] = res[1][0] = 1;
	vec[0][2] = res[2][0] = 2;
	vec[0][3] = res[3][0] = 3;
    vec[1][0] = res[0][1] = 8;
	vec[1][2] = res[2][1] = 4;
	vec[1][3] = res[3][1] = 5;
    vec[2][0] = res[0][2] = 0;
    vec[2][1] = res[1][2] = 15;
	vec[2][3] = res[3][2] = 6;
    vec[3][0] = res[0][3] = 4;
    vec[3][1] = res[1][3] = 13;
    vec[3][2] = res[2][3] = 10;
	vec[0][0] = res[0][0] = vec[1][1] = res[1][1] = 10;
	vec[2][2] = res[2][2] = vec[3][3] = res[3][3] = 20;
	trasponer(vec);
    EXPECT_EQ(vec,res);
}

TEST(Ej2Trasponer,test2){
	vector<vector<int> > vec(5,vector<int>(5));
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			vec[i][j] = i+j;
		}
	}
	vector<vector<int> > res = vec;
	trasponer(vec);

    EXPECT_EQ(vec,res);
}

TEST(Ej2Trasponer,test3){
	vector<vector<int> > vec(6,vector<int>(6)), res(6,vector<int>(6));
	for(int i=0;i<6;i++) {
		for(int j=0;j<=i;j++) {
			vec[i][j] = (i*13+j*17)%19;
			res[j][i] = vec[i][j];
		}
	}
	trasponer(vec);
    EXPECT_EQ(vec,res);
}

//////// Ejercicio 3 ////////////////
TEST(Ej3Multiplicar,test1){
	vector<vector<int> > m1(3,vector<int>(4)), m2(4,vector<int>(5)), res(3,vector<int>(5));
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[0][2] = 3;
	m1[0][3] = 4;
	m1[1][0] = 5;
	m1[1][1] = 6;
	m1[1][2] = 7;
	m1[1][3] = 8;
	m1[2][0] = 9;
	m1[2][1] = 10;
	m1[2][2] = 11;
	m1[2][3] = 12;

	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[0][2] = 3;
	m2[0][3] = 1;
	m2[0][4] = 2;
	m2[1][0] = 3;
	m2[1][1] = 1;
	m2[1][2] = 2;
	m2[1][3] = 3;
	m2[1][4] = 1;
	m2[2][0] = 2;
	m2[2][1] = 3;
	m2[2][2] = 1;
	m2[2][3] = 2;
	m2[2][4] = 3;
	m2[3][0] = 1;
	m2[3][1] = 2;
	m2[3][2] = 3;
	m2[3][3] = 1;
	m2[3][4] = 2;

	res[0][0] = 17;
	res[0][1] = 21;
	res[0][2] = 22;
	res[0][3] = 17;
	res[0][4] = 21;

	res[1][0] = 45;
	res[1][1] = 53;
	res[1][2] = 58;
	res[1][3] = 45;
	res[1][4] = 53;

	res[2][0] = 73;
	res[2][1] = 85;
	res[2][2] = 94;
	res[2][3] = 73;
	res[2][4] = 85;

    EXPECT_EQ(res, multiplicar(m1,m2));
   
    
}

TEST(Ej3Multiplicar,test2) {
	vector<vector<int> > m1(5,vector<int>(5,0)), m2(5,vector<int>(5)), res;
	m1[0][0] = m1[1][1] = m1[2][2] = m1[3][3] = m1[4][4] = 1;
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[0][2] = 3;
	m2[0][3] = 1;
	m2[0][4] = 2;
	m2[1][0] = 3;
	m2[1][1] = 1;
	m2[1][2] = 2;
	m2[1][3] = 3;
	m2[1][4] = 1;
	m2[2][0] = 2;
	m2[2][1] = 3;
	m2[2][2] = 1;
	m2[2][3] = 2;
	m2[2][4] = 3;
	m2[3][0] = 1;
	m2[3][1] = 2;
	m2[3][2] = 3;
	m2[3][3] = 1;
	m2[3][4] = 2;
	m2[4][0] = 1;
	m2[4][1] = 2;
	m2[4][2] = 3;
	m2[4][3] = 1;
	m2[4][4] = 2;

	res = m2;
    EXPECT_EQ(res, multiplicar(m1,m2));
}

//////// Ejercicio 4 ////////////////
TEST(Ej4Promediar,test1) {
	vector<vector<int> > vec(5,vector<int>(5,0));
	for(int i=0;i<5;i++) {
		vec[i][i] = 10*(i+1);
	}

	vector<vector<int> > res(5,vector<int>(5,0));
	res[0][0] = res[2][3] = res[3][2] = 7;
	res[0][1] = res[1][0] = res[1][2] = res[2][1] = 5;
	res[0][2] = res[2][0] = res[1][3] = res[3][1] = 3;
	res[1][1] = res[2][4] = res[4][2] = 6;
	res[2][2] = 10;
	res[3][3] = 13;
	res[3][4] = res[4][3] = 15;
	res[4][4] = 22;
    EXPECT_EQ(promediar(vec),res);
}

TEST(Ej4Promediar,test2){
	vector<vector<int> > vec(5,vector<int>(5,0)),res(5,vector<int>(5,1));
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			if(i%2==j%2) {
				vec[i][j] = 2;
			}
		}
	}
	res[1][2] = res[3][2] = res[2][1] = res[2][3] = 0;
    EXPECT_EQ(promediar(vec),res);
}

//////// Ejercicio 5 ////////////////
TEST(Ej5ContarPicos,test1){
	vector<vector<int> > vec(10,vector<int>(10));
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			vec[i][j] = ((1<<i)*((j+10)*41))%13;
		}
	}

    EXPECT_EQ(contarPicos(vec),8);
}

TEST(Ej5ContarPicos,test2){
	vector<vector<int> > vec(20,vector<int>(40,0));
	for(int i=0;i<10;i++) {
		for(int j=0;j<20;j++) {
			vec[2*i][2*j] = 1;
		}
	}
    EXPECT_EQ(contarPicos(vec),200);
}

//////// Ejercicio 6 ////////////////
TEST(Ej6Triangular,test1){
    vector<vector<int> > m = {
            {1,2,0,4},
            {0,2,0,0},
            {0,0,3,4},
            {0,0,0,4}
        };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}

TEST(Ej6Triangular,test2){
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,2,0,0},
            {0,8,3,0},
            {0,0,0,4}
    };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}

TEST(Ej6Triangular,test3){
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,2,3,0},
            {0,0,3,0},
            {1,0,0,0}
    };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}

TEST(Ej6Triangular,test4){
    vector<vector<int> > m = {
            {0,0,0,4},
            {0,0,0,0},
            {0,0,0,0},
            {1,0,0,0}
    };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}

TEST(Ej6Triangular,test5){
    vector<vector<int> > m = {
            {1,8},
            {0,2},
    };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}

//////// Ejercicio 7 ////////////////
TEST(Ej7HayAmenaza,test1){
	vector<vector<int> > vec(8,vector<int>(8,0));
	vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][4] = vec[6][6] = vec[7][1] = 1;
    EXPECT_FALSE(hayAmenaza(vec));
}

TEST(Ej7HayAmenaza,test2) {
	vector<vector<int> > vec(8,vector<int>(8,0));
	vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][1] = vec[6][6] = vec[7][4] = 1;
    bool res = hayAmenaza(vec);
    EXPECT_TRUE(hayAmenaza(vec));
}

TEST(Ej7HayAmenaza,test3){
	vector<vector<int> > vec(3,vector<int>(4,0));
	vec[0][0] = vec[1][3] = vec[2][1] = 1;
    EXPECT_FALSE(hayAmenaza(vec));
}

TEST(Ej7HayAmenaza,test4){
	vector<vector<int> > vec(3,vector<int>(4,0));
	vec[0][0] = vec[2][3] = vec[2][1] = 1;
    EXPECT_TRUE(hayAmenaza(vec));
}

TEST(Ej7HayAmenaza,test5){
	vector<vector<int> > vec(3,vector<int>(4,0));
	vec[0][0] = vec[1][3] = vec[2][3] = 1;
    EXPECT_TRUE(hayAmenaza(vec));
}

//////// Ejercicio 8 ////////////////


TEST(Ej9DiferenciaDiagonales,test1){
    vector<vector<int> > m = {
            {10,2,3,4},
            {5,10,7,8},
            {10,9,8,7},
            {4,0,0,1}
    };
    EXPECT_EQ(5, diferenciaDiagonales(m));
}

TEST(Ej9DiferenciaDiagonales,test2){
    vector<vector<int> > m = {
            {1,2,3,4},
            {5,6,7,8},
            {10,9,8,7},
            {0,0,0,1}
    };
    EXPECT_EQ(4, diferenciaDiagonales(m));
}

TEST(Ej9DiferenciaDiagonales,test3){
    vector<vector<int> > m = {
            {1,2,3,1},
            {5,2,2,8},
            {10,3,3,7},
            {4,0,0,4}
    };
    EXPECT_EQ(0, diferenciaDiagonales(m));
}

TEST(Ej9DiferenciaDiagonales,test4){
    vector<vector<int> > m = {
            {-1,2,3,-4},
            {5,-6,7,8},
            {1,-9,-8,7},
            {0,0,0,1}
    };
    EXPECT_EQ(8, diferenciaDiagonales(m));
}

TEST(Ej9DiferenciaDiagonales,test5){
    vector<vector<int> > m = {
            {-1,2},
            {6,-6}
    };
    EXPECT_EQ(15, diferenciaDiagonales(m));
}

TEST(Ej9DiferenciaDiagonales,test6){
    vector<vector<int> > m = {
            {-1}
    };
    EXPECT_EQ(0, diferenciaDiagonales(m));
}