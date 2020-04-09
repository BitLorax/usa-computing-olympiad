//
// Created by Will Liang on 8/22/2018.
//
#include <iostream>
#include <cstring>


using namespace std;

struct Coord {
    int x, y;
    Coord() {
        x = 0;
        y = 0;
    }
    Coord(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

Coord vertexPositions[210];
bool turnRight[210];
int distToExitClockwise[210];
int distToExitCounter[210];
int minDistToExit[210];

int getDirec(Coord from, Coord to) { // 1 right, -1 left, 2 up, -2 down
    if (from.x == to.x) {
        if (from.y > to.y) {
            return -2;
        } else {
            return 2;
        }
    } else {
        if (from.x > to.x) {
            return -1;
        } else {
            return 1;
        }
    }
}
int getDist(Coord a, Coord b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {

    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);

    int pointCount;
    cin >> pointCount;
    for (int i = 0; i < pointCount; i++) {
        cin >> vertexPositions[i].x >> vertexPositions[i].y;
    }
    int totalDist = 0;
    for (int i = 0; i < pointCount; i++) {
        int prev = (i + pointCount - 1) % pointCount;
        int next = (i + 1) % pointCount;
        int direcOne = getDirec(vertexPositions[prev], vertexPositions[i]);
        int direcTwo = getDirec(vertexPositions[i], vertexPositions[next]);
        turnRight[i] = ((direcOne == 2 && direcTwo == 1) || (direcOne == 1 && direcTwo == -2) ||
                        (direcOne == -2 && direcTwo == -1) || (direcOne == -1 && direcTwo == 2));
        if (i > 0) {
            distToExitCounter[i] = distToExitCounter[i - 1] + getDist(vertexPositions[i], vertexPositions[i - 1]);
            distToExitClockwise[i] = distToExitClockwise[i - 1] - getDist(vertexPositions[i], vertexPositions[i - 1]);
        }
        totalDist += getDist(vertexPositions[i], vertexPositions[(i + pointCount - 1) % pointCount]);
    }
    for (int i = 0; i < pointCount; i++) {
        minDistToExit[i] = min(distToExitCounter[i], distToExitClockwise[i] + totalDist);
    }
    int maxDist = 0;
    for (int i = 1; i < pointCount; i++) { //every possible starting position
        bool isPossibility[pointCount];
        memset(isPossibility, true, sizeof(isPossibility));
        isPossibility[0] = false;
        int possibilityCount = pointCount - 1;
        int moved = 0;
        int distTraveled = 0;
        while (possibilityCount > 1) {
            if (i + moved == pointCount) { //went to exit
                break;
            }
            if (moved > 0) distTraveled += getDist(vertexPositions[i + moved], vertexPositions[i + moved - 1]);
            for (int j = 1; j < pointCount; j++) {
                if (!isPossibility[j]) continue;
                if (j == i) continue;
                if (moved > 0) {
                    if (getDist(vertexPositions[j + moved], vertexPositions[j + moved - 1]) !=
                        getDist(vertexPositions[i + moved], vertexPositions[i + moved - 1])) {
                        possibilityCount--;
                        isPossibility[j] = false;
                        continue;
                    }
                }
                if (j + moved == pointCount) { //went to exit
                    possibilityCount--;
                    isPossibility[j] = false;
                    continue;
                }
                if (turnRight[j + moved] != turnRight[i + moved]) {
                    possibilityCount--;
                    isPossibility[j] = false;
                    continue;
                }
            }
            moved++;
        }
        moved--;
        maxDist = max(maxDist, (distTraveled + minDistToExit[i + moved]) - minDistToExit[i]);
    }
    cout << maxDist << endl;
    return 0;
}

