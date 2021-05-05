//
// Created by WillJ on 12/28/2018.
//

#include <iostream>

#define INF 2000000000
#define MAX_LEN 1000

using namespace std;

struct Coord {
    int x, y;
};
int DP[MAX_LEN + 1][MAX_LEN + 1];
Coord locs[MAX_LEN + 1][2]; //AFTER move i, position

pair<int, int> getMove(char a) {
    if (a == 'N') return make_pair(0, 1);
    if (a == 'S') return make_pair(0, -1);
    if (a == 'E') return make_pair(1, 0);
    if (a == 'W') return make_pair(-1, 0);
    return make_pair(-1, -1);
}
long long calcDist(Coord a, Coord b) {
    return abs(b.x - a.x) * abs(b.x - a.x) + abs(b.y - a.y) * abs(b.y - a.y);
}
int move(int fIndex, int bIndex) {
    if (fIndex < 0 || bIndex < 0) return INF;
    if (DP[fIndex][bIndex] != -1) return DP[fIndex][bIndex];
    DP[fIndex][bIndex] = min(move(fIndex - 1, bIndex - 1), min(move(fIndex - 1, bIndex), move(fIndex, bIndex - 1)));
    DP[fIndex][bIndex] += calcDist(locs[fIndex][0], locs[bIndex][1]);
    return DP[fIndex][bIndex];
}

int main() {
    int fLen, bLen; cin >> fLen >> bLen;
    Coord fCoord, bCoord;
    cin >> fCoord.x >> fCoord.y; cin >> bCoord.x >> bCoord.y;
    string f, b; cin >> f; cin >> b;
    for (int i = 0; i <= fLen; i++) {
        for (int j = 0; j <= bLen; j++) {
            DP[i][j] = -1;
        }
    }
    DP[0][0] = 0;
    for (int i = 0; i < fLen; i++) {
        locs[i][0].x = fCoord.x; locs[i][0].y = fCoord.y;
        pair<int, int> move = getMove(f[i]);
        fCoord.x += move.first; fCoord.y += move.second;
    }
    locs[fLen][0].x = fCoord.x; locs[fLen][0].y = fCoord.y;
    for (int i = 0; i < bLen; i++) {
        locs[i][1].x = bCoord.x; locs[i][1].y = bCoord.y;
        pair<int, int> move = getMove(b[i]);
        bCoord.x += move.first; bCoord.y += move.second;
    }
    locs[bLen][1].x = bCoord.x; locs[bLen][1].y = bCoord.y;
    cout << move(fLen, bLen) << endl;
    return 0;
}

