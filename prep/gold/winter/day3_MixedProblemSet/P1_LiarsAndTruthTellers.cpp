//
// Created by WillJ on 12/28/2018.
//

#include <iostream>
#include <queue>

#define INF 2000000000
#define MAX_COWCNT 1000
#define MAX_STATEMENTCNT 10000

using namespace std;

struct Statement {
    int from, to;
    bool truth;
};

int parent[MAX_COWCNT + 1];
int r[MAX_COWCNT + 1];

int cowCount, statementCount;
Statement statements[MAX_STATEMENTCNT];
int connections[MAX_COWCNT + 1][MAX_COWCNT + 1]; //true -> i = j, false -> i != j
bool visited[MAX_COWCNT + 1];

//Union Find
int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]); //path compression
}

void join(int a, int b) {
    int parA = find(a), parB = find(b);
    if (parA == parB) return;
    if (r[parA] < r[parB]) {
        parent[parA] = parB;
    }
    else if (r[parB] < r[parA]) {
        parent[parB] = parA;
    }
    else {
        parent[parA] = parB;
        r[parB]++;
    }
}
//Union Find


bool test(int s) {
    for (int i = 0; i < s; i++) {
        Statement cur = statements[i];
        int connec = 0;
        //test connection
        queue<pair<int, bool>> q;
        q.push(make_pair(cur.from, true));
        while (!q.empty()) {
            pair<int, bool> curNode = q.front(); q.pop();
            if (curNode.first == cur.to) {
                connec = (curNode.second) ? 1 : -1;
            }
            if (visited[curNode.first]) continue;
            visited[curNode.first] = true;
            for (int j = 1; j <= cowCount; j++) {
                if (connections[curNode.first][j] != 0) {
                    pair<int, bool> n = curNode;
                    n.first = j;
                    if (connections[curNode.first][j] == -1) n.second = !n.second;
                    q.push(n);
                }
            }
        }
        for (int j = 1; j <= cowCount; j++) visited[j] = false;
        int curTruth = (cur.truth) ? 1 : -1;
        if (connec != 0 && curTruth != connec) return false;
        connections[cur.from][cur.to] = (cur.truth) ? 1 : -1;
        connections[cur.to][cur.from]  = (cur.truth) ? 1 : -1;
    }
    return true;
}
bool test2(int s) {
    Statement cur = statements[s];
    if (!cur.truth) { //use union find, speed up maybe?
        if (find(cur.from) == find(cur.to)) return false;
    }
    if (cur.truth) {
        if (find(cur.from) == find(cur.to)) return true;

    }
    int connec = 0;
    //test connection
    queue<pair<int, bool>> q;
    q.push(make_pair(cur.from, true));
    while (!q.empty()) {
        pair<int, bool> curNode = q.front(); q.pop();
        if (curNode.first == cur.to) {
            connec = (curNode.second) ? 1 : -1;
        }
        if (visited[curNode.first]) continue;
        visited[curNode.first] = true;
        for (int j = 1; j <= cowCount; j++) {
            if (connections[curNode.first][j] != 0) {
                pair<int, bool> n = curNode;
                n.first = j;
                if (connections[curNode.first][j] == -1) n.second = !n.second;
                q.push(n);
            }
        }
    }
    for (int j = 1; j <= cowCount; j++) visited[j] = false;
    int curTruth = (cur.truth) ? 1 : -1;
    if (connec != 0 && curTruth != connec) return false;
    connections[cur.from][cur.to] = (cur.truth) ? 1 : -1;
    connections[cur.to][cur.from]  = (cur.truth) ? 1 : -1;
    if (cur.truth) {
        join(cur.from, cur.to);
    }
    return true;
}

int main() {
    cin >> cowCount >> statementCount;
    for (int i = 0; i < statementCount; i++) {
        char a;
        cin >> statements[i].from >> statements[i].to >> a;
        statements[i].truth = (a == 'T');
    }
    for (int i = 1; i <= cowCount; i++) {
        parent[i] = i;
        r[i] = 1;
    }
    int i = 0;
    for (i = 0; i < statementCount; i++) {
        if (!test2(i)) break;
    }
    cout << i << endl;
//    int lo = 0, hi = statementCount;
//    while (lo < hi) {
//        int mid = (lo + hi) / 2;
//        if (test(mid)) {
//            lo = mid + 1;
//        } else {
//            hi = mid;
//        }
//        for (int i = 0; i <= MAX_COWCNT; i++) {
//            for (int j = 0; j <= MAX_COWCNT; j++) {
//                connections[i][j] = 0;
//            }
//        }
//    }
//    cout << lo - 1 << endl;
    return 0;
}
