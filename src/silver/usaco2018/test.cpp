//
// Created by WillJ on 12/15/2018.
//
#include <iostream>

using namespace std;
#define MAX_LEN 101

using namespace std;

int board[10][MAX_LEN];
int len;
bool visited[10][MAX_LEN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void fall() {
    for (int i = 0; i < 10; i++) { //column
        int bottom = -1;
        bool bottomCleared = false;
        for (int j = len - 1; j >= 0; j--) {
            if (board[i][j] == 0 && bottom == -1) {
                bottom = j;
                continue;
            }
            if (board[i][j] != 0 && bottom != -1) bottomCleared = true;
            if (bottomCleared && bottom != -1) {
                board[i][bottom--] = board[i][j];
            }
        }
        for (int j = bottom; j >= 0; j--) board[i][j] = 0;
    }
}

int main() {
    int requirement; cin >> len >> requirement;
    for (int i = 0; i < len; i++) {
        string row; cin >> row;
        for (int j = 0; j < 10; j++) {
            board[j][i] = (row[j]) - '0';
        }
    }
    fall();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[j][i];
        }
        cout << endl;
    }
    return 0;
}