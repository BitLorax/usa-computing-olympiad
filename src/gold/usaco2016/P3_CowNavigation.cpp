//
// Created by Will Liang on 8/31/2018.
//
#include <iostream>
#include <queue>

#define MAX_SIDELEN 20

using namespace std;

int sideLen;
bool map[MAX_SIDELEN][MAX_SIDELEN];
int states[MAX_SIDELEN][MAX_SIDELEN][4][MAX_SIDELEN][MAX_SIDELEN][4];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct State {
    //directions: 0 up, 1 right, 2 down, 3 left
    int aX, aY, aD;
    int bX, bY, bD;
    State(int ax, int ay, int ad, int bx, int by, int bd) {
        aX = ax; aY = ay; aD = ad;
        bX = bx; bY = by; bD = bd;
    }
    State turnRight() {
        return State{aX, aY, (aD + 1) % 4, bX, bY, (bD + 1) % 4};
    }
    State turnLeft() {
        return State{aX, aY, (aD + 3) % 4, bX, bY, (bD + 3) % 4};
    }
    State moveForward() {
        int naX = aX;
        int naY = aY;
        if (!(naX == sideLen - 1 && naY == 0)) { //not already reached end
            naX += dx[aD]; naY += dy[aD];
            if (map[naX][naY] || naX < 0 || naX >= sideLen || naY < 0 || naY >= sideLen) {
                naX -= dx[aD];
                naY -= dy[aD];
            }
        }
        int nbX = bX; int nbY = bY;
        if (!(nbX == sideLen - 1 && nbY == 0)) { //not already reached end
            nbX += dx[bD]; nbY += dy[bD];
            if (map[nbX][nbY] || nbX < 0 || nbX >= sideLen || nbY < 0 || nbY >= sideLen) {
                nbX -= dx[bD]; nbY -= dy[bD];
            }
        }
        return State{naX, naY, aD, nbX, nbY, bD};
    }
};

int main() {

    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);

    cin >> sideLen;
    for (int i = 0; i < sideLen; i++) {
        char row[MAX_SIDELEN]; cin >> row;
        for (int j = 0; j < sideLen; j++) {
            map[j][i] = (row[j] == 'H');
        }
    }
    queue<State> statesQueue;
    statesQueue.push(State{0, sideLen - 1, 0, 0, sideLen - 1, 1});
    states[0][sideLen - 1][0][0][sideLen - 1][1] = 1;
    while (!statesQueue.empty()) {
        State currPos = statesQueue.front();
        statesQueue.pop();
        if (currPos.aX == sideLen - 1 && currPos.aY == 0 && currPos.bX == sideLen - 1 && currPos.bY == 0) {
            cout << states[currPos.aX][currPos.aY][currPos.aD][currPos.bX][currPos.bY][currPos.bD] - 1;
            break;
        }
        State newPositions[3] = {currPos.moveForward(), currPos.turnLeft(), currPos.turnRight()};
        for (State newPos : newPositions) {
            if (states[newPos.aX][newPos.aY][newPos.aD][newPos.bX][newPos.bY][newPos.bD] == 0) {
                states[newPos.aX][newPos.aY][newPos.aD][newPos.bX][newPos.bY][newPos.bD] = states[currPos.aX][currPos.aY][currPos.aD][currPos.bX][currPos.bY][currPos.bD] + 1;
                statesQueue.push(newPos);
            }
        }
    }
    return 0;
}
