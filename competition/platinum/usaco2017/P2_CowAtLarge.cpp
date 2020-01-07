
#include <bits/stdc++.h>

#define N 70225
#define B 265
#define BS 265
#define f first
#define s second

using namespace std;

int fenwick[B + 1][2 * N + 1];
namespace fenwicks {
    void update(int index, int block, int add) {
        for (++index; index <= 2 * N; index += index&-index)
            fenwick[block][index] += add;
    }
    int query(int index, int block) {
        int ret = 0;
        for (++index; index > 0; index -= index&-index)
            ret += fenwick[block][index];
        return ret;
    }
}

vector<int> c[N + 1];
int depth[N + 1], toLeaf[N + 1];
pair<int, int> loc[N + 1];
int val[N + 1];
int indx[N + 1];
long long res[N + 1];
int lazy[B + 1];

void getDepth(int cur, int par = -1, int d = 0) {
    depth[cur] = d; toLeaf[cur] = (c[cur].size() == 1 ? 0 : N + 1);
    for (auto i : c[cur]) {
        if (i != par) {
            getDepth(i, cur, d + 1);
            toLeaf[cur] = min(toLeaf[cur], toLeaf[i] + 1);
        }
    }
}
int t = 0;
void getLoc(int cur, int par = -1) {
    loc[cur].f = t++;
    if (par != -1) toLeaf[cur] = min(toLeaf[cur], toLeaf[par] + 1);
    for (auto i : c[cur]) {
        if (i != par) getLoc(i, cur);
    }
    loc[cur].s = t - 1;
}

int globalLazy;

void unbuild(int b, int lo, int hi) {
    for (int i = lo; i <= hi; ++i) {
        fenwicks::update(indx[i], b, -val[i]);
    }
}
void build(int b, int lo, int hi) {
    for (int i = lo; i <= hi; ++i) {
        fenwicks::update(indx[i], b, val[i]);
    }
}

void update(int lo, int hi, int d) {
    int blo = lo / BS;
    int bhi = hi / BS;
    if (blo == bhi) {
        unbuild(blo, lo, hi);
        for (int i = lo; i <= hi; ++i) {
            indx[i] += d;
        }
        build(blo, lo, hi);
    } else {
        unbuild(blo, lo, BS * (blo + 1) - 1);
        unbuild(bhi, BS * bhi, hi);
        for (int i = lo; i < BS * (blo + 1); ++i) {
            indx[i] += d;
        }
        for (int i = hi; i >= bhi * BS; --i) {
            indx[i] += d;
        }
        build(blo, lo, BS * (blo + 1) - 1);
        build(bhi, BS * bhi, hi);
        for (int i = blo + 1; i < bhi; ++i) {
            lazy[i] += d;
        }
    }
}

long long query() {
    int ret = 0;
    for (int i = 0; i < B; ++i) {
        ret += fenwicks::query(N - lazy[i] - globalLazy, i);
    }
    return ret;
}
int n;

void dfs(int cur, int par = -1) {
    res[cur] = query();
    for (auto i : c[cur]) {
        if (i == par) continue;
        update(loc[i].f, loc[i].s, 2);
        globalLazy--;
        dfs(i, cur);
        globalLazy++;
        update(loc[i].f, loc[i].s, -2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("atlarge.in");
    ofstream cout("atlarge.out");

    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    getDepth(0);
    getLoc(0);

    for (int i = 0; i < n; ++i) {
        indx[loc[i].f] = toLeaf[i] - depth[i] + N;
        val[loc[i].f] = 2 - (int)c[i].size();
    }

    for (int i = 0; i < B; ++i) {
        build(i, BS * i, BS * (i + 1) - 1);
    }

    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        if (c[i].size() == 1) res[i] = 1;
        cout << res[i] << endl;
    }
    
    return 0;
}
