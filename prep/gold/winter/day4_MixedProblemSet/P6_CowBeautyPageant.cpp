//
// Created by WillJ on 12/29/2018.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000
#define MAX_LEN 50

using namespace std;

struct Coord {
    int x, y;
};

bool cow[MAX_LEN][MAX_LEN];
vector<Coord> spots[3];
bool visited[MAX_LEN][MAX_LEN];
int minDists[3][3];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int getLen(Coord a, Coord b) {
    int ret = abs(a.x - b.x) + abs(a.y - b.y);
    ret--; //over-counted corner block OR straight line
    return ret;
}

int main() {
    int height, width; cin >> height >> width;
    for (int i = 0; i < height; i++) {
        string row; cin >> row;
        for (int j = 0; j < width; j++) {
            cow[j][i] = (row[j] == 'X');
        }
    }
    int spotsFound = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (!cow[i][j] || visited[i][j]) continue;
            queue<Coord> q;
            q.push(Coord{i, j});
            while (!q.empty()) {
                Coord cur = q.front(); q.pop();
                if (cur.x < 0 || cur.x >= width || cur.y < 0 || cur.y >= height) continue;
                if (visited[cur.x][cur.y] || !cow[cur.x][cur.y]) continue;
                visited[cur.x][cur.y] = true;
                spots[spotsFound].push_back(Coord{cur.x, cur.y});
                for (int l = 0; l < 4; l++) {
                    q.push(Coord{cur.x + dx[l], cur.y + dy[l]});
                }
            }
            spotsFound++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            int minDist = INF;
            for (int k = 0; k < spots[i].size(); k++) {
                for (int l = 0; l < spots[j].size(); l++) {
                    minDist = min(minDist, getLen(spots[i][k], spots[j][l]));
                }
            }
            minDists[i][j] = minDist;
            minDists[j][i] = minDist;
        }
    }
    int minDist = min(minDists[0][1] + minDists[0][2], min(minDists[0][1] + minDists[1][2], minDists[0][2] + minDists[1][2]));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (cow[i][j]) continue;
            Coord cur{i, j};
            int distOne = INF, distTwo = INF, distThree = INF;
            for (int k = 0; k < spots[0].size(); k++) {
                distOne = min(distOne, getLen(cur, spots[0][k]));
            }
            for (int k = 0; k < spots[1].size(); k++) {
                distTwo = min(distTwo, getLen(cur, spots[1][k]));
            }
            for (int k = 0; k < spots[2].size(); k++) {
                distThree = min(distThree, getLen(cur, spots[2][k]));
            }
            minDist = min(minDist, distOne + distTwo + distThree + 1);
        }
    }
    cout << minDist << endl;
    return 0;
}
