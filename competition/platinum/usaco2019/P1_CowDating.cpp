
#include <bits/stdc++.h>

#define N 1000000

using namespace std;

long double p[N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("cowdate.in");
    ofstream cout("cowdate.out");
    cout.precision(20);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] *= .000001;
    }

    long double prod = 1, sum = 0;
    int res = 0, hi = 0;
    for (int lo = 0; lo < n; ++lo) {
        while (hi < n && sum < 1) {
            prod *= (1 - p[hi]);
            sum += p[hi] / (1 - p[hi]);
            hi++;
        }
        res = max(res, (int)floor(1e6 * prod * sum + 5.0 * 1e-8));
        prod /= (1 - p[lo]);
        sum -= p[lo] / (1 - p[lo]);
    }

    cout << res << endl;

    return 0;
}