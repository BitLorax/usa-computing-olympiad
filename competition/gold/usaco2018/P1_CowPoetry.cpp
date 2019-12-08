//
// Created by WillJ on 3/12/2019.
//

#include <bits/stdc++.h>

#define INF 2000000000
#define MAX_WORDCNT 5000
#define MAX_LEN 5000
#define MOD 1000000007

using namespace std;

struct Word {
    int len, rhyme;
};

Word words[MAX_WORDCNT];
map<char, int> freq;

long long DP[MAX_LEN + 1];
long long possibilities[MAX_WORDCNT + 1];

long long exp(long long base, long long power) {
    if (power == 0) return 1;
    if (power == 1) return (base + MOD) % MOD;

    long long ret = exp(base,power/2);
    ret = (ret * ret + MOD) % MOD;
    if(power%2 == 1) ret = (ret * base + MOD) % MOD;
    return (ret + MOD) % MOD;
}

int main() {

    ifstream cin ("poetry.in");
    ofstream cout ("poetry.out");

    int wordCount, lineReq, lenReq; cin >> wordCount >> lineReq >> lenReq;
    for (int i = 0; i < wordCount; i++) {
        cin >> words[i].len >> words[i].rhyme;
    }
    for (int i = 0; i < lineReq; i++) {
        char a; cin >> a;
        freq[a]++;
    }
    DP[0] = 1;
    for (int i = 0; i <= lenReq; i++) {
        for (int j = 0; j < wordCount; j++) {
            Word cur = words[j];
            if (i - cur.len < 0) continue;
            DP[i] = (DP[i] + DP[i - cur.len]) % MOD;
            if (i == lenReq) possibilities[cur.rhyme] = (possibilities[cur.rhyme] + DP[i - cur.len]) % MOD;
        }
    }
    long long sum = 1;
    for (auto it : freq) {
        long long curSum = 0;
        for (int i = 0; i <= wordCount; i++) {
            long long k = exp(possibilities[i], it.second);
            curSum = (curSum + k) % MOD;
        }
        sum = (sum * curSum) % MOD;
    }
    cout << sum << endl;
    return 0;
}
