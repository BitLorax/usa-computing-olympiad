//
// Created by WillJ on 8/25/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_LEN 200000
#define MAX_COWCNT 100000

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

    vector<Suffix> suffixes;
    vector<int> indx;

    void construct(string str) {
        int len = str.length();
        str += "$";
        for (int i = 0; i < len; i++) {
            suffixes[i] = Suffix{i, make_pair(str[i] - 'a', str[i + 1] - 'a')};
        }
        sort(suffixes.begin(), suffixes.end());
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
            sort(suffixes.begin(), suffixes.end());
        }
    }
}

int cowCount, len = 0;
string s;
string names[MAX_COWCNT + 1];
int lcp[MAX_LEN + 1];
int info[MAX_LEN][2]; //word id, suffix length
int score[MAX_COWCNT + 1];

void calcLCP() {
    int curLen = 0;
    for (int i = 0; i < len; i++) {
        curLen = max(curLen - 1, 0);
        int k = sA::suffixes[sA::indx[i] - 1].indx;
        for (; i + curLen < len && k + curLen < len && s[i + curLen] == s[k + curLen]; curLen++);
        lcp[sA::indx[i] - 1] = max(lcp[sA::indx[i] - 1], curLen);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("standingout.in");
    ofstream cout("standingout.out");

    cin >> cowCount;
    for (int i = 0; i < cowCount; i++) {
        string a; cin >> a;
        names[i] = a;
        s += a; s += "#";
        len += a.length() + 1;
        for (int j = 0; j < a.length(); j++) {
            info[s.length() - a.length() - 1 + j][0] = i;
            info[s.length() - a.length() - 1 + j][1] = a.length() - j;
        }
        info[s.length() - 1][0] = info[s.length() - 1][1] = -1;
    }
    sA::suffixes = vector<sA::Suffix>(len);
    sA::indx = vector<int>(len);
    sA::construct(s);
    calcLCP();

    for (int i = 0; i < len; i++) {
        int indx = sA::suffixes[i].indx, curWord = info[indx][0];
        if (curWord == -1) continue;

        //find chunk of suffixes belonging to same word
        int curLen = 1;
        while (i + curLen < len && info[sA::suffixes[i + curLen].indx][0] == curWord) curLen++;

        //comparing j to left suffix that isn't a suffix of curWord (avoid not unique substrings)
        int l = lcp[i - 1];
        for (int j = i; j < i + curLen; j++) {
            //lcp[j] compares j to right suffix (avoid overcount and not unique substrings)
            score[curWord] += max(0, info[sA::suffixes[j].indx][1] - max(l, lcp[j]));
            l = min(l, lcp[j]);
        }
        i--; i += curLen;
    }

    for (int i = 0; i < cowCount; i++) cout << score[i] << endl;
    return 0;
}