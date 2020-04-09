//
// Created by WillJ on 7/4/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define N 1000
#define INF 2000000000

using namespace std;

namespace sa {
    struct Suffix {
        int indx; //starting indx
        pair<int, int> rank;
        bool operator<(const Suffix &a) const {
            if (rank.first == a.rank.first) return rank.second < a.rank.second;
            return rank.first < a.rank.first;
        }
    };

    string str; int len;
    Suffix s[N + 1];
    int indx[N + 1];
    int loc[N + 1];
    int lcp[N + 1];

    void construct(string in) {
        str = in; len = str.length();
        str += "$";
        for (int i = 0; i < len; i++) {
            s[i] = Suffix{i, make_pair(str[i] - 'a', str[i + 1] - 'a')};
        }
        sort(s, s + len);
        for (int k = 2; k < len; k *= 2) {
            int rank = 0;
            Suffix pre = s[0];
            for (int i = 0; i < len; i++) {
                if (s[i].rank == pre.rank) {
                    pre = s[i];
                    s[i].rank.first = rank;
                } else {
                    pre = s[i];
                    s[i].rank.first = ++rank;
                }
                indx[s[i].indx] = i;
            }
            for (int i = 0; i < len; i++) {
                s[i].rank.second = ((s[i].indx + k / 2 < len) ?
                                           s[indx[s[i].indx + k / 2]].rank.first : -1);
            }
            sort(s, s + len);
        }
    }
    void findLCP(string str) {
        for (int i = 0; i < len; ++i) {
            loc[s[i].indx] = i;
        }
        int k = 0;
        for (int i = 0; i < len; ++i) {
            k = max(0, k - 1);
            int indx = loc[i];
            if (indx == 0) continue;
            int j = s[indx - 1].indx;
            while (i + k < len && j + k < len && str[i + k] == str[j + k]) k++;
            lcp[indx - 1] = k;
        }
    }
}

int main() {
    return 0;
}
