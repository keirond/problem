#include <bits/stdc++.h>
using namespace std;

struct Vec { // a.k.a. Point
    double x, y;

    void print() { cout << x << ' ' << y << endl; }
    Vec operator+(const Vec &v) const { return {x + v.x, y + v.y}; }
    Vec operator-(const Vec &v) const { return {x - v.x, y - v.y}; }
    Vec operator*(double k) const { return {x * k, y * k}; }
    Vec operator/(double k) const { return {x / k, y / k}; }
};

double cross(const Vec &a, const Vec &b) { return a.x * b.y - a.y * b.x; }

double triangleArea(Vec &a, Vec &b, Vec &c) {
    return 0.5 * abs(cross(b - a, c - a));
}

double polygonArea(vector<Vec> &ps) {
    int n = ps.size();
    if (n < 3) { return 0; }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        Vec &a = ps[i];
        Vec &b = ps[(i + 1) % n];
        ans += cross(a, b);
    }
    return abs(ans) * 0.5;
}

bool isPtInsidePolygon(Vec &p, vector<Vec> &ps) { return true; }

bool isConvexPolygon(vector<Vec> &ps) { return true; }
