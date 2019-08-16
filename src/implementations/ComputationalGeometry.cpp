
#include <iostream>
#include <cmath>

using namespace std;

namespace compGeo {
    struct Coord {
        int x, y;
        bool operator<(const Coord &a) const {
            if (x == a.x) return y < a.y;
            return x < a.x;
        }
    };
    struct Line {
        int A, B, C; //Ax + By = C
        bool operator<(const Line &a) const {
            if (A == a.A) {
                if (B == a.B) return C < a.C;
                return B < a.B;
            }
            return A < a.A;
        }
    };

    Line calcLine(Coord one, Coord two) {
        int A = two.y - one.y; int B = one.x - two.x;
        int C = A * one.x + B * one.y;
        return Line{A, B, C};
    }
    Coord getReflect(Coord pt, Line sym) {
        Coord n{(double)sym.A, (double)sym.B}; //vector
        double change = (sym.A * pt.x + sym.B * pt.y - sym.C) / (sym.A * sym.A + sym.B * sym.B);
        Coord delta{n.x * change, n.y * change}; //vector
        return Coord{pt.x - 2 * delta.x, pt.y - 2 * delta.y};
    }
    inline double getDist(Coord a, Coord b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
    double getDist(Coord pt, Coord a, Coord b) {
        double ab = getDist(a, b);
        double ap = getDist(a, pt);
        double bp = getDist(b, pt);
        if (ab + bp <= ap || ab + ap <= bp) return sqrt(min(ap, bp));

        long long i = a.y - b.y;
        long long j = b.x - a.x;
        long long k = i * a.x + j * a.y;
        return abs(double(i * pt.x + j * pt.y - k) / sqrt(i * i + j * j));
    }
    int ccw(Coord a, Coord b, Coord c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        //ccw+, cw-
    }
}