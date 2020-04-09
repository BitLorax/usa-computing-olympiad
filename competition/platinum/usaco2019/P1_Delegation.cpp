#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

vector<int> c[MAX_N + 1];

int k = MAX_N - 1;
bool val = true;

bool deleg(vector<int> t) {
    bool curVal = true;
    while (!t.empty() && *t.begin() < k) {
        int l = *t.begin(); t.erase(t.begin());
        auto it = lower_bound(t.begin(), t.end(), k - l);
        if (it == t.end()) {
            curVal = false; break;
        } else {
            t.erase(it);
        }
    }
    return curVal;
}

int dfs(int cur, int par = -1) {
    if (!val) return -1;

    vector<int> lens;
    for (auto i : c[cur]) {
        if (i != par) lens.push_back(dfs(i, cur) + 1);
    }

    sort(lens.begin(), lens.end());

    int p = -1;
    for (int i = lens.size(); i >= 1; i /= 2) {
        while (p + i < lens.size()) {
            vector<int> t = lens;
            t.erase(t.begin() + p + i);
            if (deleg(t)) p += i;
            else break;
        }
    }

    if (p != -1) return lens[p];
    else {
        if (deleg(lens)) return 0;
        val = false;
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("deleg.in");
    ofstream cout("deleg.out");

    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }

    int p = 0;
    for (int i = n; i >= 1; i /= 2) {
        while (p + i < n) {
            val = true; k = p + i; dfs(1);
            if (!val) break;
            p += i;
        }
    }
    cout << p << endl;

    return 0;
}