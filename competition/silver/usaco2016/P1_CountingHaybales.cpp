//
// Created by WillJ on 2/21/2019.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define INF 2000000000
#define MAX_BALECNT 100000
#define MAX_COORD 1000000000

using namespace std;

vector<int> locs;

int main() {

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int baleCount, queryCount; cin >> baleCount >> queryCount;
    for (int i = 0; i < baleCount; i++) {
        int a; cin >> a;
        locs.push_back(a);
    }
    sort(locs.begin(), locs.end());
    for (int i = 0; i < queryCount; i++) {
        int lo, hi; cin >> lo >> hi;
        auto indxLo = lower_bound(locs.begin(), locs.end(), lo);
        auto indxHi = lower_bound(locs.begin(), locs.end(), hi);
        int len = (indxHi - locs.begin()) - (indxLo - locs.begin()) + 1;
        if (!binary_search(locs.begin(), locs.end(), hi)) len--;
        cout << len << endl;
    }
    return 0;
}
