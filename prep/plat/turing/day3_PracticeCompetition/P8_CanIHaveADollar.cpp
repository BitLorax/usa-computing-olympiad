//
// Created by willj on 10/20/2019.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    long long n; cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a; cin >> a;
        cout << "Person #" << (i + 1) << ": $" << (a / 2) << endl;
    }
    return 0;
}
