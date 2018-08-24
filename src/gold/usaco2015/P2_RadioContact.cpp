//
// Created by Will Liang on 8/19/2018.
//
#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>

#define MAX 0x7FFFFFFFFFFFFFFFLL

using namespace std;

struct Coord {
    long long x, y;
    Coord() {
        x = 0;
        y = 0;
    }
    Coord(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

Coord fPositions[1001];
Coord bPositions[1001];

long long states[1010][1010];
int fMoveCount, bMoveCount;
map<char, int> dx, dy;

long long move(int fMoved, int bMoved) {
    long long cost = (abs(fPositions[fMoved].x - bPositions[bMoved].x)) * (abs(fPositions[fMoved].x - bPositions[bMoved].x))
                     + (abs(fPositions[fMoved].y - bPositions[bMoved].y)) * (abs(fPositions[fMoved].y - bPositions[bMoved].y));
    if (fMoved == fMoveCount && bMoved == bMoveCount) {
        return cost;
    }
    long long &minCost = states[fMoved][bMoved];
    if (minCost != -1) {
        return minCost;
    }
    if (fMoved == 0 && bMoved == 0) {
        cost = 0;
    }
    minCost = MAX;
    if (fMoved < fMoveCount) {
        minCost = min(minCost, move(fMoved + 1, bMoved) + cost);
    }
    if (bMoved < bMoveCount) {
        minCost = min(minCost, move(fMoved, bMoved + 1) + cost);
    }
    if (fMoved < fMoveCount && bMoved < bMoveCount) {
        minCost = min(minCost, move(fMoved + 1, bMoved + 1) + cost);
    }
    return minCost;
}
int main() {

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w" , stdout);

    cin >> fMoveCount >> bMoveCount;
    int fX, fY, bX, bY;
    cin >> fX >> fY >> bX >> bY;
    string fMoves, bMoves;
    cin >> fMoves >> bMoves;

    dx['E'] = 1; dx['W'] = -1;
    dy['N'] = 1; dy['S'] = -1;

    for (int i = 0; i < fMoveCount; i++) {
        fPositions[i].x = fX;
        fPositions[i].y = fY;
        fX += dx[fMoves[i]];
        fY += dy[fMoves[i]];
    }
    fPositions[fMoveCount].x = fX;
    fPositions[fMoveCount].y = fY;
    for (int i = 0; i < bMoveCount; i++) {
        bPositions[i].x = bX;
        bPositions[i].y = bY;
        bX += dx[bMoves[i]];
        bY += dy[bMoves[i]];
    }
    bPositions[bMoveCount].x = bX;
    bPositions[bMoveCount].y = bY;
    memset(states, -1, sizeof(states));
    cout << move(0, 0) << endl;
    return 0;
}
/*
 *
*/
