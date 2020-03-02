
#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

vector<pair<int, int>> a;
bool b[301][301];

int dist(pair<int, int> u, pair<int, int> v) {
	return (abs(u.f - v.f) + abs(u.s - v.s));
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("test.in");
    ofstream cout("test.out");

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
    	string s; cin >> s;
    	for (int j = 0; j < n; ++j) {
    		if (s[j] == '*') a.emplace_back(j, i);
    		b[j][i] = (s[j] == '*');
    	}
    }

    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
    	for (int j = i + 1; j < a.size(); ++j) {
    		if (a[i].f != a[j].f && a[i].s != a[j].s) continue;
    		if (a[i].f == a[j].f) {
    			if (abs(a[i].s - a[j].s) % 2 == 1) continue;
    			int k = abs(a[i].s - a[j].s) / 2;
    			if (a[i].f + k < n && b[a[i].f + k][min(a[i].s, a[j].s) + k]) ans++;
    			if (a[i].f - k >= 0 && b[a[i].f - k][min(a[i].s, a[j].s) + k]) ans++;
    		} else {
    			if (abs(a[i].f - a[j].f) % 2 == 1) continue;
    			int k = abs(a[i].f - a[j].f) / 2;
    			if (a[i].s + k < n && b[min(a[i].f, a[j].f) + k][a[i].s + k]) ans++;
    			if (a[i].s - k >= 0 && b[min(a[i].f, a[j].f) + k][a[i].s - k]) ans++;
    		}
    	}
    }
    
    cout << ans << endl;

    return 0;
}