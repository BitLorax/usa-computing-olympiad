
#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int a[MAX_N + 1];
vector<int> stacks[MAX_N + 1];
int at[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("dishes.in");
    ofstream cout("dishes.out");
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int last = 0;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        if (cur < last) {
            cout << i << endl;
            return 0;
        }
        for (int j = cur; j >= 0 && at[j] == 0; j--) {
            at[j] = cur;
        }
        while (!stacks[at[cur]].empty() && stacks[at[cur]].back() < cur) {
            last = stacks[at[cur]].back();
            stacks[at[cur]].pop_back();
        }
        stacks[at[cur]].push_back(cur);
    }

    cout << n << endl;
    return 0;
}