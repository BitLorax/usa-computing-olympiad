
#include <iostream>

#define N 1000

using namespace std;


/**
 * Function that tests with k
 * @param k The test value
 */
bool func(int k) {
    return false;
}

/**
 * Runs binary search from [0, N - 1]
 */
int binarySearch() {
    int p = 0;
    for (int i = N; i >= 1; i /= 2) {
        while (p + i < N && func(p + i)) p += i;
    }
    return p;
}
