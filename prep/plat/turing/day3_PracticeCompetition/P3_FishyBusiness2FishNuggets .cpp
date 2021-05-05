//
// Created by willj on 10/20/2019.
//


#include <iostream>
#include <fstream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for (ll ii = 0; ii<t; ii++) {
        ll ans = 0;
        ll h, w;
        cin >> h >> w;
        for (ll i = 0; i<h; i++) {
            for (ll j = 0; j<w; j++) {
                char c;
                cin >> c;
                if (c == '<' || c == '>' || c == '~') {
                    ans++;
                }
            }
        }
        cout << "Net #" << ii+1 << ": " << ans << " Fish Nuggets" << "\n";
    }
    return 0;
}
