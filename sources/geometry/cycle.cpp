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

vector<Vec> lineXcycle(Vec &a, Vec &b, Vec &c, double r) { return {}; }

vector<Vec> segXcycle(Vec &a, Vec &b, Vec &c, double r) { return {}; }

vector<Vec> cycleXcycle(Vec &c1, double r1, Vec &c2, double r2) { return {}; }

vector<Vec> targentsPtToCircle(Vec &p, Vec &c, double r) { return {}; }

vector<Vec> targents2Cycles(Vec &c1, double r1, Vec &c2, double r2) {
    return {};
}

pair<Vec, double> circumcircleTriangle(Vec &a, Vec &b, Vec &c) { return {}; }

pair<Vec, double> incircleTriangle(Vec &a, Vec &b, Vec &c) { return {}; }
