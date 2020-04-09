
#include <bits/stdc++.h>

#define MAX_VAL 1000000
#define f first
#define s second

using namespace std;

struct V {
    long long n = 0;
    long long a[5] = {0, 0, 0, 0, 0};
    bool operator<(const V &u) const {
        for (long long i = 0; i < 5; i++) {
            if (u.a[i] < a[i]) return false;
            if (a[i] < u.a[i]) return true;
        }
        return false;
    }
};

map<V, long long> s;
long long m[] = {0, 1, -1, 1, -1, 1};

V sub(V v, long long x) {
    V ret;
    for (long long i = 0; i < 5; i++) {
        if (x & (1 << i)) ret.a[ret.n++] = v.a[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("cowpatibility.in");
    ofstream cout("cowpatibility.out");

    long long n; cin >> n;
    for (long long i = 0; i < n; i++) {
        V v;
        for (long long j = 0; j < 5; j++) {
            long long u; cin >> u;
            v.a[v.n++] = u;
        }
        sort(v.a, v.a + 5);
        for (long long j = 1; j <= (1 << 5); j++) {
            s[sub(v, j)]++;
        }
    }
    long long res = 0;
    for (auto a : s) {
        res += m[a.f.n] * a.s * (a.s - 1) / 2;
    }

    cout << n * (n - 1) / 2 - res << endl;
    return 0;
}