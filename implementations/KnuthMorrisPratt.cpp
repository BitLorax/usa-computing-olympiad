//
// Created by WillJ on 7/4/2019.
//

#include <iostream>
#include <fstream>
#include <vector>

#define INF 2000000000
#define N 1000

using namespace std;

namespace kmp {
    string str, pat;
    int fail[N + 1];

    /**
     * Constructs the failure array
     * @param s String to be searched
     * @param p Pattern
     */
    void construct(string s, string p) {
        str = s; pat = p;

        fail[0] = -1;
        for (int i = 1; i <= pat.length(); i++) {
            fail[i] = fail[i - 1];
            while (fail[i] > -1 && pat[i - 1] != pat[fail[i]]) fail[i] = fail[fail[i]];
            fail[i]++;
        }
    }
    /**
     * Searches string for pattern
     * @return Vector of all starting positions of found patterns
     */
    vector<int> query() {
        vector<int> ret;
            int pStr = 0, pPat = 0;
            while (pStr < str.length()) {
                if (str[pStr] == pat[pPat]) {
                    pStr++; pPat++;
                    if (pPat == pat.length()) {
                        ret.push_back(pStr - pPat);
                        pPat = fail[pPat];
                    }
                } else {
                    pPat = fail[pPat];
                    if (pPat < 0)
                        pStr++; pPat++;
                }
            }
        return ret;
    }
}