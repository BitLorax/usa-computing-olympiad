//
// Created by willj on 10/19/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_N 100010
#define MAX_C 1000000000
#define f first
#define s second

using namespace std;

pair<int, int> coords[MAX_N + 1];


struct Node {
    int val;
    Node* c[2];
    Node() {
        val = 0;
        c[0] = c[1] = NULL;
    }
    Node* getC(int i) {
        if (!c[i]) c[i] = new Node();
        return c[i];
    }
    void add(int i, int v, int a = 0, int b = MAX_C) {
        val += v;
        if (a == b) return;
        int mid = (a + b) / 2;
        if (i <= mid) getC(0)->add(i, v, a, mid);
        else getC(1)->add(i, v, mid + 1, b);
    }
    int query(int i, int j, int a = 0, int b = MAX_C) {
        if (a >= i && b <= j) return val;
        if (a > j || b < i) return 0;
        int mid = (a + b) / 2;
        return (c[0] ? c[0]->query(i, j, a, mid) : 0) + (c[1] ? c[1]->query(i, j, mid + 1, b) : 0);
    }
};

namespace fenwicks {
    int n = MAX_N + 1;
    Node fenwick[MAX_N + 10];
    void update(int x, int y, int add) {
        for (++y; y <= n; y += y&-y)
            fenwick[y].add(x, add);
    }
    int query(int x1, int x2, int y) {
        int ans = 0;
        for (++y; y > 0; y -= y&-y)
            ans += fenwick[y].query(x1, x2);
        return ans;
    }
}

struct Event {
    int x, y, mag, t;
    bool operator<(const Event &a) const {
        return x < a.x;
    }
};
struct Seg {
    int x, y1, y2, t;
    bool operator<(const Seg &a) const {
        if (x == a.x) {
            if (y1 == a.y1) {
                if (y2 == a.y2) return t < a.t;
                return y2 < a.y2;
            }
            return y1 < a. y1;
        }
        return x < a.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("mowing.in");
    ofstream cout("mowing.out");

    int n, t; cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> coords[i].f >> coords[i].s;
    }
    vector<Event> h;
    vector<Seg> v;
    for (int i = 0; i < n - 1; i++) {
        pair<int, int> a = coords[i];
        pair<int, int> b = coords[i + 1];
        if (a.s == b.s) {
            if (b.f < a.f) swap(a, b);
            h.push_back(Event{a.f + 1, a.s, 1, i});
            h.push_back(Event{b.f, b.s, -1, i});
        } else {
            v.push_back(Seg{a.f, min(a.s, b.s) + 1, max(a.s, b.s) - 1, i});
        }
    }
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());

    int hI = 0;
    int ans = 0;
    for (int vI = 0; vI < v.size(); vI++) {
        int x = v[vI].x;
        while (hI < h.size() && h[hI].x <= x) {
            fenwicks::update(h[hI].y, h[hI].t, h[hI].mag);
            hI++;
        }
        while (vI < v.size() && v[vI].x == x) {
            int lo = v[vI].y1, hi = v[vI].y2;
            int t1 = v[vI].t - t, t2 = v[vI].t + t;
            if (t1 >= 0) ans += fenwicks::query(lo, hi, t1);
            if (t2 <= MAX_N) ans += fenwicks::query(lo, hi, MAX_N) - fenwicks::query(lo, hi, t2 - 1);
            vI++;
        }
        vI--;
    }

    cout << ans << endl;
    return 0;
}
