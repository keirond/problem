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

double dot(const Vec &a, const Vec &b) { return a.x * b.x + a.y * b.y; }

double cross(const Vec &a, const Vec &b) { return a.x * b.y - a.y * b.x; }

double segLen(Vec &a, Vec &b) {
    Vec ab = b - a;
    return sqrt(dot(ab, ab));
}

double orientation(Vec &a, Vec &b, Vec &c) {
    double cr = cross(b - a, c - b);
    if (abs(cr) < 1e-9) { return 0; }
    return (cr > 0) ? 1 : -1;
}

bool isPtInLine(Vec &a, Vec &b, Vec &p) {
    double cr = cross(b - a, p - b);
    return abs(cr) < 1e-9;
}

bool isPtInSeg(Vec &a, Vec &b, Vec &p) {
    double cr = cross(b - a, p - b);
    if (abs(cr) < 1e-9) {
        double dt = dot(b - a, p - a);
        if (dt > 0 && dt - dot(b - a, b - a) < 1e-9) { return true; }
    }
    return false;
}

Vec projPtOntoLine(Vec &a, Vec &b, Vec &p) {
    double d1 = dot(b - a, p - a);
    double d2 = dot(b - a, b - a);
    return a + (b - a) * d1 / d2;
}

Vec reflptOverLine(Vec &a, Vec &b, Vec &p) {
    double d1 = dot(b - a, p - a);
    double d2 = dot(b - a, b - a);
    Vec h = a + (b - a) * d1 / d2;
    return h * 2 - p;
}

double distPtToLine(Vec &a, Vec &b, Vec &p) {
    double c = cross(b - a, p - a);
    double d = dot(b - a, b - a);
    return abs(c) / sqrt(d);
}

double distPtToSegment(Vec &a, Vec &b, Vec &p) {
    double d1 = dot(b - a, p - a);
    double d2 = dot(b - a, b - a);
    double d = d1 / d2;
    if (d < 1e-9) { return sqrt(dot(p - a, p - a)); }
    if (d - 1 < 1e-9) { return sqrt(dot(p - b, p - b)); }
    Vec h = a + (b - a) * d;
    return sqrt(dot(p - h, p - h));
}

optional<Vec> lineXline(Vec &a, Vec &b, Vec &c, Vec &d) {
    Vec ab = b - a;
    Vec cd = d - c;
    Vec ca = a - c;
    if (abs(cross(cd, ab)) < 1e-9) {
        if (abs(cross(ca, ab)) < 1e-9) {
            // overlapped
            return nullopt;
        }
        return nullopt;
    }
    double t = cross(ca, ab) / cross(cd, ab);
    return c + cd * t;
}

bool isSegXseg(Vec &a, Vec &b, Vec &c, Vec &d) {
    // TBD
    return true;
}
