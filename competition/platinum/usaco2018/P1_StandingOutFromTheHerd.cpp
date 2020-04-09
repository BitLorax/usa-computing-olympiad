
#include <bits/stdc++.h>

#define N 100000
#define f first
#define s second

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
    Suffix s[2 * N + 1];
    int indx[2 * N + 1];
    int loc[2 * N + 1];
    int lcp[2 * N + 1];

    void construct(string in) {
        str = in; len = str.size();
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
    void findLCP() {
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

int res[2 * N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("standingout.in");
    ofstream cout("standingout.out");

    int n; cin >> n;
    string s; vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        string a; cin >> a;
        s += a; s += "?";
        for (int j = 0; j < a.size(); ++j) {
            v.emplace_back(i, a.size() - j);
        }
        v.emplace_back(-1, -1);
    }

    sa::construct(s);
    sa::findLCP();

    int len = s.size();
    for (int i = n; i < len; ++i) {
        int id = v[sa::s[i].indx].f;
        int k = 0;
        while (i + k < len && v[sa::s[i + k].indx].f == id) k++;
        int lo = (i ? sa::lcp[i - 1] : 0);
        for (int j = i; j < i + k; ++j) {
            res[id] += max(0, v[sa::s[j].indx].s - max(lo, sa::lcp[j]));
            lo = min(lo, sa::lcp[j]);
        }
        i += k; i--;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << endl;
    }
    
    return 0;
}