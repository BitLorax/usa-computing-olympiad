//
// Created by wilong longj on 10/20/2019.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long i = 0; i<t; i++) {
        long long minim = 1e12;
        long long N;
        cin >> N;
        string s;
        for (long long j = 0; j<N; j++) {
            long long a;
            cin >> s;
            cin >> a;
            if (j != N-1) {
                minim = min(minim, a);
            }
        }
        cout << "Assembly #" << i+1 << ": "   <<  minim << "\n";
    }
    return 0;
}
