//
// Created by willj on 9/9/2019.
//

#include <iostream>
#include <fstream>

#define INF 2000000000000000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin1("src/competition/c1.in");
    ifstream cin2("src/competition/c2.in");
    ofstream cout("src/competition/cout.out");

    int line = 1;
    while (!cin1.eof() && !cin2.eof()) {
        long long a = -INF, b = -INF;
        cin1 >> a; cin2 >> b;
        if (a != b) cout << line << endl;
        line++;
    }
    cout << line << endl;
    return 0;
}
