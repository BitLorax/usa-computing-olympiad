#include <bits/stdc++.h>

using namespace std;

bool bird[110];
bool mv[110];

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        bird[a] = 1;
    }
    for (int i = 0; i <= 100; i++) {
        if (bird[i]) {
            cout << "FAILURE" << endl;
            return 0;
        }
        int ii = i;
        for (int j = 1; j <= k; j++) {
            if (bird[ii + j]) {
                mv[ii + j] = 1;
                ii = ii + j;
                j = 1;
            }
        }
        for (int j = 1; j <= 100; j++) {
            if (mv[j]) {
                bird[j] = mv[j] = 0;
                bird[j - 1] = mv[j - 1] = 1;
            }
        }
    }
    cout << "SUCCESS" << endl;
    return 0;
}
