
#include <bits/stdc++.h>

#define MAX_N 16
#define f first
#define s second

using namespace std;

pair<int, int> a[MAX_N + 1];
bool b[MAX_N * 2 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("help.in");
    ofstream cout("help.out");

    int n, k; cin >> n >> k;

    if (n > 16) return 0;

    for (int i = 0; i < n; ++i) {
    	cin >> a[i].f >> a[i].s;
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
    	vector<pair<int, int>> cur;
    	for (int j = 0; j < n; ++j) {
    		if ((i & (1 << j)) > 0) cur.push_back(a[j]);
    	}
    	memset(b, 0, sizeof b);
    	int lo = 2 * n + 1, hi = -1;
    	for (int j = 0; j < cur.size(); ++j) {
    		lo = min(lo, cur[j].f); hi = max(hi, cur[j].s);
    		for (int k = cur[j].f; k < cur[j].s; ++k) {
    			b[k] = true;
    		}
    	}
    	int ct = 1;
    	for (int k = lo; k < hi - 1; ++k) {
    		if (b[k] == 1 && b[k + 1] == 0) ct++;
    	}
    	//cout << i << " " <<  ct << endl;
    	ans += pow(ct, k);
    }
    
    cout << ans << endl;

    return 0;
}