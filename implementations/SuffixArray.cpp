//
// Created by WillJ on 7/4/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 2000000000
#define N 1000

using namespace std;

namespace sA {
    struct Suffix {
        int indx; //starting indx
        pair<int, int> rank;
        bool operator<(const Suffix &a) const {
            if (rank.first == a.rank.first) return rank.second < a.rank.second;
            return rank.first < a.rank.first;
        }
    };

    Suffix suffixes[MAX_LEN + 1];
    int indx[MAX_LEN + 1];

    void construct(string str) {
        int len = str.length();
        str += "$";
        for (int i = 0; i < len; i++) {
            suffixes[i] = Suffix{i, make_pair(str[i] - 'a', str[i + 1] - 'a')};
        }
        sort(suffixes, suffixes + len);
        for (int k = 2; k < len; k *= 2) {
            int rank = 0;
            Suffix pre = suffixes[0];
            for (int i = 0; i < len; i++) {
                if (suffixes[i].rank == pre.rank) {
                    pre = suffixes[i];
                    suffixes[i].rank.first = rank;
                } else {
                    pre = suffixes[i];
                    suffixes[i].rank.first = ++rank;
                }
                indx[suffixes[i].indx] = i;
            }
            for (int i = 0; i < len; i++) {
                suffixes[i].rank.second = ((suffixes[i].indx + k / 2 < len) ?
                                           suffixes[indx[suffixes[i].indx + k / 2]].rank.first : -1);
            }
            sort(suffixes, suffixes + len);
        }
    }
}

int main() {
    return 0;
}
