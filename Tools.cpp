#include <chrono>
#include <random>
#include <stdlib.h>
#include "Tools.h"
using namespace std;

int Tools::randomInt() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    int rand = generator();
    return abs(rand);
}