//
// Created by WillJ on 8/16/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_TRIANGLECNT 300

using namespace std;

struct Coord {
    int x, y;
    bool operator<(const Coord &a) const {
        return x < a.x;
    }
};

Coord pts[MAX_TRIANGLECNT + 1];
int under[MAX_TRIANGLECNT + 1][MAX_TRIANGLECNT + 1];
int triangles[MAX_TRIANGLECNT + 1];

inline long long ccw(Coord a, Coord b, Coord c) {
    return (long long) (b.x - a.x) * (long long) (c.y - a.y) -
           (long long) (b.y - a.y) * (long long) (c.x - a.x);
}
bool isBelow(Coord a, Coord b, Coord c) {
    return (a.x == c.x && c.y < a.y) || (b.x == c.x && c.y < b.y);
}
bool isUnder(Coord a, Coord b, Coord c) {
    if (a.x > b.x) {
        Coord t = a;
        a = b;
        b = t;
    }
    long long k = ccw(a, b, c);
    return c.x > a.x && c.x < b.x && k < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");

    int triangleCount; cin >> triangleCount;
    for (int i = 0; i < triangleCount; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    for (int i = 0; i < triangleCount; i++) {
        for (int j = 0; j < triangleCount; j++) {
            if (pts[i].x > pts[j].x) continue;
            for (int l = 0; l < triangleCount; l++) {
                if (l == j || l == i) continue;
                if (isBelow(pts[i], pts[j], pts[l])) {
                    under[i][j] += 1;
                }
                if (isUnder(pts[i], pts[j], pts[l])) under[i][j] += 2;
                under[j][i] = -(under[i][j]);
            }
        }
    }

    for (int i = 0; i < triangleCount; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                int sum = abs(under[i][j] + under[j][k] + under[k][i]) / 2;
                if (isUnder(pts[i], pts[j], pts[k])) sum--;
                if (isUnder(pts[i], pts[k], pts[j])) sum--;
                if (isUnder(pts[j], pts[k], pts[i])) sum--;
                triangles[sum]++;
            }
        }
    }

    for (int i = 0; i <= triangleCount - 3; i++) cout << triangles[i] << endl;
    return 0;
}
