//
// Created by WillJ on 7/18/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 2000000000

using namespace std;

struct Coord {
    int x, y;
};

namespace convexHull {
    Coord bot = Coord{INF, INF};
    /**
     * Calculates direction of bc in relation with ab
     * @param a First point
     * @param b Second point
     * @param c Third point
     * @return Positive if counter-clockwise, negative if clockwise, zero if straight
     */
    inline long long ccw(Coord a, Coord b, Coord c) {
        return (long long) (b.x - a.x) * (long long) (c.y - a.y) -
            (long long) (b.y - a.y) * (long long) (c.x - a.x);
    }
    /**
     * Sorts with ccw
     * @param a Node to test
     * @param b Node to test
     * @return Whether a comes before b in relation with bottom point
     */
    bool comp(Coord a, Coord b) {
        return ccw(a, bot, b) > 0;
    }
    /**
     * Performs the Graham Scan to generate a convex hull
     * @param n Number of points
     * @param pts Array of points
     * @return Vector containing Coords of convex hull
     */
    vector<Coord> grahamScan(int n, Coord pts[]) {
        bot = Coord{INF, INF};
        for (int i = 0; i < n; i++) {
            if (pts[i].y < bot.y || (pts[i].y == bot.y && pts[i].x < bot.x)) {
                bot = pts[i];
                pts[i] = pts[0];
                pts[0] = bot;
            }
        }
        sort(pts + 1, pts + n, comp);

        vector<Coord> hull;
        int indx = 0;
        for (int i = 0; i < n; i++) {
            while (indx >= 2 && ccw(hull[indx - 2], hull[indx - 1], pts[i]) <= 0) indx--;
            hull[indx++] = pts[i];
        }
        hull.resize(indx);
        return hull;
    }
}