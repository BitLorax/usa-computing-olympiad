//
// Created by WillJ on 1/19/2019.
//

#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2000000000
#define MAX_LEN 1000

using namespace std;

struct Coord {
    int x, y;
};

int map[MAX_LEN + 2][MAX_LEN + 2];
vector<int> maxAreas;
bool visited[MAX_LEN + 2][MAX_LEN + 2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    int len; cin >> len; len += 2;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            map[i][j] = -1;
        }
    }
    for (int i = 1; i < len - 1; i++) {
        string row; cin >> row;
        for (int j = 1; j < len - 1; j++) {
            map[j][i] = (row[j - 1] == '#') ? 0 : -1;
        }
    }
    int maxArea = 0, id = 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (map[i][j] == 0) {
                int area = 0;
                queue<Coord> q;
                q.push(Coord{i, j});
                while (!q.empty()) {
                    Coord cur = q.front(); q.pop();
                    if (cur.x < 0 || cur.x >= len || cur.y < 0 || cur.y >= len) continue;
                    if (map[cur.x][cur.y] != 0) continue;
                    map[cur.x][cur.y] = id;
                    area++;
                    for (int ii = 0; ii < 4; ii++) {
                        q.push(Coord{cur.x + dx[ii], cur.y + dy[ii]});
                    }
                }
                if (area == maxArea) {
                    maxAreas.push_back(id);
                }
                if (area > maxArea) {
                    maxArea = area;
                    maxAreas.clear();
                    maxAreas.push_back(id);
                }
                id++;
            }
        }
    }
    int minPerimeter = INF;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (map[i][j] != -1 && binary_search(maxAreas.begin(), maxAreas.end(), map[i][j])) { //eligible for check
                for (int ii = 0; ii < len; ii++) {
                    for (int jj = 0; jj < len; jj++) {
                        visited[ii][jj] = false;
                    }
                }
                int curId = map[i][j];
                int curPerimeter = 0;
                queue<Coord> q;
                q.push(Coord{i, j});
                while (!q.empty()) {
                    Coord cur = q.front(); q.pop();
                    if (cur.x < 0 || cur.x >= len || cur.y < 0 || cur.y >= len) continue;
                    if (map[cur.x][cur.y] != curId || visited[cur.x][cur.y]) continue;
                    visited[cur.x][cur.y] = true;
                    for (int ii = 0; ii < 4; ii++) {
                        if (map[cur.x + dx[ii]][cur.y + dy[ii]] == -1) curPerimeter++;
                        q.push(Coord{cur.x + dx[ii], cur.y + dy[ii]});
                    }
                }
                minPerimeter = min(minPerimeter, curPerimeter);
                maxAreas.erase(std::find(maxAreas.begin(), maxAreas.end(), curId));
            }
        }
    }
    cout << maxArea << " " << minPerimeter << endl;
    return 0;
}
