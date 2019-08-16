
#include <iostream>

#define N 1000

using namespace std;

namespace binarySearch {
    /**
     * Function to test index
     * @param a Index to test
     * @return Evaluation of index
     */
    bool func(int a) {
        return true;
    }
    /**
     * Runs binary search in O(logN)
     * @return Maximum index for which func() returns true
     */
    int run() {
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
}