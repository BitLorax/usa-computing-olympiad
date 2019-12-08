//
// Created by WillJ on 2/19/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2000000000
#define MAX_NUMCNT 100000

using namespace std;

vector<pair<int, int>> arr; //<val, initalIndx>

//values not distinct, comparing sorted array with initial array won't work, need to keep track of individual indices

int main() {

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int numCount; cin >> numCount;
    for (int i = 0; i < numCount; i++) {
        int a; cin >> a;
        arr.push_back(make_pair(a, i));
    }
    sort(arr.begin(), arr.end());
    int maxStep = 0;
    for (int i = 0; i < numCount; i++) {
        maxStep = max(maxStep, arr.at(i).second - i);
    }
    cout << maxStep + 1 << endl;
    return 0;
}
