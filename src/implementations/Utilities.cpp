
#include <iostream>

#define MOD 1000000007

using namespace std;

/**
 * Computes base ^ pow in O(logN)
 * @param base Base
 * @param pow Power
 * @return Base ^ power
 */
long long fastExpo(int base, int pow) {
    long long ret = 1, b = base;
    while (pow > 0) {
        if (pow % 2 == 1) ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        pow /= 2;
    }
    return ret % MOD;
}

