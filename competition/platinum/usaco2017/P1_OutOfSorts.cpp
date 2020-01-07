
#include <bits/stdc++.h>

#define N 100000
#define f first
#define s second

using namespace std;

pair<int, int> a[N + 1];
int hi[N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("sort.in");
    ofstream cout("sort.out");

    int n; cin >> n;
    if (n == 1) {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].f; a[i].s = i;
    }
    sort(a, a + n);

    int curHi = 0;
    for (int i = 0; i < n; ++i) {
        curHi = max(curHi, a[i].s);
        hi[i] = curHi - i;
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        if (i > 0) k = max(k, hi[i - 1]);
        if (i < n - 1) k = max(k, hi[i]);
        res += k;
    }

    cout << res << endl;

    return 0;
}