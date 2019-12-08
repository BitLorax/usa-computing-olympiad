
#include <iostream>
#include <cmath>
#include <vector>

#define N 1000
#define LOG 10

using namespace std;

namespace rmq {
    int n;
    int mins[N + 1][LOG + 1];
    /**
     * Preprocesses arr in O(NlogN)
     *
     * @param arr Array to be preprocessed
     * @param size Size of array
     */
    void preprocess(int arr[], int size) {
        n = size;

        for (int i = 0; i < n; i++) mins[i][0] = i;
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j)) <= n; i++) {
                if (arr[mins[i][j - 1]] < arr[mins[i + (1 << (j - 1))][j - 1]]) mins[i][j] = mins[i][j - 1];
                else mins[i][j] = mins[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    /**
     * Queries mins in O(1)
     *
     * @param arr Array to query
     * @param lo Low index
     * @param hi High index
     * @return Index of minimum value from range [lo, hi]
     */
    int query(int arr[], int lo, int hi) {
        int i = (int)(log2(hi - lo + 1));
        if (arr[mins[lo][i]] <= arr[mins[hi - (1 << i) + 1][i]]) return mins[lo][i];
        return mins[hi - (1 << i) + 1][i];
    }
};

