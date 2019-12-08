
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
     * @return maximum index for which func() returns true (ex: [t, t, t, f, f, f])
     */
    int lower() {
        int lo = 0, hi = N;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (func(mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    }
    /**
     * Runs binary search in O(logN)
     * @return minimum index for which func() returns true (ex: [f, f, f, t ,t ,t])
     */
    int upper() {
        int lo = 0, hi = N - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (func(mid)) hi = mid;
            else lo = mid + 1;
        }
    }
    int binarySearch() {
        int p = 0;
        for (int i = N; i >= 1; i /= 2) {
            while (p + i < N && func(p + i)) p += i;
        }
    }
}