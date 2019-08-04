//
// Created by WillJ on 3/31/2019.
//

#include <iostream>
#include <fstream>
#include <set>
#include <vector>

#define INF 2000000000
#define MAX_COWCNT 50000

using namespace std;

struct Fenwicks {
    int n;
    vector<int> fenwick;
    /**
     * Calculates the sums of input array in O(NlogN)
     *
     * @param size Size of array
     */
    void construct(int size) {
        n = size;
        fenwick = vector<int>(n + 1, 0);
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

int crossings[MAX_COWCNT * 2];
pair<int, int> locs[MAX_COWCNT + 1];
vector<int> cows;

int main() {

    ifstream cin ("circlecross.in");
    ofstream cout ("circlecross.out");

    int cowCount; cin >> cowCount;
    for (int i = 1; i <= cowCount; i++) {
        locs[i].first = INF;
        locs[i].second = -1;
    }
    for (int i = 0; i < cowCount * 2; i++) {
        cin >> crossings[i];
        locs[crossings[i]].first = min(locs[crossings[i]].first, i);
        locs[crossings[i]].second = max(locs[crossings[i]].second, i);
    }

    long long intersections = 0;
    Fenwicks fenwicks; fenwicks.construct(cowCount * 2);
    for (int i = 0; i < cowCount * 2; i++) {
        if (i == locs[crossings[i]].first) {
            fenwicks.update(i, 1);
        }
        else {
            intersections += fenwicks.query(i) - fenwicks.query(locs[crossings[i]].first);
            fenwicks.update(locs[crossings[i]].first, -1);
        }
    }
    cout << intersections << endl;
    return 0;
}
