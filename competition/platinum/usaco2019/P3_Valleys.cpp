
#include <bits/stdc++.h>

#define N 1000

using namespace std;

long long curve[N * N + 1];

namespace uf {
    long long n;
    long long component[N * N + 1];
    vector<long long> indices[N * N + 1];

    void construct(long long size) {
        n = size;
        for (long long i = 0; i <= n; i++) {
            component[i] = i;
            indices[i].push_back(i);
        }
    }
    long long find(long long node) {
        return component[node];
    }
    bool join(long long a, long long b) {
        if (find(a) == find(b)) return false;
        if (indices[component[b]].size() > indices[component[a]].size()) swap(a, b);
        curve[component[a]] += curve[component[b]];
        for (long long j : indices[component[b]]) {
            component[j] = component[a];
            indices[component[a]].push_back(j);
        }
        return true;
    }
};

struct Tile {
    long long x, y, val;
    bool operator<(const Tile &a) const {
        return val < a.val;
    }
};

long long n;
long long a[N + 1][N + 1];
vector<Tile> tiles;

long long id(long long x, long long y) {
    return (n + 2) * y + x;
}
long long dc(long long a, long long b, long long c) {
    if (a + b + c == 0) return 1;
    if (a + b + c == 1) return (b ? 1 : -1);
    if (a + b + c == 2) return (b ? -1 : -3);
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("valleys.in");
    ofstream cout("valleys.out");

    cin >> n;
    for (long long i = 0; i < n + 2; ++i) {
        for (long long j = 0; j < n + 2; ++j) {
            a[i][j] = 2000000;
        }
    }
    for (long long i = 1; i < n + 1; ++i) {
        for (long long j = 1; j < n + 1; ++j) {
            cin >> a[j][i];
        }
    }
    for (long long i = 0; i < n + 2; ++i) {
        for (long long j = 0; j < n + 2; ++j) {
            tiles.push_back(Tile{i, j, a[i][j]});
        }
    }
    sort(tiles.begin(), tiles.end());
    uf::construct(tiles.size() + 1);

    long long res = 0;
    for (long long i = 0; i < tiles.size(); ++i) {
        Tile cur = tiles[i]; long long curID = id(cur.x, cur.y);
        if (cur.x == 0 || cur.x == (n + 1) || cur.y == 0 || cur.y == (n + 1)) break;
        
        vector<long long> ids = {id(cur.x - 1, cur.y), id(cur.x + 1, cur.y), id(cur.x, cur.y - 1), id(cur.x, cur.y + 1)};
        if (a[cur.x - 1][cur.y] <= cur.val) uf::join(ids[0], curID);
        if (a[cur.x + 1][cur.y] <= cur.val) uf::join(ids[1], curID);
        if (a[cur.x][cur.y - 1] <= cur.val) uf::join(ids[2], curID);
        if (a[cur.x][cur.y + 1] <= cur.val) uf::join(ids[3], curID);

        long long comp = uf::find(curID);
        curve[comp] += dc(comp == uf::find(ids[0]), comp == uf::find(id(cur.x - 1, cur.y - 1)), comp == uf::find(ids[2]));
        curve[comp] += dc(comp == uf::find(ids[0]), comp == uf::find(id(cur.x - 1, cur.y + 1)), comp == uf::find(ids[3]));
        curve[comp] += dc(comp == uf::find(ids[1]), comp == uf::find(id(cur.x + 1, cur.y + 1)), comp == uf::find(ids[3]));
        curve[comp] += dc(comp == uf::find(ids[1]), comp == uf::find(id(cur.x + 1, cur.y - 1)), comp == uf::find(ids[2]));

        if (curve[comp] > 0) res += uf::indices[comp].size();
    }

    cout << res << endl;

    return 0;
}
