//
// Created by willj on 10/20/2019.
//

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

char grid[310][310];
int id[310][310];
int size[310 * 310];
bool used[310 * 310];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c, colored; cin >> r >> c >> colored;
        bool valid = true;
        for (int j = 0; j < r; j++) {
            string row; cin >> row;
            for (int k = 0; k < c; k++) {
                if (row[k] == '#') grid[k][j] = -1; //black
                else grid[k][j] = -2; //white
            }
        }
        for (int j = 0; j < colored; j++) {
            int a, b, c; cin >> a >> b >> c; a--; b--;
            if (grid[b][a] == -1) valid = false;
            grid[b][a] = c;
        }
        if (!valid) {
            cout << "Puzzle #" << (i + 1) << ": Incorrect" << endl;
            continue;
        }
        for (int j = 0; j < c - 1; j++) {
            for (int k = 0; k < r - 1; k++) {
                if (grid[j][k] == -1 && grid[j + 1][k] == -1 && grid[j][k + 1] == -1 && grid[j + 1][k + 1] == -1) valid = false;
            }
        }
        if (!valid) {
            cout << "Puzzle #" << (i + 1) << ": Incorrect" << endl;
            continue;
        }
        queue<pair<int, int>> q;
        bool ll = true;
        for (int j = 0; j < c && ll; j++) {
            for (int k = 0; k < r; k++) {
                if (grid[j][k] == -1) {
                    q.push(make_pair(j, k));
                    ll = false;
                    break;
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            if (grid[cur.first][cur.second] != -1) continue;
            if (cur.first < 0 || cur.first >= c || cur.second < 0 || cur.second >= r) continue;
            grid[cur.first][cur.second] = -3; //confirmed black
            for (int l = 0; l < 4; l++) {
                q.push(make_pair(cur.first + dx[l], cur.second + dy[l]));
            }
        }
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < r; k++) {
                if (grid[j][k] == -1) {
                    valid = false;
                    break;
                }
            }
        }
        if (!valid) {
            cout << "Puzzle #" << (i + 1) << ": Incorrect" << endl;
            continue;
        }
        int curID = 1;
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < r; k++) {
                if (id[j][k] != 0 || grid[j][k] == -3) continue;
                int s = 0;
                queue<pair<int, int>> q;
                q.push(make_pair(j, k));
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    if (grid[cur.first][cur.second] == -3) continue;
                    if (id[cur.first][cur.second] != 0) continue;
                    if (cur.first < 0 || cur.first >= c || cur.second < 0 || cur.second >= r) continue;
                    id[cur.first][cur.second] = curID;
                    s++;
                    for (int l = 0; l < 4; l++) {
                        q.push(make_pair(cur.first + dx[l], cur.second + dy[l]));
                    }
                }
                size[curID] = s;
                curID++;
            }
        }
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < r; k++) {
                if (grid[j][k] < 0) continue;
                if (grid[j][k] != size[id[j][k]]) valid = false;
                if (used[id[j][k]]) valid = false;
                used[id[j][k]] = true;
            }
        }
        if (!valid) {
            cout << "Puzzle #" << (i + 1) << ": Incorrect" << endl;
            continue;
        }
        if (valid) {
            cout << "Puzzle #" << (i + 1) << ": Correct" << endl;
            continue;
        }
    }
    return 0;
}
