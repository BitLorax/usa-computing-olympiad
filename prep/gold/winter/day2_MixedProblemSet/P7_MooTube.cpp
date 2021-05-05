//
// Created by WillJ on 12/27/2018.
//

//DISJOINT SET

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000000
#define MAX_VIDEOCNT 100000
#define MAX_QUERYCNT 100000

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

Connection connections[MAX_VIDEOCNT];
Query queries[MAX_QUERYCNT];
int parent[MAX_VIDEOCNT + 1];
int size[MAX_VIDEOCNT + 1];
int answers[MAX_QUERYCNT];

int find(int node) {
    if (parent[node] == 0) return node;
    return find(parent[node]);
}
void join(int a, int b) {
    int aPar = find(a), bPar = find(b);
    if (aPar == bPar) return;
    if (size[aPar] > size[bPar]) {
        parent[bPar] = aPar;
        size[aPar] += size[bPar];
    } else {
        parent[aPar] = bPar;
        size[bPar] += size[aPar];
    }
}

int main() {
    int videoCount, queryCount; cin >> videoCount >> queryCount;
    for (int i = 0; i < videoCount - 1; i++) {
        cin >> connections[i].one >> connections[i].two >> connections[i].relevance;
    }
    for (int i = 1; i <= videoCount; i++) size[i] = 1;
    for (int i = 0; i < queryCount; i++) {
        cin >> queries[i].relevance >> queries[i].start; //<start, relevance>
        queries[i].id = i;
    }
    sort(queries, queries + queryCount);
    sort(connections, connections + videoCount - 1);
    int j = 0;
    for (int i = 0; i < queryCount; i++) {
        Query cur = queries[i];
        for (j; j < videoCount - 1; j++) {
            if (connections[j].relevance >= cur.relevance) join(connections[j].one, connections[j].two);
            else break;
        }
        answers[cur.id] = size[find(cur.start)] - 1;
    }
    for (int i = 0; i < queryCount; i++) cout << answers[i] << endl;
    return 0;
}

