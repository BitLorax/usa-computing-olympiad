//
// Created by WillJ on 2/19/2019.
//

#include <iostream>
#include <set>
#include <queue>
#include <map>

#define INF 2000000000
#define MAX_LEN 250

using namespace std;

struct BoardState {
    int x, y;
};
struct Chunk {
    int color, size;
};

int board[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
bool preCalculated[MAX_LEN * MAX_LEN];

set<int> connections[MAX_LEN * MAX_LEN];
Chunk chunks[MAX_LEN * MAX_LEN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {

    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);

    int len; cin >> len;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cin >> board[j][i];
        }
    }
    int id = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (visited[j][i]) continue;
            int size = 0, color = board[j][i];
            queue<BoardState> q;
            q.push(BoardState{j, i});
            while (!q.empty()) {
                BoardState cur = q.front(); q.pop();
                if (cur.x < 0 || cur.x >= len || cur.y < 0 || cur.y >= len || (!visited[cur.x][cur.y] && board[cur.x][cur.y] != color)) continue;
                if (visited[cur.x][cur.y]) {
                    if (board[cur.x][cur.y] != id) connections[id].insert(board[cur.x][cur.y]);
                    continue;
                }
                visited[cur.x][cur.y] = true;
                board[cur.x][cur.y] = id;
                size++;
                for (int l = 0; l < 4; l++) {
                    q.push(BoardState{cur.x + dx[l], cur.y + dy[l]});
                }
            }

            chunks[id].color = color;
            chunks[id].size = size;
            id++;
        }
    }
    for (int i = 0; i < id; i++) {
        for (int j : connections[i]) {
            if (j != i) connections[j].insert(i);
        }
    }
    int maxOne = 0, maxTwo = 0;
    for (int i = 0; i < id; i++) {
        maxOne = max(maxOne, chunks[i].size);
    }
    for (int i = 0; i < id; i++) {
        if (preCalculated[i]) continue;
        map<int, bool> colorsTested;
        for (auto it = connections[i].begin(); it != connections[i].end(); it++) {
            if (colorsTested[chunks[*it].color]) continue;
            colorsTested[chunks[*it].color] = true;
            pair<int, int> colors = make_pair(chunks[i].color, chunks[*it].color);
            map<int, bool> visited;
            int size = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                if (visited[cur]) continue;
                if (chunks[cur].color != colors.first && chunks[cur].color != colors.second) continue;
                visited[cur] = true;
                if (chunks[cur].color == colors.first) preCalculated[cur] = true;

                size += chunks[cur].size;
                for (auto itt = connections[cur].begin(); itt != connections[cur].end(); itt++) {
                    q.push(*itt);
                }
            }
            maxTwo = max(maxTwo, size);
        }
    }
    cout << maxOne << endl << maxTwo << endl;
    return 0;
}
