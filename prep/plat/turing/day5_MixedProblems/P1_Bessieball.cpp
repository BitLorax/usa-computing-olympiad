//
// Created by willj on 11/24/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_N 50
#define f first
#define s second

using namespace std;

int n, m;
pair<int, int> a[MAX_N * MAX_N / 2];

int run(multiset<int> ms, int k) {
    if (k >= m) {
        for (auto i : ms) cout << i << " ";
        cout << endl;
        return 1;
    }
    int ret = 0;
    bool u = binary_search(ms.begin(), ms.end(), a[k].f), v = binary_search(ms.begin(), ms.end(), a[k].s);
    if (!u && !v) {
        run(ms, k + 1);
    } else if (u && !v) {
        ret += run(ms, k + 1);
        ms.erase(a[k].f);
        ret += run(ms, k + 1);
        ms.insert(a[k].f);
    } else if (v && !u) {
        ret += run(ms, k + 1);
        ms.erase(ms.find(a[k].s));
        ret += run(ms, k + 1);
        ms.insert(a[k].s);
    } else {
        ms.erase(ms.find(a[k].f));
        ret += run(ms, k + 1);
        ms.insert(a[k].f);
        ms.erase(ms.find(a[k].s));
        ret += run(ms, k + 1);
        ms.insert(a[k].s);
    }
    return ret;
}

int main() {
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < m; i++) {
        cin >> a[i].f >> a[i].s;
        ms.insert(i + 1);
    }
    cout << run(ms, 0) << endl;
    return 0;
}
