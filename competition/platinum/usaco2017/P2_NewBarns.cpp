//
// Created by willj on 11/28/2019.
//

#include <iostream>
#include <fstream>
#include <vector>

#define MAX_Q 100000
#define MAX_N 100000
#define f first
#define s second

using namespace std;

struct Tree {
    int root, h1 = 0, h2 = 0, hI = -1;
};

pair<int, int> a[MAX_Q + 1];
vector<int> c[MAX_N + 1];
vector<int> roots;
int s[MAX_N + 1];
bool v[MAX_N + 1];
vector<pair<int, int>> d[MAX_N + 1];
Tree t[MAX_N + 1];

int getC(int cur, int par, int size) {
    for (int to : c[cur]) {
        if (to != par && !v[to] && s[to] * 2 >= size) return getC(to, cur, size);
    }
    return cur;
}
int getSize(int cur, int par) {
    s[cur] = 1;
    for (int to : c[cur]) {
        if (to != par && !v[to]) s[cur] += getSize(to, cur);
    }
    return s[cur];
}
void getDepth(int cur, int par, int t, int depth) {
    d[cur].emplace_back(t, depth);
    for (int to : c[cur]) {
        if (to != par && !v[to]) getDepth(to, cur, t, depth + 1);
    }
}
void build(int cur, int par) {
    getSize(cur, par);
    int cen = getC(cur, par, s[cur]);
    t[cen].root = cur; v[cen] = true;
    getDepth(cen, -1, cen, 0);
    for (int to : c[cen]) {
        if (!v[to]) build(to, cen);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("newbarn.in");
    ofstream cout("newbarn.out");

    int q; cin >> q;
    int n = 0;
    for (int i = 0; i < q; i++) {
        char u; int v; cin >> u >> v;
        if (u == 'B') {
            a[i].f = n++; a[i].s = --v;
            if (a[i].s == -2) roots.push_back(a[i].f);
            else {
                c[a[i].f].push_back(a[i].s);
                c[a[i].s].push_back(a[i].f);
            }
        } else {
            a[i].f = -1; a[i].s = --v;
        }
    }
    for (int r : roots) {
        build(r, -1);
    }

    int curN = 0;
    for (int i = 0; i < q; i++) {
        if (a[i].f != -1) {
            int prev = -1, cur = a[i].f;
            for (int j = d[cur].size() - 1; j >= 0; j--) {
                Tree &curT = t[d[cur][j].f];
                if (d[cur][j].s > curT.h1) {
                    if (prev != curT.hI) curT.h2 = curT.h1;
                    curT.h1 = d[cur][j].s;
                    curT.hI = prev;
                } else if (d[cur][j].s > curT.h2 && prev != curT.hI) {
                    curT.h2 = d[cur][j].s;
                }
                prev = curT.root;
            }
            curN++;
        } else {
            int prev = -1, cur = a[i].s;
            int res = 0;
            for (int j = d[cur].size() - 1; j >= 0; j--) {
                Tree &curT = t[d[cur][j].f];
                if (d[cur][j].f < curN) {
                    if (curT.hI != prev) res = max(res, curT.h1 + d[cur][j].s);
                    else res = max(res, curT.h2 + d[cur][j].s);
                }
                prev = curT.root;
            }
            cout << res << endl;
        }
    }
    return 0;
}
