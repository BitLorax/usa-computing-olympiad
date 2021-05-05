//
// Created by WillJ on 12/30/2018.
//

#include <iostream>
#include <algorithm>

#define INF 2000000000
#define MAX_LEN 1000

using namespace std;

int brands[MAX_LEN];

int main() {
    string str; cin >> str;
    for (int i = 0; i < str.size(); i++) {
        brands[i] = (str[i] == '(') ? 1 : -1;
    }

    return 0;
}
