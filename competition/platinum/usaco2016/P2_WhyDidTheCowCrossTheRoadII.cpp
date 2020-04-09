//
// Created by willj on 10/21/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_N 100000
#define LOG 20

using namespace std;

int c[MAX_N + 1];
int loc[MAX_N + 1];

namespace segTree {
    int segTree[1 << LOG];
    int n;
    inline int func(int a, int b) {
        return max(a, b);
    }
    void update(int i, int val, int node = 1, int a = 0, int b = -1) {
        if (b == -1) b = n - 1;
        if (a > i || b < i) return;
        if (a == i && b == i) {
            segTree[node] = val;
            return;
        }
        update(i, val, node * 2, a, (a + b) / 2);
        update(i, val, node * 2 + 1, (a + b) / 2 + 1, b);
        segTree[node] = func(segTree[node * 2], segTree[node * 2 + 1]);
    }
    int query(int i, int j, int node = 1, int a = 0, int b = -1) {
        if (b == -1) b = n - 1;
        if (a > b || a > j || b < i) return 0;
        if (a >= i && b <= j) return segTree[node];
        int one = query(i, j, node * 2, a, (a + b) / 2);
        int two = query(i, j, node * 2 + 1, (a + b) / 2 + 1, b);
        return func(one, two);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("nocross.in");
    ofstream cout("nocross.out");

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i]; c[i]--;
    }
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        loc[a - 1] = i;
    }
    segTree::n = n + 1;
    for (int i = 0; i < n; i++) {
        int v = c[i];
        vector<int> indices;
        for (int j = max(0, v - 4); j <= min(n - 1, v + 4); j++) {
            indices.push_back(loc[j]);
        }
        sort(indices.begin(), indices.end());
        for (int j = indices.size() - 1; j >= 0; j--) {
            int k = indices[j];
            int l = segTree::query(0, k) + 1;
            segTree::update(k + 1, l);
        }
    }
    cout << segTree::query(0, n) << endl;
    return 0;
}
