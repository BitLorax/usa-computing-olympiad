
#include <bits/stdc++.h>

#define N 300000
#define f first
#define s second

using namespace std;

bool a[N + 1];
int pSum[N + 1];
int dp[N + 1];

priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> dpq[N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("redistricting.in");
    ofstream cout("redistricting.out");

    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) {
        a[i] = (s[i] == 'H');
    }
    for (int i = 0; i < n; ++i) {
        pSum[i + 1] = pSum[i] + (a[i] ? 1 : -1);
    }

    pq.push(make_pair(0, 0));
    dpq[0].push(make_pair(0, 0));
    for (int i = 1; i <= n; ++i) {
        while (!pq.empty() && pq.top().s < i - k) {
            pq.pop();
        }
        int val = pq.top().f;
        while (!dpq[val].empty() && dpq[val].top().s < i - k) dpq[val].pop();
        if (dpq[val].top().f < pSum[i]) dp[i] = val;
        else dp[i] = val + 1;
        pq.push(make_pair(dp[i], i));
        dpq[dp[i]].push(make_pair(pSum[i], i));
    }

    cout << dp[n] << endl;

    return 0;
}