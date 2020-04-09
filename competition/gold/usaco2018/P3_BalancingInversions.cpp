
#include <bits/stdc++.h>

#define N 100000
#define INF 2000000000
#define f first
#define s second

using namespace std;

int a[2 * N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("test.in");
    ofstream cout("test.out");
    
    int n; cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
    	cin >> a[i];
    }

    pair<int, int> inv = make_pair(0, 0); //inv1 - inv2
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	if (a[i]) cnt++;
    	else inv.f += cnt;
    }

    cnt = 0;
    for (int i = n; i < 2 * n; ++i) {
    	if (a[i]) cnt++;
    	else inv.s -= cnt;
    }

    int res = INF;

    int lo = n, hi = n - 1; //lo gets 0, hi gets 1
    while (lo >= 0 && hi < 2 * n) {
    	lo--; hi++;
    	while (lo >= 0 && a[lo] != 0) lo--;
    	while (hi < 2 * n && a[hi] != 1) hi++;

    	

    }

    return 0;
}