//
// Created by WillJ on 3/20/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#define INF 2000000000
#define MAX_COWCNT 100000

using namespace std;

int cows[MAX_COWCNT];
pair<int, int> sorted[MAX_COWCNT];
int arr[MAX_COWCNT + 1];

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

    ifstream fin ("sort.in");
    ofstream fout ("sort.out");

    int cowCount; fin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        fin >> cows[i];
        sorted[i].first = cows[i]; sorted[i].second = i + 1;
    }
    sort(sorted, sorted + cowCount); //map values to consecutive integers
    //1 8 5 2 3 -> 1 2 3 4 5
    //1 2 3 5 8 -> 1 5 4 3 2
    Fenwicks fenwicks{}; fenwicks.construct(arr, MAX_COWCNT + 1);
    int answer = 1;
    for (int i = 0; i < cowCount; i++) {
        fenwicks.update(sorted[i].second, 1);
        answer = max(answer, (i + 1) - fenwicks.query((i + 1)));
    }
    fout << answer << endl;
    return 0;
}
