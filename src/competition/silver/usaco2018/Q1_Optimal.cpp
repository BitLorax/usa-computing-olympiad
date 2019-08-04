//
// Created by WillJ on 2/23/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2000000000
#define MAX_COWCNT 100000

using namespace std;

vector<int> locs;

int getDist(int a, int b) {
    return abs(locs[a] - locs[b]) - 1;
}

int main() {

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        int a; cin >> a;
        locs.push_back(a);
    }
    sort(locs.begin(), locs.end());
    int minMoves = INF, maxMoves = 0;
    int curSize = 0, indx = 0;
    for (int i = 0; i < cowCount - 1; i++) {
        int lo = locs[i], hi = locs[i] + cowCount;
        while (indx < cowCount && locs[indx] < hi) {
            curSize++; indx++;
        }
        if (!(cowCount - curSize == 1 && locs[indx - 1] != hi - 1)) minMoves = min(minMoves, cowCount - curSize);
        curSize--;
    }
    curSize = 0; indx = cowCount - 1;
    for (int i = cowCount - 1; i >= 0; i--) {
        int hi = locs[i], lo = locs[i] - cowCount;
        while (indx >= 0 && locs[indx] > lo) {
            curSize++; indx--;
        }
        if (!(cowCount - curSize == 1 && locs[indx + 1] != lo + 1)) minMoves = min(minMoves, cowCount - curSize);
        curSize--;
    }
    maxMoves = getDist(0, locs.size() - 1) - (cowCount - 2) - min(getDist(0, 1), getDist(locs.size() - 1, locs.size() - 2));
    cout << minMoves << endl << maxMoves << endl;
    return 0;
}
