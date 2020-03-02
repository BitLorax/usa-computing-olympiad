
#include <bits/stdc++.h>

#define N 1000000000000
#define MOD 1000000007

using namespace std;

long long n, nn;
vector<long long> p, e;
long long ans = 0;

long long fastExpo(long long base, long long pow) {
    long long ret = 1, b = base;
    while (pow > 0) {
        if (pow % 2 == 1) ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        pow /= 2;
    }
    return ret % MOD;
}
void calc(long long cur, long long i, long long j, long long k) {
    if (cur == (long long)p.size()) {
        if (i < n) ans = (ans + fastExpo(2, i) * (n / (i * j)) * k) % MOD;
        return;
    }
    for (long long l = 0; l < e[cur]; ++l) {
        calc(cur + 1, i, j * p[cur], k * (p[cur] - 1));
        i *= p[cur];
    }
    calc(cur + 1, i, j, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("gymnasts.in");
    ofstream cout("gymnasts.out");

    cin >> n; nn = n;
    for (long long i = 2; i <= (long long)ceil(sqrt(n)); ++i) {
        long long k = 0;
        while (nn % i == 0) {
            k++; nn /= i;
        }
        if (k > 0) {
            p.push_back(i);
            e.push_back(k);
        }
    }
    if (nn > 1) {
        p.push_back(nn);
        e.push_back(1);
    }
    calc(0, 1, 1, 1);
    ans = (ans - (n - 1) % MOD + 1 + MOD) % MOD;
    
    cout << ans << endl;
    return 0;
}