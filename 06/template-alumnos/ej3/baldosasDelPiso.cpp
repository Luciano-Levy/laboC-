#include <cmath>
using namespace std;

int baldosasDelPiso(int M, int N, int B) {
    int a = (float)M/B;
    float b = ((float)N/B);
    return ceil(((float)M/B)) * ceil(((float)N/B));
}
