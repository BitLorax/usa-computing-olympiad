//
// Created by WillJ on 1/2/2019.
//

#include <iostream>
#include <vector>
#include <cmath>

#define INF 2000000000
#define N 1000

using namespace std;

vector<int> connections[N + 1];

int mins[N][(int)(log2(N))];
int depth[N + 1];
int pos[N + 1];

vector<int> order;
bool visited[N + 1];
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
    for (int i = 0; i <= N; i++) pos[i] = -1;
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
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    construct(connections);
    cout << query(10, 15) << endl;
    cout << query(11, 14) << endl;
    return 0;
}
