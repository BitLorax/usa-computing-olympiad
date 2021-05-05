//
// Created by WillJ on 12/31/2018.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2000000000
#define MAX_BALECNT 50000
#define MAX_X 1000000

using namespace std;

struct Coord {
    int x, y, direc;
};

vector<int> bales[MAX_X + 1];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    int baleCount; cin >> baleCount;
    Coord cur{INF, INF, -1};
    for (int i = 0; i < baleCount; i++) {
        int a, b; cin >> a >> b;
        bales[a].push_back(b);
        if (a < cur.x) { //left most
            cur.x = a;
            cur.y = b;
        } else if (a == cur.x) { //lower
            cur.y = min(cur.y, b);
        }
    }
    cur.x--; cur.direc = 1;
    Coord s{cur.x, cur.y - 1};
    int perimeter = 0;
    while (cur.x != s.x || cur.y != s.y) {
        int x = cur.x, y = cur.y;
        x += dx[cur.direc]; y += dy[cur.direc];
        if (std::find(bales[x].begin(), bales[x].end(), y) != bales[x].end()) {
            perimeter++;
            cur.direc = (cur.direc - 1 + 4) % 4;
        } else {
            cur.x = x; cur.y = y;
            cur.direc = (cur.direc + 1) % 4;
        }
    }
    cout << perimeter << endl;
    return 0;
}
