
#include <bits/stdc++.h>

#define MAX_N 10000
#define f first
#define s second

using namespace std;

long long a[MAX_N + 1];
long long from[MAX_N + 1], dist[MAX_N + 1];
vector<pair<long long, long long>> c[MAX_N + 1];
long long sum[MAX_N + 1];

struct State {
	long long at, from, len;
	bool operator<(const State &a) const {
		return len > a.len;
	}
};

long long dfs(long long cur, long long par) {
	sum[cur] = a[cur];
	for (pair<long long, long long> i : c[cur]) {
		if (i.f == par) continue;
		sum[cur] += dfs(i.f, cur);
	}
	return sum[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("shortcut.in");
    ofstream cout("shortcut.out");

    long long n, m, t; cin >> n >> m >> t;
    for (long long i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (long long i = 0; i < m; ++i) {
    	long long a, b, w; cin >> a >> b >> w; a--; b--;
    	c[a].push_back(make_pair(b, w));
    	c[b].push_back(make_pair(a, w));
    }
    for (long long i = 0; i < n; i++) {
    	sort(c[i].begin(), c[i].end());
    }

    for (long long i = 0; i <= n; ++i) {
    	dist[i] = -1;
    }

    priority_queue<State> pq; pq.push(State{0, n, 0});
    while (!pq.empty()) {
    	State cur = pq.top(); pq.pop();

    	if (dist[cur.at] != -1 && dist[cur.at] < cur.len) continue;
    	if (dist[cur.at] == cur.len && cur.from >= from[cur.at]) continue;
    	dist[cur.at] = cur.len; from[cur.at] = cur.from;

    	for (pair<long long, long long> to : c[cur.at]) {
    		pq.push(State{to.f, cur.at, cur.len + to.s});
    	}
    }

    for (long long i = 0; i < n; ++i) {
    	c[i].clear();
    }
    for (long long i = 0; i < n; ++i) {
    	c[i].push_back(make_pair(from[i], -1));
    	c[from[i]].push_back(make_pair(i, -1));
    }

    dfs(0, -1);

    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
    	ans = max(ans, sum[i] * (dist[i] - t));
    }

    cout << ans << endl;
    return 0;
}