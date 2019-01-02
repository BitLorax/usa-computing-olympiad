//
// Created by Will Liang on 8/23/2018.
//
#include <iostream>
#define INF 2000000000;

using namespace std;

struct Coord {
    int x, y;
    Coord() {
        x = -1;
        y = -1;
    }
    Coord(int a, int b) {
        x = a;
        y = b;
    }
    int calcDist(Coord a) {
        return abs(x - a.x) * abs(x - a.x) + abs(y - a.y) * abs(y - a.y);
    }
};

Coord holsteinPositions[1010];
Coord guernseyPositions[1010];
int states[1010][1010][2];

int main() {

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int holsteinCount, guernseyCount; cin >> holsteinCount >> guernseyCount;
    for (int i = 0; i < holsteinCount; i++) {
        cin >> holsteinPositions[i].x >> holsteinPositions[i].y;
    }
    for (int i = 0; i < guernseyCount; i++) {
        cin >> guernseyPositions[i].x >> guernseyPositions[i].y;
    }
    for (int i = 0; i <= holsteinCount; i++) {
        for (int j = 0; j <= guernseyCount; j++) {
            states[i][j][0] = states[i][j][1] = INF;
        }
    }
    states[1][0][0] = 0;
    for (int i = 0; i <= holsteinCount; i++) {
        for (int j = 0; j <= guernseyCount; j++) {
            for (int k = 0; k < 2; k++) {
                if (k == 0 && i == 0) continue;
                if (k == 1 && j == 0) continue;

                Coord from;
                if (k == 0) from = holsteinPositions[i - 1];
                else from = guernseyPositions[j - 1];

                if (i < holsteinCount) states[i + 1][j][0] = min(states[i + 1][j][0],
                        states[i][j][k] + from.calcDist(holsteinPositions[i]));
                if (j < guernseyCount) states[i][j + 1][1] = min(states[i][j + 1][1],
                        states[i][j][k] + from.calcDist(guernseyPositions[j]));
            }
        }
    }
    cout << states[holsteinCount][guernseyCount][0];
    return 0;
}
