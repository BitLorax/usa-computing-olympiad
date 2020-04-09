//
// Created by willj on 11/25/2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

#define MAX_N 100000
#define MAX_M 100000
#define INF 2000000000
#define LOG 20

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

struct Slingshot {
    long long x, y, t;
    bool operator<(const Slingshot &a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
};
struct Query {
    long long a, b, id;
    bool operator<(const Query &u) const {
        if (a == u.a) return b < u.b;
        return a < u.a;
    }
};

Slingshot s[MAX_N + 1];
Query q[MAX_M + 1];
long long res[MAX_M + 1];
long long y[MAX_N + 1];
map<long long, long long> mp;

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("slingshot.in");
    ofstream cout("slingshot.out");

    long long n, m; cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        cin >> s[i].x >> s[i].y >> s[i].t;
        y[i] = s[i].y;
    }
    for (long long i = 0; i < m; i++) {
        cin >> q[i].a >> q[i].b; q[i].id = i;
        res[i] = INF;
    }
    sort(s, s + n);
    sort(q, q + m);
    sort(y, y + n);

    for (long long i = 0; i < n; i++) {
        mp.insert(make_pair(y[i], i));
    }

    segTree::n = n + 1;
    segTree::update(0, n, INF);
    long long j = 0;
    for (long long i = 0; i < m; i++) {
        while (j < n && s[j].x < q[i].a) {
            segTree::update(mp[s[j].y], mp[s[j].y], s[j].t - s[j].x - s[j].y);
            j++;
        }
        long long k = lower_bound(y, y + n, q[i].b) - y;
        res[q[i].id] = min(res[q[i].id], q[i].a + q[i].b + segTree::query(0, k - 1));
    }
    segTree::update(0, n, INF);
    j = 0;
    for (long long i = 0; i < m; i++) {
        while (j < n && s[j].x < q[i].a) {
            segTree::update(mp[s[j].y], mp[s[j].y], s[j].t - s[j].x + s[j].y);
            j++;
        }
        long long k = (q[i].b > y[n - 1]) ? n : lower_bound(y, y + n, q[i].b) - y;
        res[q[i].id] = min(res[q[i].id], q[i].a - q[i].b + segTree::query(k, n));
    }
    segTree::update(0, n, INF);
    j = n - 1;
    for (long long i = m - 1; i >= 0; i--) {
        while (j >= 0 && s[j].x >= q[i].a) {
            segTree::update(mp[s[j].y], mp[s[j].y], s[j].t + s[j].x - s[j].y);
            j--;
        }
        long long k = lower_bound(y, y + n, q[i].b) - y;
        res[q[i].id] = min(res[q[i].id], -q[i].a + q[i].b + segTree::query(0, k - 1));
    }
    segTree::update(0, n, INF);
    j = n - 1;
    for (long long i = m - 1; i >= 0; i--) {
        while (j >= 0 && s[j].x >= q[i].a) {
            segTree::update(mp[s[j].y], mp[s[j].y], s[j].t + s[j].x + s[j].y);
            j--;
        }
        long long k = (q[i].b > y[n - 1]) ? n : lower_bound(y, y + n, q[i].b) - y;
        res[q[i].id] = min(res[q[i].id], -q[i].a - q[i].b + segTree::query(k, n));
    }
    for (long long i = 0; i < m; i++) {
        res[q[i].id] = min(res[q[i].id], abs(q[i].b - q[i].a));
    }
    for (long long i = 0; i < m; i++) {
        cout << res[i] << endl;
    }
    return 0;
}
