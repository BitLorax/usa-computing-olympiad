//
// Created by willj on 11/2/2019.
//

#include <iostream>
#include <fstream>

#define MAX_N 100000
#define MAX_NODES 20000000

using namespace std;

namespace segTree {
    struct Node {
        int val, l, r;
    };
    int next;
    Node nodes[MAX_NODES + 1];

    int get(int node, bool i) {
        if (!i) return nodes[node].l = (nodes[node].l) ? nodes[node].l : ++next;
        else return nodes[node].r = (nodes[node].r) ? nodes[node].r : ++next;
    }
    void add(int i, int v, int node, int a = 0, int b = MAX_N + 10) {
        nodes[node].val += v;
        if (a == b) return;
        int mid = (a + b) / 2;
        if (i <= mid) add(i, v, get(node, 0), a, mid);
        else add(i, v, get(node, 1), mid + 1, b);
    }
    int query(int lo, int hi, int node, int a = 0, int b = MAX_N + 10) {
        if (a >= lo && b <= hi) {
            return nodes[node].val;
        }
        if (a > hi || b < lo) return 0;
        int mid = (a + b) / 2;
        return (nodes[node].l != 0 ? query(lo, hi, nodes[node].l, a, mid) : 0) +
               (nodes[node].r != 0 ? query(lo, hi, nodes[node].r, mid + 1, b) : 0);
    }
}
namespace fenwicks {
    int n;
    void update(int x, int y, int add) {
        for (++x; x <= n; x += x&-x)
            segTree::add(y, add, x);
    }
    int query(int x, int y) {
        int ans = 0;
        for (++x; x > 0; x -= x&-x)
            ans += segTree::query(0, y, x);
        return ans;
    }
}

int pos[MAX_N + 1][2];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("friendcross.in");
    ofstream cout("friendcross.out");

    int n, k; cin >> n >> k;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            int a; cin >> a; a--;
            pos[a][j] = i;
        }
    }

    segTree::next = n + 5;
    fenwicks::n = n;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (i - k - 1 < 0) continue;
        fenwicks::update(pos[i - k - 1][0], pos[i - k - 1][1], 1);
        res += fenwicks::query(n + 1, pos[i][1]) + fenwicks::query(pos[i][0], n + 1) - 2 * fenwicks::query(pos[i][0], pos[i][1]);
    }
    cout << res << endl;
    return 0;
}
