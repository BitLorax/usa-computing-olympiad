
#include <bits/stdc++.h>

#define N 100000
#define f first
#define s second

using namespace std;

vector<long long> c[N + 1];
vector<long long> v;
long long loc[N + 1][2];
long long sub[N + 1];
set<long long> tops[N + 1];

struct fenwicks {
    long long n;
    long long fenwick[2 * N + 10];
    void update(long long index, long long add) {
        for (++index; index <= n; index += index&-index)
            fenwick[index] += add;
    }
    void construct(long long arr[], long long size) {
        n = size;
        for (long long i = 0; i < n; i++)
            update(i, arr[i]);
    }
    long long query(long long index) {
        long long ans = 0;
        for (++index; index > 0; index -= index&-index)
            ans += fenwick[index];
        return ans;
    }
};
fenwicks up{};
fenwicks down{};

long long cnt = 0;
void dfs(long long cur, long long par) {
    v.push_back(cur);
    loc[cur][0] = cnt++;
    sub[cur] += 1;
    for (long long i : c[cur]) {
        if (i != par) {
            dfs(i, cur);
            sub[cur] += sub[i];
        }
    }
    v.push_back(cur);
    loc[cur][1] = cnt++;
}

void update(long long at, long long mag) {
    up.update(loc[at][0], mag); up.update(loc[at][1] + 1, -mag);
    down.update(loc[at][0], mag * sub[at]);
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("snowcow.in");
    ofstream cout("snowcow.out");
        
    long long n, q; cin >> n >> q; up.n = down.n = 2 * n + 5;
    for (long long i = 0; i < n - 1; ++i) {
        long long a, b; cin >> a >> b;
        c[a].push_back(b); c[b].push_back(a);
    }
    dfs(1, -1);

    for (long long i = 0; i < q; ++i) {
        long long a; cin >> a; a--;
        if (a) {
            long long b; cin >> b;
            cout << sub[b] * up.query(loc[b][0]) + (down.query(loc[b][1]) - down.query(loc[b][0])) << endl;
        } else {
            long long b, c; cin >> b >> c;
            auto it = tops[c].upper_bound(loc[b][0]);
            if (it != tops[c].begin() && loc[v[*prev(it)]][1] >= loc[b][1]) continue;
            while (it != tops[c].end() && loc[v[*it]][1] <= loc[b][1]) {
                update(v[*it], -1);
                tops[c].erase(it++);
            }
            update(b, 1);
            tops[c].insert(loc[b][0]);
        }
    }

    return 0;
}