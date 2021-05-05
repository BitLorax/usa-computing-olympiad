//
// Created by willj on 10/20/2019.
//


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for (ll i = 0; i<t; i++) {
        ll arr[510], arr2[510], aux[510];
        ll N, K;
        cin >> N >> K;
        for (ll j = 0; j<N; j++) {
            cin >> arr[j];
            arr2[j] = arr[j];
        }
        sort(arr2, arr2+N);
        vector<ll> r[60];
        vector<ll> r2[60];
        bool yes = true;
        bool flag = true;
        for (ll j = 0; j<K; j++) {
            for (ll k = j; k<N; k+=K) {
                r[j].push_back(arr[k]);
                r2[j].push_back(arr2[k]);
            }
            sort(r[j].begin(), r[j].end());
            sort(r2[j].begin(), r2[j].end());
            if (!flag) {
                break;
            }
            for (ll k = 0; k<r[j].size(); k++) {
                if (!flag) {
                    break;
                }
                if (r[j][k] != r2[j][k]) {
                    cout << "Lobster #" << i << ": " << "Unsortable\n";
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "Lobster #" << i << ": " << "Sortable\n";
        }
    }
    return 0;
}
