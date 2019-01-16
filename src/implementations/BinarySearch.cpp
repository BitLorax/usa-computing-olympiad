//
// Created by WillJ on 1/2/2019.
//

#include <iostream>

#define INF 2000000000
#define N 1000

using namespace std;

bool func(int a) {
    return true;
}
int binarySearch() {
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (func(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    return 0;
}
