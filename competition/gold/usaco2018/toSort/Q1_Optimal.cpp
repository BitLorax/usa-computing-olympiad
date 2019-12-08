//
// Created by WillJ on 2/24/2019.
//

#include <iostream>
#include <vector>

#define INF 2000000000
#define MAX_ATTRACTIONCNT 100000

using namespace std;

int attractionInfo[MAX_ATTRACTIONCNT + 1];
vector<int> connections[MAX_ATTRACTIONCNT + 1];
vector<int> path;
bool visited[MAX_ATTRACTIONCNT + 1];
int depth[MAX_ATTRACTIONCNT + 1];

int fenwick[MAX_ATTRACTIONCNT + 1];

int queryFenwick(int index) {
    int ans = 0;
    for (; index > 0; index -= index&-index) ans = ans^fenwick[index];
    return ans;
}
void updateFenwick(int index, int add) {
    for (; index <= MAX_ATTRACTIONCNT; index += index&-index) fenwick[index] += add;
}

void traverse(int node, int d) {
    path.push_back(node);
    if (depth[node] == 0) depth[node] = d;
    visited[node] = true;
    for (int i : connections[node]) {
        if (visited[i]) continue;
        traverse(i, d + 1);
        path.push_back(node);
    }
}

int main() {
    int attractionCount, queryCount; cin >> attractionCount >> queryCount;
    for (int i = 1; i <= attractionCount; i++) {
        cin >> attractionInfo[i];
    }
    for (int i = 0; i < attractionCount - 1; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    traverse(1, 1);
    for (int i = 0; i < path.size(); i++) {
        updateFenwick(i, attractionInfo[path[i]]);
    }
    for (int i = 0; i < queryCount; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) return 0;

    }
    return 0;
}
