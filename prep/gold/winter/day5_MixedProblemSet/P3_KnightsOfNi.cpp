//
// Created by WillJ on 12/30/2018.
//

#include <iostream>
#include <queue>

#define INF 2000000000
#define MAX_LEN 1000

using namespace std;

int map[MAX_LEN][MAX_LEN];
int dists[MAX_LEN][MAX_LEN][2];
bool visited[MAX_LEN][MAX_LEN][2];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Coord {
    int x, y, dist;
    int starter; //bessie or knights
};

int main() {
    int width, height; cin >> width >> height;
    Coord startB{-1, -1, 0, 0};
    Coord startK{-1, -1, 0, 1};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> map[j][i];
            if (map[j][i] == 2) {
                startB.x = j; startB.y = i;
            }
            if (map[j][i] == 3) {
                startK.x = j; startK.y = i;
            }
        }
    }
    queue<Coord> q;
    q.push(startB);
    q.push(startK);
    while (!q.empty()) {
        Coord cur = q.front(); q.pop();
        if (cur.x < 0 || cur.x >= width || cur.y < 0 || cur.y >= height) continue;
        if (visited[cur.x][cur.y][cur.starter]) continue;
        if (map[cur.x][cur.y] == 1 || (map[cur.x][cur.y] == 3 && cur.starter == 0)) continue;
        visited[cur.x][cur.y][cur.starter] = true;
        if (map[cur.x][cur.y] == 4) {
            dists[cur.x][cur.y][cur.starter] = cur.dist;
            continue;
        }
        for (int i = 0; i < 4; i++) {
            q.push(Coord{cur.x + dx[i], cur.y + dy[i], cur.dist + 1, cur.starter});
        }
    }
    int minDist = INF;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (dists[i][j][0] > 0 && dists[i][j][1] > 0) minDist = min(minDist, dists[i][j][0] + dists[i][j][1]);
        }
    }
    cout << minDist << endl;
    return 0;
}
