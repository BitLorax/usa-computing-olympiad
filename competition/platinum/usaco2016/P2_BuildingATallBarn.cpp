//
// Created by willj on 10/5/2019.
//

#include <iostream>
#include <fstream>
#include <cmath>

#define MAX_N 100000

using namespace std;

long long n, k;
long long req[MAX_N + 1];

long long count(double rem) {
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        tot += (long long)(-1 + sqrt(1 + 4 * req[i] / rem)) / 2;
    }
    return tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("tallbarn.in");
    ofstream cout("tallbarn.out");

    cin >> n >> k; k -= n;
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }
    double lo = 0, hi = 1e18;
    while (hi - lo > 1e-15) {
        double mid = (lo + hi) / 2;
        if (count(mid) >= k) lo = mid;
        else hi = mid;
    }

    double ans = 0;
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        long long count = (-1 + sqrt(1 + 4 * req[i] / lo)) / 2;
        tot += count;
        ans += 1.0 * req[i] / (count + 1);
    }

    cout << (long long)round(ans + (tot - k) * lo) << endl;
    return 0;
}
