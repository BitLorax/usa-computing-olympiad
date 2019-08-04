//
// Created by WillJ on 7/11/2019.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>

#define INF 2000000000
#define N 1000

using namespace std;

vector<int> connections[N + 1];

namespace tarjans {
    bool inStack[N + 1];
    stack<int> nodes; //<bot, top>
    int in[N + 1], low[N + 1], t = 0, sccCount = 0;
    vector<int> scc[N + 1];

    bool biconnected(int a, int b) {
        for (int j : scc[a])
            if (binary_search(scc[b].begin(), scc[b].end(), j)) return true;
        return false;
    }

    void traverse(int cur) {
        low[cur] = in[cur] = ++t;
        nodes.push(cur); inStack[cur] = true;
        for (int j : connections[cur]) {
            if (in[j] == 0) {
                traverse(j);
                low[cur] = min(low[cur], low[j]);
            } else if (inStack[j]) {
                low[cur] = min(low[cur], in[j]);
            }
        }
        if (low[cur] == in[cur]) { //can't go any higher, found bcc
            while (true) {
                int n = nodes.top(); nodes.pop();
                inStack[n] = false;
                scc[n].push_back(sccCount);
                if (n == cur) break;
            }
            sccCount++;
        }
    }

    void run() {
        for (int i = 0; i < N; i++)
            if (in[i] == 0) traverse(i);
    }
}

int main() {
    return 0;
}
