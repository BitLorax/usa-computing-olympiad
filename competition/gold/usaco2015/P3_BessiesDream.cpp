//
// Created by Will Liang on 8/18/2018.
//
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 2000000000;

int visited[1000][1000][2];
int colors[1000][1000];
int height, width;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct State {
    int moveCount, x, y;
    int smellsLikeOranges;
    State() {
        moveCount = 0;
        smellsLikeOranges = false;
        x = 0;
        y = 0;
    }
    State(int a, int b, int x, int y) {
        moveCount = a;
        smellsLikeOranges = b;
        this->x = x;
        this->y = y;
    }
    bool operator<(const State &a) const {
        return moveCount > a.moveCount;
    }
};
bool canMoveTo(State to) {
    if (to.x < 0 || to.x >= width || to.y < 0 || to.y >= height) return false;
    if (colors[to.x][to.y] == 0) return false;
    if (colors[to.x][to.y] == 3) return (to.smellsLikeOranges == 1);
    return true;
}
int main() {

    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);


    cin >> height;
    cin >> width;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            visited[j][i][0] = MAX;
            visited[j][i][1] = MAX;
            cin >> colors[j][i];
        }
    }

    priority_queue<State> states;
    states.push(State{0, 0, 0, 0});
    bool success = false;
    while (states.size() > 0) {
        State curr = states.top();
        states.pop();
        if (curr.x == width - 1 && curr.y == height - 1) {
            cout << curr.moveCount;
            success = true;
            break;
        }
        if (visited[curr.x][curr.y][curr.smellsLikeOranges] != MAX) {
            continue;
        }
        visited[curr.x][curr.y][curr.smellsLikeOranges] = curr.moveCount;
        for (int i = 0; i < 4; i++) {
            State next{curr.moveCount + 1, curr.smellsLikeOranges, curr.x + dx[i], curr.y + dy[i]};
            if (!canMoveTo(next)) continue;
            if (colors[next.x][next.y] == 4) {
                next.smellsLikeOranges = 0;
                while (colors[next.x][next.y] == 4 && canMoveTo(State{-1, 0, next.x + dx[i], next.y + dy[i]})) {
                    next.x += dx[i];
                    next.y += dy[i];
                    next.moveCount++;
                }
            }
            if (colors[next.x][next.y] == 2) {
                next.smellsLikeOranges = 1;
            }
            if (visited[next.x][next.y][next.smellsLikeOranges] < next.moveCount) continue;
            states.push(next);
        }
    }
    if (!success) {
        cout << -1;
    }
    return 0;
}

