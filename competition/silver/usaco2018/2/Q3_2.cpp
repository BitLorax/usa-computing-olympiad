//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_MTCNT 100000

using namespace std;

struct Coord {
    int x, y, id;
    bool operator<(const Coord &a) const {
        return x < a.x;
    }
};

Coord peaks[MAX_MTCNT];
bool covered[MAX_MTCNT];

int main() {

    freopen("mountains.in", "r" , stdin);
    freopen("mountains.out", "w", stdout);

    int mountainCount; cin >> mountainCount;
    for (int i = 0; i < mountainCount; i++) {
        cin >> peaks[i].x >> peaks[i].y;
        peaks[i].id = i;
    }
    sort(peaks, peaks + mountainCount);
    int curHeight = 0,  prevX = peaks[0].x;
    for (int i = 0; i < mountainCount; i++) {
        curHeight -= abs(peaks[i].x - prevX);
        if (curHeight >= peaks[i].y) {
            covered[peaks[i].id] = true;
        }
        curHeight = max(curHeight, peaks[i].y);
        prevX = peaks[i].x;
    }
    curHeight = 0; prevX = peaks[mountainCount - 1].x;
    for (int i = mountainCount - 1; i >= 0; i--) {
        curHeight -= abs(peaks[i].x - prevX);
        if (curHeight >= peaks[i].y) {
            covered[peaks[i].id] = true;
        }
        curHeight = max(curHeight, peaks[i].y);
        prevX = peaks[i].x;
    }
    int notCovered = 0;
    for (int i = 0; i < mountainCount; i++) {
        if (!covered[i]) notCovered++;
    }
    cout << notCovered << endl;
    return 0;
}
