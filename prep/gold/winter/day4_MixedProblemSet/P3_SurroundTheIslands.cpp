//
// Created by WillJ on 12/29/2018.
//

#include <iostream>
#include <queue>

#define INF 2000000000
#define MAX_VERTEXCNT 500

using namespace std;

int parent[MAX_VERTEXCNT + 1];
int depth[MAX_VERTEXCNT + 1];
//bool islandConnecs[MAX_VERTEXCNT + 1][MAX_VERTEXCNT + 1];
int seaConnecs[MAX_VERTEXCNT + 1][MAX_VERTEXCNT + 1];
int islandConnecs[MAX_VERTEXCNT + 1][MAX_VERTEXCNT + 1];
bool visited[MAX_VERTEXCNT + 1];

struct State {
    int curNode, len;
    bool operator<(const State &a) const {
        return len > a.len;
    }
};

//Union Find
int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]); //path compression
}

void join(int a, int b) {
    int parA = find(a), parB = find(b);
    if (parA == parB) return;
    if (depth[parA] < depth[parB]) {
        parent[parA] = parB;
    }
    else if (depth[parB] < depth[parA]) {
        parent[parB] = parA;
    }
    else {
        parent[parA] = parB;
        depth[parB]++;
    }
}
//Union Find


int main() {
    int vertexCount; cin >> vertexCount;
    for (int i = 1; i <= vertexCount; i++) parent[i] = i;
    for (int i = 0; i < vertexCount; i++) {
        int a, b; cin >> a >> b;
        join(a, b);
//        islandConnecs[a][b] = true;
//        islandConnecs[b][a] = true;
    }
    for (int i = 1; i <= vertexCount; i++) {
        for (int j = 1; j <= vertexCount; j++) {
            cin >> seaConnecs[j][i];
            islandConnecs[j][i] = INF;
        }
    }
    for (int i = 1; i <= vertexCount; i++) {
        for (int j = 1; j < i; j++) { //j ALWAYS less than i
            if (seaConnecs[i][j] == 0) continue;
            int parI = find(i), parJ = find(j);
            islandConnecs[parI][parJ] = min(islandConnecs[parI][parJ], seaConnecs[i][j]);
            islandConnecs[parJ][parI] = min(islandConnecs[parJ][parI], seaConnecs[i][j]);
        }
    }
    int minCost = INF;
    for (int i = 1; i <= vertexCount; i++) {
        if (parent[i] != i) continue;
        int cost = 0;
        for (int j = 1; j <= vertexCount; j++) {
            if (i == j) continue;
            if (islandConnecs[i][j] != INF) cost += 2 * islandConnecs[i][j];
        }
        minCost = min(minCost, cost);
    }
    cout << minCost << endl;
    return 0;
}
