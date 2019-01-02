//
// Created by WillJ on 12/28/2018.
//

#include <iostream>

#define INF 2000000000
#define N 1000

using namespace std;

int parent[N];
int depth[N];

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
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        depth[i] = 1;
    }
    return 0;
}
