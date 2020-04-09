//
// Created by WillJ on 12/15/2018.
//
#include <iostream>
#include <queue>

#define MAX_LEN 101

using namespace std;

int board[10][MAX_LEN];
int len;
bool visited[10][MAX_LEN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct State {
    int x, y, color;
};

void fall() { //FAULTY
    for (int i = 0; i < 10; i++) {
        int to = -1; //lowest
        int from = -1;
        for (int j = len - 1; j >= 0; j--) { //lowest empty space
            if (board[i][j] == 0) {
                to = j;
                break;
            }
        }
        for (int j = to - 1; j >= 0; j--) { //lowest block
            if (board[i][j] != 0) {
                from = j;
                break;
            }
        }
        for (int j = from; j >= 0; j--, to--) {
            board[i][to] = board[i][j];
        }
        for (int j = to; j >= 0; j--) board[i][j] = 0;
    }
}

int main() {

    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);

    int requirement; cin >> len >> requirement;
    for (int i = 0; i < len; i++) {
        string row; cin >> row;
        for (int j = 0; j < 10; j++) {
            board[j][i] = (row[j]) - '0';
        }
    }
    bool keepGoing = true;
    while (keepGoing) {
        keepGoing = false;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[j][i] == 0) continue;
                for (int k = 0; k < 10; k++) for (int l = 0; l < len; l++) visited[k][l] = false;
                queue<State> q;
                int numVisited = 0;
                q.push(State{j, i, board[j][i]});
                while (!q.empty()) { //check
                    State curr = q.front(); q.pop();
                    if (curr.x < 0 || curr.x >= 10 || curr.y < 0 || curr.y >= len) continue;
                    if (board[curr.x][curr.y] != curr.color) continue;
                    if (visited[curr.x][curr.y]) continue;
                    visited[curr.x][curr.y] = true;
                    numVisited++;
                    for (int l = 0; l < 4; l++) {
                        State newState{curr.x + dx[l], curr.y + dy[l], curr.color};
                        q.push(newState);
                    }
                }
                if (numVisited >= requirement) {
                    keepGoing = true;
                    for (int k = 0; k < 10; k++) {
                        for (int l = 0; l < len; l++) {
                            if (visited[k][l]) board[k][l] = 0;
                            visited[k][l] = false;
                        }
                    }
                }
            }
        }
        fall();
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[j][i];
        }
        cout << endl;
    }
    return 0;
}
/*
 * if (numVisited >= requirement) { //delete
                    keepGoing = true;
                    q.push(State{j, i, board[j][i]});
                    while (!q.empty()) {
                        State curr = q.front(); q.pop();
                        if (curr.x < 0 || curr.x >= 10 || curr.y < 0 || curr.y >= len) continue;
                        if (board[curr.x][curr.y] != curr.color) continue;
                        if (visited[curr.x][curr.y]) continue;
                        visited[curr.x][curr.y] = true;
                        board[curr.x][curr.y] = 0;
                        for (int l = 0; l < 4; l++) {
                            State newState{curr.x + dx[l], curr.y + dy[l], curr.color};
                            q.push(newState);
                        }
                    }
                }
 */

