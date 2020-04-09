//
// Created by Will Liang on 9/2/2018.
//
#include <iostream>
#include <queue>

#define INF 2000000000
#define MAX_SIDELEN 100

using namespace std;

struct State {
    int x, y;
    int time;
    int timeLeft; //before need to eat grass
    State (int a, int b, int c, int d) {
        x = a;
        y = b;
        time = c;
        timeLeft = d;
    }
    bool operator<(const State &a) const {
        return time > a.time;
    }
};

int map[MAX_SIDELEN][MAX_SIDELEN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[MAX_SIDELEN][MAX_SIDELEN][4];

int main() {

    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);

    int sideLen, crossTime; cin >> sideLen >> crossTime;
    for (int i = 0; i < sideLen; i++) {
        for (int j = 0; j < sideLen; j++) {
            cin >> map[j][i];
        }
    }
    priority_queue<State> states;
    states.push(State{0, 0, 0, 3});
    while (!states.empty()) {
        State currState = states.top();
        states.pop();
        visited[currState.x][currState.y][currState.timeLeft] = true;
        if (currState.x == sideLen - 1 && currState.y == sideLen - 1) {
            cout << currState.time << endl;
            break;
        }
        for (int i = 0; i < 4; i++) {
            State newState{currState.x + dx[i], currState.y + dy[i], currState.time + crossTime, currState.timeLeft - 1};
            if (newState.x < 0 || newState.x >= sideLen || newState.y < 0 || newState.y >= sideLen) continue;
            if (newState.timeLeft == 0) {
                newState.time += map[newState.x][newState.y];
                newState.timeLeft = 3;
            }
            if (visited[newState.x][newState.y][newState.timeLeft]) continue;
            visited[newState.x][newState.y][newState.timeLeft] = true;
            states.push(newState);
        }
    }
    return 0;
}
