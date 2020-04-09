
#include <iostream>
#include <vector>

#define f first
#define s second

using namespace std;

namespace cht {
    vector<pair<int, int>> lines;

    inline double intersect(long long m1, long long b1, long long m2, long long b2) {
        return (double)(b2 - b1) / (m1 - m2);
    }
    inline double intersect(pair<int, int> a, pair<int, int> b) {
        return intersect(a.f, a.s, b.f, b.s);
    }
    inline double y(pair<int, int> a, int x) {
        return a.f * x + a.s;
    }
    /**
     * Inserts line to minimum convex hull, usage must be increasing slope only
     * @param m slope of line
     * @param b y-intercept of line
     */
    void insert(int m, int b) {
        pair<int, int> n = make_pair(m, b);
        while (lines.size() >= 2) {
            double w = intersect(lines[lines.size() - 1], n);
            double z = intersect(lines[lines.size() - 2], n);
            if (w > z)
                lines.pop_back();
            else break;
        }
        lines.emplace_back(m, b);
    }
    /**
     * Returns minimum value of y at x, usage must be descending order only
     * @param x position to be searched
     * @return minimum y value at x
     */
    int query(int x) {
        while (lines.size() >= 2 && y(lines[0], x) >= y(lines[1], x))
            lines.erase(lines.begin());
        return y(lines[0], x);
    }
}