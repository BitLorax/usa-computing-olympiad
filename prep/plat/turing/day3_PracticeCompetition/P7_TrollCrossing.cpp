//
// Created by willj on 10/20/2019.
//

#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

typedef unsigned long long ll;

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i<t; i++) {
        ll s, n;
        cin >> s >> n;
        ll ans = 0;
        while (s != 0) {
            ans+=(s%2 == 1)*n;
            s/=2;
            n*=2;
        }
        cout << "Situation #" << i+1 << ": " << ans << "\n";
    }
}
