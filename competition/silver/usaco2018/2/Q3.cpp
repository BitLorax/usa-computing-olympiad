//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_MTCNT 100000

using namespace std;

struct Coord {
    int x, y;
    bool operator<(const Coord &a) const {
        return y > a.y;
    }
};

Coord peaks[MAX_MTCNT];
bool covered[MAX_MTCNT];

int main() {
//
//    freopen("mountains.in", "r" , stdin);
//    freopen("mountains.out", "w", stdout);

    int mountainCount; cin >> mountainCount;
    for (int i = 0; i < mountainCount; i++) {
        cin >> peaks[i].x >> peaks[i].y;
    }
    sort(peaks, peaks + mountainCount);
    int notCovered = mountainCount;
    for (int i = 0; i < mountainCount; i++) {
        for (int j = i + 1; j < mountainCount; j++) {
            if (covered[i] || covered[j]) continue;
            if (peaks[i].y - abs(peaks[i].x - peaks[j].x) >= peaks[j].y) {
                covered[j] = true;
                notCovered--;
            }
            if (peaks[j].y - abs(peaks[i].x - peaks[j].x) >= peaks[i].y) {
                covered[i] = true;
                notCovered--;
            }
        }
    }
    cout << notCovered << endl;
    return 0;
}
