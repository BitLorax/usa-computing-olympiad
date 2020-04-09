
#include <iostream>

#define MOD 1000000007

using namespace std;

/**
 * Computes base ^ pow in O(logN)
 * @param base base
 * @param pow power
 * @return base ^ power
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

/**
 * Computes the greatest common divisor
 * @param a first number
 * @param b second number
 * @return the greatest common divisor
 */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
