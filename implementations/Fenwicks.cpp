
#include <iostream>
#include <vector>

#define N 1000

using namespace std;

namespace fenwicks {
    int n;
    int fenwick[N + 1];
    /**
     * Updates fenwick array in O(logN)
     * @param index index of value to update
     * @param add value to add to current value, does not replace
     */
    void update(int index, int add) {
        for (++index; index <= n; index += index&-index)
            fenwick[index] += add;
    }
    /**
     * Calculates the sums of input array in O(NlogN)
     * @param arr Array for prefix sums
     * @param size Size of array
     */
    void construct(int arr[], int size) {
        n = size;
        for (int i = 0; i < n; i++)
            update(i, arr[i]);
    }
    /**
     * Queries fenwick array in O(logN)
     * @param index index of prefix sum
     * @return sum of values [0, index]
     */
    int query(int index) {
        int ans = 0;
        for (++index; index > 0; index -= index&-index)
            ans += fenwick[index];
        return ans;
    }
}