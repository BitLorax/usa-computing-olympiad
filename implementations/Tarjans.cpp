//
// Created by WillJ on 7/11/2019.
//

#include <bits/stdc++.h>

#define N 1000
#define f first
#define s second

using namespace std;

vector<int> c[N + 1];

namespace scc {
    int n;
    stack<int> s; //<bot, top>
    int in[N + 1], lo[N + 1], t = 0, count = 0;
    int scc[N + 1];
    bool v[N + 1];

    void dfs(int cur) {
        lo[cur] = in[cur] = ++t;
        v[cur] = true;
        s.emplace(cur);
        for (int to : c[cur]) {
            if (in[to] == -1) {
                dfs(to);
                lo[cur] = min(lo[cur], lo[to]);
            } else if (v[to]) {
                lo[cur] = min(lo[cur], lo[to]);
            }
        }
        if (lo[cur] == in[cur]) {
            while (1) {
                int a = s.top(); s.pop();
                scc[a] = count;
                v[a] = false;
                if (a == cur) break;
            }
            count++;
        }
    }
    void run() {
        memset(in, -1, sizeof in);
        memset(scc, -1, sizeof scc);
        for (int i = 0; i < n; i++) {
            if (!v[i]) dfs(i);
        }
    }
};

namespace bcc {
    int n;
    stack<pair<int, int>> s; //<bot, top>
    int in[N + 1], lo[N + 1], t = 0, count = 0;
    vector<int> bcc[N + 1];
    bool v[N + 1];

    bool biconnected(int a, int b) {
        for (int j : bcc[a]) {
            if (binary_search(bcc[b].begin(), bcc[b].end(), j)) return true;
        }
        return false;
    }
    void dfs(int cur, int par = -1) {
        lo[cur] = in[cur] = ++t;
        v[cur] = true;
        for (int to : c[cur]) {
            if (to == par) continue;
            if (!v[to]) {
                s.emplace(to, cur);
                dfs(to, cur);
                lo[cur] = min(lo[cur], lo[to]);
                if (lo[to] >= in[cur]) {
                    while (1) {
                        pair<int, int> p = s.top(); s.pop();
                        if (bcc[p.f].empty() || bcc[p.f].back() != count) bcc[p.f].push_back(count);
                        if (bcc[p.s].empty() || bcc[p.s].back() != count) bcc[p.s].push_back(count);
                        if (p.f == to && p.s == cur) break;
                    }
                    count++;
                }
            } else if (in[to] < in[cur]) {
                s.emplace(to, cur);
                lo[cur] = min(lo[cur], in[to]);
            }
        }
    }
    void run() {
        for (int i = 0; i < n; i++) {
            if (!v[i]) dfs(i);
        }
    }
};
