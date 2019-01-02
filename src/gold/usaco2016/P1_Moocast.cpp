//
// Created by Will Liang on 8/23/2018.
//
#include <iostream>
#define INF 200000000
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

Coord cowPositions[1010];
bool visited[1010];
int distances[1010];

int main() {

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int cowCount; cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        cin >> cowPositions[i].x >> cowPositions[i].y;
    }
    int maxDist = 0;
    fill(distances, distances + cowCount + 1, INF);
    distances[0] = 0;
    for (int ii = 0; ii < cowCount; ii++) {
        int minDist = INF;
        int closestDest = -1;
        for (int i = 0; i < cowCount; i++) {
            if (!visited[i] && distances[i] < minDist) {
                minDist = distances[i];
                closestDest = i;
            }
        }
        visited[closestDest] = true;
        maxDist = max(maxDist, minDist);
        for (int i = 0; i < cowCount; i++) {
            if (!visited[i]) distances[i] = min(distances[i], cowPositions[closestDest].calcDist(cowPositions[i]));
        }
    }
    cout << maxDist << endl;
    return 0;
}

