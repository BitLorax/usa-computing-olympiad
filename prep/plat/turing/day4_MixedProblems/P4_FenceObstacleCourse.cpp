//
// Created by willj on 11/23/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 50000
#define MAX_X 100000
#define LOG 20
#define INF 2000000000
#define f first
#define s second

using namespace std;

namespace segTree {
    int segTree[1 << LOG];
    int lazy[1 << LOG];
    int n;

    inline int func(int a, int b) {
        return min(a, b);
    }
    void push(int node, int a, int b) {
        if (lazy[node] != 0) {
            segTree[node] = lazy[node];
            if (a != b) {
                lazy[node * 2] = lazy[node];
                lazy[node * 2 + 1] = lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int i, int j, int val, int node = 1, int a = 0, int b = -1) {
        if (b == -1) b = n - 1;
        push(node, a, b);
        if (a > j || b < i) return;
        if (a >= i && b <= j) {
            lazy[node] = val;
            push(node, a, b);
            return;
        }
        update(i, j, val, node * 2, a, (a + b) / 2);
        update(i, j, val, node * 2 + 1, (a + b) / 2 + 1, b);
        segTree[node] = func(segTree[node * 2], segTree[node * 2 + 1]);
    }
    int query(int i, int j, int node = 1, int a = 0, int b = -1) {
        if (b == -1) b = n - 1;
        push(node, a, b);
        if (a > b || a > j || b < i) return INF;
        if (a >= i && b <= j) return segTree[node];
        int one = query(i, j, node * 2, a, (a + b) / 2);
        int two = query(i, j, node * 2 + 1, (a + b) / 2 + 1, b);
        return func(one, two);
    }
};

pair<int, int> a[MAX_N + 1];
pair<int, int> dist[MAX_N + 1];

int main() {
    int n, s; cin >> n >> s;
    a[n + 1].f = a[n + 1].s = MAX_X + s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f >> a[i].s;
        a[i].f += MAX_X; a[i].s += MAX_X;
    }
    segTree::n = 2 * MAX_X + 10;
    segTree::update(0, 2 * MAX_X, n + 1);
    for (int i = n; i >= 1; i--) {
        int k = segTree::query(a[i].f, a[i].f);
        dist[i].f = min(dist[k].f + abs(a[i].f - a[k].f), dist[k].s + abs(a[i].f - a[k].s));
        k = segTree::query(a[i].s, a[i].s);
        dist[i].s = min(dist[k].f + abs(a[i].s - a[k].f), dist[k].s + abs(a[i].s - a[k].s));
        segTree::update(a[i].f, a[i].s, i);
    }
    int k = segTree::query(MAX_X, MAX_X);
    cout << min(dist[k].f + abs(a[k].f - MAX_X), dist[k].s + abs(a[k].s - MAX_X)) << endl;
    return 0;
}
