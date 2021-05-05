//
// Created by willj on 10/6/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_N 200000
#define f first
#define s second

using namespace std;

long long h[MAX_N + 1];
pair<long long, long long> sorted[MAX_N + 1];
vector<long long> stops;

long long p(long long a, long long i, long long b) {
    return (i - a) * (b - i);
}

int main() {
    long long n; cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> h[i];
        sorted[i].f = h[i]; sorted[i].s = i;
    }
    sort(sorted, sorted + n);
    stops.push_back(-1); stops.push_back(n);
    long long tot = 0;
    for (long long i = 0; i < n; i++) {
        pair<long long, long long> cur = sorted[i];
        auto b = upper_bound(stops.begin(), stops.end(), cur.s);
        auto a = b; a--;
        tot += p(*a, cur.s, *b) * cur.f;
        stops.insert(b, cur.s);
    }

    cout << tot << endl;
    return 0;
}
