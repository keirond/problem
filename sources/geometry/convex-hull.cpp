#include <bits/stdc++.h>
using namespace std;

struct Vec { // a.k.a. Point
    double x, y;

    void print() { cout << x << ' ' << y << endl; }
    Vec operator+(const Vec &v) const { return {x + v.x, y + v.y}; }
    Vec operator-(const Vec &v) const { return {x - v.x, y - v.y}; }
    Vec operator*(double k) const { return {x * k, y * k}; }
    Vec operator/(double k) const { return {x / k, y / k}; }

    bool operator<(const Vec &v) {
        if (x == v.x) { return y < v.y; }
        return x < v.x;
    }
};

double cross(const Vec &a, const Vec &b) { return a.x * b.y - a.y * b.x; }

int orientation(Vec &a, Vec &b, Vec &c) {
    double cr = cross(b - a, c - b);
    if (abs(cr) < 1e-9) { return 0; }
    return (cr > 0) ? 1 : -1;
}

// Andrew's Monotone Chain
vector<Vec> convexHull(vector<Vec> &ps) {
    int n = ps.size();
    sort(begin(ps), end(ps));

    vector<Vec> ans(2 * n);

    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && orientation(ans[k - 2], ans[k - 1], ps[i]) <= 0) {
            k--;
        }
        ans[k++] = ps[i];
    }

    int t = k + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (k >= t && orientation(ans[k - 2], ans[k - 1], ps[i]) <= 0) {
            k--;
        }
        ans[k++] = ps[i];
    }

    ans.resize(k - 1); // if size is k, p0 is at both start and end.
    return ans;
}
