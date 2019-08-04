//
// Created by WillJ on 3/13/2019.
//

#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

#define INF 2000000000
#define MAX_COWCNT 100000

using namespace std;

int cows[MAX_COWCNT];
int preSums[MAX_COWCNT + 1];

struct Fenwicks {
    int n;
    vector<int> fenwick;
    /**
     * Calculates the sums of input array in O(NlogN)
     *
     * @param arr Array for prefix sums
     * @param size Size of array
     */
    void construct(int arr[], int size) {
        n = size;
        fenwick = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) update(i, arr[i]);
    }
    /**
     * Queries fenwick array in O(logN)
     *
     * @param index index of prefix sum
     * @return sum of values [0, index]
     */
    int query(int index) { //sum [0, index]
        index++;
        int ans = 0;
        for (; index > 0; index -= index&-index) ans += fenwick[index];
        return ans;
    }
    /**
     * Updates fenwick array in O(logN)
     *
     * @param index index of value to update
     * @param add value to add to current value, does not replace
     */
    void update(int index, int add) {
        index++;
        for (; index <= n; index += index&-index) {
            fenwick[index] += add;
        }
    }
};

int main() {

    ifstream cin ("sleepy.in");
    ofstream cout ("sleepy.out");

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cows[i];
    }
    int indx = cowCount - 1; preSums[cows[indx]] = 1;
    while (cows[indx - 1] < cows[indx]) {
        preSums[cows[indx - 1]] = 1;
        indx--;
    }
    cout << indx << endl;

    Fenwicks fenwicks{}; fenwicks.construct(preSums, MAX_COWCNT + 1);
    for (int i = 0; i < indx; i++) {
        int j = indx - i - 1;
        int k = fenwicks.query(cows[i]);
        cout << (j + k) << ((i == indx - 1) ? "" : " ");
        fenwicks.update(cows[i], 1);
    }
    cout << endl;
    return 0;
}
