#include <bits/stdc++.h>
using namespace std;

struct Vec {
    double x, y;

    void print() { cout << x << ' ' << y << endl; }
    Vec operator/(double k) const { return {x / k, y / k}; }
};

double dot(Vec &a, Vec &b) { return a.x * b.x + a.y * b.y; }

double cross(Vec &a, Vec &b) { return a.x * b.y - a.y * b.x; }

Vec unit(Vec &a) { return a / sqrt(dot(a, a)); }

Vec perp(Vec &a) { return {-a.y, a.x}; }

double mag(Vec &a) { return sqrt(dot(a, a)); }

Vec rotate(Vec &a, double theta) {
    double cosTh = cos(theta);
    double sinTh = sin(theta);
    return {a.x * cosTh - a.y * sinTh, a.x * sinTh + a.y * cosTh};
}

double angle(Vec &a, Vec &b) { return atan2(cross(a, b), dot(a, b)); }

double angleDegree(double angle) { return 180 * angle / M_PI; }

bool areParallel(Vec &ab, Vec &cd) { return abs(cross(ab, cd)) < 1e-9; }

bool arePerpendicular(Vec &ab, Vec &cd) { return abs(dot(ab, cd)) < 1e-9; }

int main() {
    Vec a(3, 4), b(1, 2);
    a.print();
    cout << dot(a, b) << endl;
    cout << cross(a, b) << endl;
    unit(a).print();
    perp(a).print();
    cout << mag(a) << endl;
    rotate(a, M_PI / 2).print();
    cout << angle(a, b) << endl;
    cout << angleDegree(angle(a, b)) << endl;
}
