
#include <bits/stdc++.h>

#define N 1500
#define Y 2500
#define MOD 1000000007
#define f first
#define s second

using namespace std;

vector<pair<long long, long long>> c[N + 1];
bool v[N + 1];
vector<long long> curComp;
vector<long long> curLens;
pair<long long, long long> res[Y + 1];
pair<long long, long long> temp[Y + 1];

void getComp(long long cur, long long par = -1) {
    curComp.push_back(cur);
    v[cur] = true;
    for (pair<long long, long long> i : c[cur]) {
        if (i.f != par) getComp(i.f, cur);
    }
}
void getLens(long long start, long long cur, long long par = -1, long long dist = 0) {
    if (start < cur) curLens.push_back(dist);
    for (auto i : c[cur]) {
        if (i.f == par) continue;
        getLens(start, i.f, cur, dist + i.s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("mooriokart.in");
    ofstream cout("mooriokart.out");

    long long n, m, x, y; cin >> n >> m >> x >> y;
    for (long long i = 0; i < m; ++i) {
        long long a, b, v; cin >> a >> b >> v; a--; b--;
        c[a].emplace_back(b, v);
        c[b].emplace_back(a, v);
    }
    res[min(x * (n - m), y)] = make_pair(1, x * (n - m));
    for (long long i = 0; i < n; ++i) {
        if (v[i]) continue;
        curComp.clear(); getComp(i);
        curLens.clear();
        for (auto j : curComp) {
            getLens(j, j);
        }
        map<long long, pair<long long, long long>> mp;
        for (auto j : curLens) {
            mp[min(j, y)].f += 1;
            mp[min(j, y)].s += j;
        }
        memset(temp, 0, sizeof(temp));
        for (auto j : mp) {
            for (long long k = 0; k <= y; ++k) {
                temp[min(k + j.f, y)].f += (res[k].f * j.s.f) % MOD; temp[min(k + j.f, y)].f %= MOD;
                temp[min(k + j.f, y)].s += ((res[k].f * j.s.s) % MOD + (res[k].s * j.s.f) % MOD) % MOD; temp[min(k + j.f, y)].s %= MOD;
            }
        }
        swap(res, temp);
    }

    for (long long i = 0; i < (n - m) - 1; ++i) {
        res[y].s *= 2; res[y].s %= MOD;
    }
    for (long long i = 1; i < (n - m); ++i) {
        res[y].s *= i; res[y].s %= MOD;
    }

    cout << res[y].s << endl;

    return 0;
}
