//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define INF 2000000000
#define MAX_FIELDCNT 100000

using namespace std;

set<int> connections[MAX_FIELDCNT + 1];
set<int> extended[MAX_FIELDCNT + 1];
int color[MAX_FIELDCNT + 1];
bool avaliable[MAX_FIELDCNT + 1];

int main() {

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int fieldCount; cin >> fieldCount;
    for (int i = 0; i < fieldCount - 1; i++) {
        int a, b; cin >> a >> b;
        connections[a].insert(b);
        connections[b].insert(a);
    }
    for (int i = 1; i <= fieldCount; i++) {
        for (auto it : connections[i]) {
            extended[i].insert(it);
            for (auto itit : connections[it]) {
                extended[i].insert(itit);
            }
        }
    }
    int maxColor = 0;
    for (int i = 1; i <= fieldCount; i++) {
        for (int j = 1; j <= fieldCount; j++) avaliable[j] = true;
        color[i] = 1;
        for (auto it : extended[i]) {
            if (color[it] != 0 && it != i) avaliable[color[it]] = false;
        }
        for (int j = 1; j <= fieldCount; j++) {
            if (avaliable[j]) {
                color[i] = j;
                break;
            }
        }
        maxColor = max(maxColor, color[i]);
    }
    cout << maxColor << endl;
    return 0;
}
