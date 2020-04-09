//
// Created by WillJ on 1/11/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000000
#define MAX_VIDEOCNT 100000
#define MAX_QUERYCNT 100000

using namespace std;

struct Connection {
    int a, b, relevance;
    bool operator<(const Connection &a) const { //sort by greatest relevance
        return relevance > a.relevance;
    }
};
struct Query {
    int start, relevance, id;
    bool operator<(const Query &a) const { //sort by greatest relevance
        return relevance > a.relevance;
    }
};

Connection connections[MAX_VIDEOCNT];
Query queries[MAX_QUERYCNT];
int parent[MAX_VIDEOCNT];
int size[MAX_VIDEOCNT];
int videosSuggested[MAX_QUERYCNT];

//Union Find
int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]); //path compression
}

void join(int a, int b) {
    int parA = find(a), parB = find(b);
    if (parA == parB) return;
    if (size[parA] < size[parB]) {
        parent[parA] = parB;
        size[parB] += size[parA];
    }
    else if (size[parB] < size[parA]) {
        parent[parB] = parA;
        size[parA] += size[parB];
    }
    else {
        parent[parA] = parB;
        size[parB] += size[parA];
    }
}
//Union Find

int main() {

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int videoCount, queryCount; cin >> videoCount >> queryCount;
    for (int i = 0; i < videoCount - 1; i++) {
        cin >> connections[i].a >> connections[i].b >> connections[i].relevance;
    }
    for (int i = 0; i < queryCount; i++) {
        cin >> queries[i].relevance >> queries[i].start;
        queries[i].id = i;
    }
    sort(connections, connections + videoCount - 1);
    sort(queries, queries + queryCount);
    for (int i = 1; i <= videoCount; i++) { //set up union find
        parent[i] = i;
        size[i] = 1;
    }
    int indx = 0;
    for (int i = 0; i < queryCount; i++) {
        Query curQ = queries[i];
        while (indx < videoCount - 1 && connections[indx].relevance >= curQ.relevance) {
            join(connections[indx].a, connections[indx].b);
            indx++;
        }
        videosSuggested[curQ.id] = size[find(curQ.start)];
    }
    for (int i = 0; i < queryCount; i++) cout << videosSuggested[i] - 1 << endl;
    return 0;
}
