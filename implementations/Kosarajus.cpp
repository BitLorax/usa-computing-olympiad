
#include <iostream>
#include <stack>
#include <vector>

#define N 1000

using namespace std;

vector<int> connections[N + 1];

namespace kosarajus {
    stack<int> s;
    vector<int> scc[N + 1];
    bool v[N + 1];
    vector<int> transposed[N + 1];

    void traverse(int cur) {
        v[cur] = true;
        for (int i : connections[cur])
            if (!v[cur]) traverse(i);
        s.push(cur);
    }
    void find(int cur, int id) {
        v[cur] = true;
        scc[id].push_back(cur);
        for (int i : transposed[cur])
            if (!v[i]) find(i, id);
    }
    /**
     * Records scc's in O(V + E)
     */
    void run() {
        for (int i = 0; i < N; i++) {
            if (!v[i]) traverse(i);
            for (int j : connections[i]) transposed[j].push_back(i);
        }
        for (int i = 0; i < N; i++) v[i] = false;
        int id = 0;
        while (!s.empty()) {
            int i = s.top(); s.pop();
            if (!v[i]) find(i, id++);
        }
    }
};
