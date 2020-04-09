//
// Created by WillJ on 1/16/2019.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_PATHLEN 100000
#define MAX_BOOTCNT 100000

using namespace std;

struct Boot {
    int durability, agility, id;
    bool operator<(const Boot &a) const {
        return durability > a.durability;
    }
};

struct Tile {
    int depth, loc;
    bool operator<(const Tile &a) const {
        return depth > a.depth;
    }
};

Tile path[MAX_PATHLEN];
Boot boots[MAX_BOOTCNT];
bool canUse[MAX_BOOTCNT];
int l[MAX_BOOTCNT];
int r[MAX_BOOTCNT];

int main() {

    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    int pathLen, bootCount; cin >> pathLen >> bootCount;
    for (int i = 0; i < pathLen; i++) {
        cin >> path[i].depth;
        path[i].loc = i;
        l[i] = i - 1; r[i] = i + 1;
    }
    for (int i = 0; i < bootCount; i++) {
        cin >> boots[i].durability >> boots[i].agility;
        boots[i].id = i;
    }
    sort(boots, boots + bootCount);
    sort(path, path + pathLen);
    int ind = 0;
    int largestInterval = 0; //largest un-passable group of tiles
    for (int i = 0; i < bootCount; i++) {
        while (ind < pathLen && path[ind].depth > boots[i].durability) {
            int loc = path[ind].loc;
            r[l[loc]] = r[loc];
            l[r[loc]] = l[loc];
            largestInterval = max(largestInterval, abs(l[loc] - r[loc]) - 1);
            ind++;
        }
        if (boots[i].agility > largestInterval) canUse[boots[i].id] = true;
    }
    for (int i = 0; i < bootCount; i++) {
        cout << canUse[i] << endl;
    }
    return 0;
}
