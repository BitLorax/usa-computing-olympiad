//
// Created by WillJ on 1/1/2019.
//

#include <iostream>
#include <queue>

#define INF 2000000000
#define N 1000
#define f first
#define s second

using namespace std;

int parent[N + 1];
vector<pair<int, int>> c[N];
int d[N + 1]; bool v[N + 1];

/**
 * Gets minimum edges in O(V^2)
 */
void prims() {
    for (int ii = 0; ii < N; ++ii) {
        int to = 1;
        for (int i = 1; i <= N; ++i) {
            if (!v[i] && d[i] < d[to]) to = i;
        }
        v[to] = true;
        for (pair<int, int> i : c[to]) {
            if (!v[i.f]) d[i.f] = min(d[i.f], i.s);
        }
    }
}

int main() {
    return 0;
}
