//
// Created by WillJ on 12/28/2018.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000000
#define MAX_LEN 100

using namespace std;

struct Coord {
    int x, y;
    bool operator<(const Coord &b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};

int height, width;
bool board[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
vector<vector<Coord>> clusters;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<Coord> cluster;

void getCluster(int x, int y) {
    cluster.clear();
    queue<Coord> q;
    q.push(Coord{x, y});
    while (!q.empty()) {
        Coord cur = q.front(); q.pop();
        if (cur.x < 0 || cur.x >= width || cur.y < 0 || cur.y >= height) continue;
        if (!board[cur.x][cur.y]) continue;
        if (visited[cur.x][cur.y]) continue;
        visited[cur.x][cur.y] = true;
        cluster.push_back(Coord{cur.x, cur.y});
        for (int i = 0; i < 4; i++) {
            Coord newPos{cur.x, cur.y};
            newPos.x += dx[i]; newPos.y += dy[i];
            q.push(newPos);
        }
    }
}

void shift() { //shifts vector<Coord> cluster toward (0, 0); cluster should touch x = 0 and y = 0
    int minX = INF, minY = INF;
    for (int i = 0; i < cluster.size(); i++) {
        minX = min(minX, cluster[i].x); minY = min(minY, cluster[i].y);
    }
    for (int i = 0; i < cluster.size(); i++) {
        cluster[i].x -= minX; cluster[i].y -= minY;
    }
}

void rotate0() {

}

bool same(int a, int b) {
    vector<Coord> one = clusters[a];
    vector<Coord> two = clusters[b];
    if (one.size() != two.size()) return false;
    unsigned long len = one.size();

    cluster = one;
    shift();
    one = cluster;
    cluster = two;
    shift();
    two = cluster;
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    bool confirmed = true;
    //keep one stationary, try 8 rotations of two (clockwise)
    //0 degrees
    for (int i = 0; i < len; i++) {
        if (one[i].x != two[i].y || one[i].y != two[i].y) {
            confirmed = false;
            break;
        }
    }
    //90 degrees

}

int main() {
    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        string row; cin >> row;
        for (int j = 0; j < width; j++) {
            board[j][i] = (row[j] == '*');
        }
    }
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            getCluster(x, y);
            if (cluster.size() > 0) clusters.push_back(cluster);
        }
    }
    for (int i = 0; i < clusters.size(); i++) {
        for (int j = 0; j < i; j++) {

        }
    }
    return 0;
}
