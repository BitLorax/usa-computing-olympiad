//
// Created by WillJ on 2/24/2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <fstream>

#define INF 2000000000
#define MAX_ATTRACTIONCNT 100000 + 10

using namespace std;
int mins[MAX_ATTRACTIONCNT][(int)(log2(MAX_ATTRACTIONCNT))];
int depth[MAX_ATTRACTIONCNT + 1];
int pos[MAX_ATTRACTIONCNT + 1];

vector<int> order;
bool visited[MAX_ATTRACTIONCNT + 1];
vector<int> orderDepths;

//Range Minimum Query
void preprocessRMQ(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) mins[i][0] = i;
    for (int j = 1; (1 << j) <= arr.size(); j++) {
        for (int i = 0; (i + (1 << j)) <= arr.size(); i++) {
            if (arr[mins[i][j - 1]] < arr[mins[i + (1 << (j - 1))][j - 1]]) mins[i][j] = mins[i][j - 1];
            else mins[i][j] = mins[i + (1 << (j - 1))][j - 1];
        }
    }
}
int queryRMQ(vector<int> &arr, int lo, int hi) {
    int i = (int)(log2(hi - lo + 1));
    if (arr[mins[lo][i]] <= arr[mins[hi - (1 << i) + 1][i]]) return mins[lo][i];
    return mins[hi - (1 << i) + 1][i];
}
//Range Minimum Query

void calcDepths(vector<int> connections[], int from) {
    for (int i = 0; i < connections[from].size(); i++) {
        if (depth[connections[from][i]] == 0) {
            depth[connections[from][i]] = depth[from] + 1;
            calcDepths(connections, connections[from][i]);
        }
    }
}
void findTraversalOrder(vector<int> connections[], int from) {
    order.push_back(from);
    visited[from] = true;
    for (int i = 0; i < connections[from].size(); i++) {
        if (!visited[connections[from][i]]) {
            findTraversalOrder(connections, connections[from][i]);
            order.push_back(from);
        }
    }
}
int calcOrderDepths() {
    for (int i = 0; i < order.size(); i++) orderDepths.push_back(depth[order[i]]);
}
void findFirstOccurrence() {
    for (int i = 0; i <= MAX_ATTRACTIONCNT; i++) pos[i] = -1;
    for (int i = 0; i < order.size(); i++) {
        if (pos[order[i]] == -1) pos[order[i]] = i;
    }
}

void construct(vector<int> connections[]) {
    depth[1] = 1;
    calcDepths(connections, 1);
    findTraversalOrder(connections, 1);
    calcOrderDepths();
    findFirstOccurrence();
    preprocessRMQ(orderDepths);
}
int query(int a, int b) {
    int lo = min(pos[a], pos[b]), hi = max(pos[a], pos[b]);
    return order[queryRMQ(orderDepths, lo, hi)];
}

int attractionInfo[MAX_ATTRACTIONCNT + 1];
vector<int> connections[MAX_ATTRACTIONCNT + 1];
int dists[MAX_ATTRACTIONCNT + 1]; //dists[i] = root to i

int getDist(int a, int b) { //a higher than b
    return dists[b]^dists[a];
}
void calcDists(int attractionCount) {
    for (int i = 0; i <= attractionCount; i++) visited[i] = false;
    queue<pair<int, int>> q;
    q.push(make_pair(1, attractionInfo[1]));
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if (visited[cur.first]) continue;
        dists[cur.first] = cur.second;
        visited[cur.first] = true;
        for (int i : connections[cur.first]) {
            q.push(make_pair(i, cur.second^attractionInfo[i]));
        }
    }
}

int main() {

    ifstream cin("cowland.in");
    ofstream cout("cowland.out");

    int attractionCount, queryCount; cin >> attractionCount >> queryCount;
    for (int i = 1; i <= attractionCount; i++) {
        cin >> attractionInfo[i];
    }
    for (int i = 0; i < attractionCount - 1; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    construct(connections);
    calcDists(attractionCount);
    for (int i = 0; i < queryCount; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            attractionInfo[b] = c;
            calcDists(attractionCount);
        } else {
            int lca = query(b, c);
            int one = (getDist(lca, b)), two = getDist(lca, c);
            int ans = one ^two ^attractionInfo[lca];
            cout << ans << endl;
        }
    }
    return 0;
}
