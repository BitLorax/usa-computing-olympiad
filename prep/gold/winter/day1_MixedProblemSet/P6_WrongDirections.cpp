//
// Created by WillJ on 12/26/2018.
//

#include <iostream>
#include <set>

#define MAX_LEN 100000

using namespace std;

struct State {
    int x, y, direc;
};

State preSums[MAX_LEN];
set<pair<int, int>> newLocs;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

State turnRight(State &initialVector) {
    return State{initialVector.y, -1 * initialVector.x, (initialVector.direc + 1) % 4};
}
State turnLeft(State &initialVector) {
    return State{-1 * initialVector.y,initialVector.x, (initialVector.direc - 1 + 3) % 4};
}

int main() {
    string instructions; cin >> instructions;
    long instrucLen = instructions.size();
    int xMove = 0, yMove = 0, direc = 0;
    for (int i = 0; i < instrucLen; i++) {
        if (instructions[i] == 'F') {
            xMove += dx[direc];
            yMove += dy[direc];
        }
        if (instructions[i] == 'R') {
            direc = (direc + 1) % 4;
        }
        if (instructions[i] == 'L') {
            direc = (direc - 1 + 4) % 4;
        }
        preSums[i].x = xMove;
        preSums[i].y = yMove;
        preSums[i].direc = direc;
    }
    for (int i = 0; i < instructions.size(); i++) {
        State cur{preSums[i].x, preSums[i].y, preSums[i].direc};
        State next{preSums[instrucLen - 1].x - preSums[i].x, preSums[instrucLen - 1].y - preSums[i].y, -1};

        if (instructions[i] == 'F') {
            //negate 'F'
            cur.x -= dx[cur.direc]; cur.y -= dy[cur.direc];
            //turn right
            State r = turnRight(next);
            newLocs.insert(make_pair(cur.x + r.x, cur.y + r.y));
            //turn left
            State l = turnLeft(next);
            newLocs.insert(make_pair(cur.x + l.x, cur.y + l.y));
        } else {
            if (instructions[i] == 'R') {
                //negate 'R'
                cur.direc = (cur.direc - 1 + 4) % 4;
                next = turnLeft(next);
                //turn left
                State l = turnLeft(next);
                newLocs.insert(make_pair(cur.x + l.x, cur.y + l.y));
                //forward
                cur.x += dx[cur.direc]; cur.y += dy[cur.direc];
                newLocs.insert(make_pair(cur.x + next.x, cur.y + next.y));
            }
            if (instructions[i] == 'L') {
                //negate 'L'
                cur.direc = (cur.direc + 1) % 4;
                next = turnRight(next);
                //turn left (again)
                State r = turnRight(next);
                newLocs.insert(make_pair(cur.x + r.x, cur.y + r.y));
                //forward
                cur.x += dx[cur.direc]; cur.y += dy[cur.direc];
                newLocs.insert(make_pair(cur.x + next.x, cur.y + next.y));
            }
        }
    }
    cout << newLocs.size() << endl;
    return 0;
}
