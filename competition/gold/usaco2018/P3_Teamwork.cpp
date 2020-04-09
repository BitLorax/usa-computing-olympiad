
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#define INF 2000000000
#define MAX_N 10000

using namespace std;

int c[MAX_N + 1];
int dp[MAX_N + 1];

struct RMQ {
    int n;
    vector<vector<int>> maxs;
    void preprocess(int arr[], int size) {
        n = size;
        maxs = vector<vector<int>>(n + 1, vector<int>((int)(ceil(log2(n)) + 1), 0));

        for (int i = 0; i < n; i++) maxs[i][0] = i;
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j)) <= n; i++) {
                if (arr[maxs[i][j - 1]] > arr[maxs[i + (1 << (j - 1))][j - 1]]) maxs[i][j] = maxs[i][j - 1];
                else maxs[i][j] = maxs[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    int query(int arr[], int lo, int hi) {
        int i = (int)(log2(hi - lo + 1));
        if (arr[maxs[lo][i]] >= arr[maxs[hi - (1 << i) + 1][i]]) return maxs[lo][i];
        return maxs[hi - (1 << i) + 1][i];
    }
};

int main() {

    ifstream cin ("teamwork.in");
    ofstream cout ("teamwork.out");

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    RMQ rmq{}; rmq.preprocess(c, n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j - 1 > n) continue;
            dp[i + j - 1] = max(dp[i + j - 1], dp[i - 1] + j * c[rmq.query(c, i - 1, i + j - 2)]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}
