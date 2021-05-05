//
// Created by willj on 10/20/2019.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t, a, b;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a >> b;
        cout << "Fraction #" << i << ": ";
        if(a+b < 0)
            cout << "DNE" << endl;
        else {
            cout << std::fixed << setprecision(2) << sqrt(a+b) << endl;
        }
    }
}
