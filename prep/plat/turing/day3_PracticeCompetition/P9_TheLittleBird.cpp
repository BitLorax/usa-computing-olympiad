#include <bits/stdc++.h>
using namespace std;

struct PT{
    int x, y;
};
#define MAXN 1000
PT A[MAXN];

int main(){
    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int R, N;
        cin >> R, N;
        for (int j = 0; j < N; j++)
            cin >> A[j].x >> A[j].y;
        A[N] = A[0];
        bool good = true;
        for (int j = 0; j < N; j++) {
            if ((A[j].x * A[j].x + A[j].y * A[j].y) <= R * R) {
                good = false;
                break;
            }
            if ((A[j + 1].x * A[j + 1].x + A[j + 1].y * A[j + 1].y) <= R * R) {
                good = false;
                break;
            }
            int AA = A[j + 1].y - A[j].y;
            int BB = A[j + 1].x - A[j].x;
            if ((AA * A[j].x - BB * A[j].y) * (AA * A[j].x - BB * A[j].y) <= (AA * AA + BB * BB) * R * R) {
                good = false;
                break;
            }
        }
        cout << "Yard #" << i <<": ";
        if (good) {
            cout << "Fly away!" << endl;
        } else {
            cout << "Better not risk it." << endl;
        }
    }
}