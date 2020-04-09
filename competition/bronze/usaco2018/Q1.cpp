//
// Created by WillJ on 12/14/2018.
//

#include <iostream>

using namespace std;

struct Bucket {
    int capacity, amount;
};

Bucket buckets[3];

int main() {

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    for (int i = 0; i < 3; i++) {
        cin >> buckets[i].capacity >> buckets[i].amount;
    }
    int from = 0; int to = 1;
    for (int i = 0; i < 100; i++) {
        if (buckets[to].capacity >= buckets[from].amount + buckets[to].amount) { //full pour
            buckets[to].amount += buckets[from].amount;
            buckets[from].amount = 0;
        } else { //pour to max
            buckets[from].amount -= (buckets[to].capacity - buckets[to].amount);
            buckets[to].amount = buckets[to].capacity;
        }
        from = (from + 1) % 3;
        to = (to + 1) % 3;
    }
    for (int i = 0; i < 3; i++) {
        cout << buckets[i].amount << endl;
    }
    return 0;
}
