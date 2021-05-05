//
// Created by willj on 10/20/2019.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long n; cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;
        long long res;
        if (b >= 350000) res = 0;
        else {
            if (a <= 17) res = 4;
            else res = 5;
        }
        cout << "Breakfast #" << (i + 1) << ": " << res << endl;
    }
    return 0;
}
