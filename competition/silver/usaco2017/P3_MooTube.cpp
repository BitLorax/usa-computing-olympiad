//
// Created by WillJ on 2/18/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000000
#define MAX_VIDEOCNT 5001
#define MAX_QUERYCNT 5000

using namespace std;

struct Connection {
    int one, two, relevance;
    bool operator<(const Connection &a) const {
        return relevance > a.relevance;
    }
};
struct Query {
    int relevance, start, id;
    bool operator<(const Query &a) const {
        return relevance > a.relevance;
    }
};

vector<Connection> connections;
Query queries[MAX_QUERYCNT];
int videosReached[MAX_QUERYCNT];

int parent[MAX_VIDEOCNT];
int size[MAX_VIDEOCNT];

//Union Find
int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]); //path compression
}

void join(int a, int b) {
    int parA = find(a), parB = find(b);
    if (parA == parB) return;
    if (size[parA] <= size[parB]) {
        parent[parA] = parB;
        size[parB] += size[parA];
    }
    else {
        parent[parB] = parA;
        size[parA] += size[parB];
    }
}
//Union Find

int main() {

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int videoCount, queryCount; cin >> videoCount >> queryCount;
    for (int i = 0; i < MAX_VIDEOCNT; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < videoCount - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        connections.push_back(Connection{a, b, c});
    }
    sort(connections.begin(), connections.end());
    for (int i = 0; i < queryCount; i++) {
        cin >> queries[i].relevance >> queries[i].start;
        queries[i].id = i;
    }
    sort(queries, queries + queryCount);
    int indx = 0;
    for (int i = 0; i < queryCount; i++) {
        Query cur = queries[i];
        while (indx < connections.size() && connections[indx].relevance >= cur.relevance) {
            join(connections[indx].one, connections[indx].two);
            indx++;
        }
        videosReached[cur.id] = size[find(cur.start)];
    }
    for (int i = 0; i < queryCount; i++) {
        cout << videosReached[i] - 1 << endl;
    }
    return 0;
}
