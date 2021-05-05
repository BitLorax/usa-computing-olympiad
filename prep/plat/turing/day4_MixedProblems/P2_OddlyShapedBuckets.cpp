//
// Created by willj on 11/3/2019.
//

#include <iostream>
#include <fstream>
#include <queue>

#define MAX_S 100
#define INF 2000000000

using namespace std;

bool grid[MAX_S + 1][MAX_S + 1];
int height[MAX_S + 1][MAX_S + 1];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct State{
    int x, y, h;
    bool operator<(const State &a) const {
        return h < a.h;
    }
};

int main() {
    int h, w; cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string row; cin >> row;
        for (int j = 0; j < w; j++) {
            grid[j][i] = (row[j] == 'X');
            height[j][i] = INF;
        }
    }

    int maxRes = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (grid[i][j]) continue;
            grid[i][j] = true;

            priority_queue<State> q;
            for (int ii = 0; ii < w; ii++)
                if (!grid[ii][h - 1]) q.push(State{ii, h - 1, h - 1});
            for (int jj = 0; jj < h - 1; jj++) {
                if (!grid[0][jj]) q.push({0, jj, jj});
                if (!grid[w - 1][jj]) q.push({w - 1, jj, jj});
            }
            while (!q.empty()) {
                State cur = q.top(); q.pop();
                if (cur.x < 0 || cur.x >= w || cur.y < 0 || cur.y >= h) continue;
                if (height[cur.x][cur.y] != INF) continue;
                if (grid[cur.x][cur.y]) continue;

                height[cur.x][cur.y] = cur.h;
                for (int k = 0; k < 4; k++) {
                    q.push(State{cur.x + dx[k], cur.y + dy[k], min(cur.h, cur.y + dy[k])});
                }
            }
            int res = 0;
            for (int ii = 0; ii < w; ii++) {
                for (int jj = 0; jj < h; jj++) {
                    if (grid[ii][jj]) continue;
                    if (height[ii][jj] < jj || height[ii][jj] == INF) res++;
                    height[ii][jj] = INF;
                }
            }
            maxRes = max(maxRes, res);
            grid[i][j] = false;
        }
    }

    cout << maxRes << endl;
    return 0;
}
