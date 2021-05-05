
#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long q; cin >> q;
    for (long long i = 0; i < q; i++) {
        long long n; cin >> n;
        long long nsave = n;
        long long count = 0;
        for (long long k = 2; k <= nsave; k++) {
            while (n % k == 0) {
                count++;
                n /= k;
            }
        }
        cout << "Pop #" << (i + 1) << ": ";
        if (count <= 3) cout << count << " licks? Your goose is cooked!" << endl;
        else cout << "A-one... A-two-HOO... A-" << count <<  "." << endl;
    }
    return 0;
}