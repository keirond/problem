#include <bits/stdc++.h>
using namespace std;

void patternMatching(string &s, string &p) {
    string q = p + '&' + s;
    int n = q.size(), m = p.size();
    vector<int> z(n);
    int r = 0, ir = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) { z[i] = min(z[i - ir], r - i); }
        while (i + z[i] < n && q[z[i]] == q[i + z[i]]) { z[i]++; }
        if (i + z[i] > r) {
            ir = i;
            r = i + z[i];
        }
    }
    z[0] = n;

    for (int i = m + 1; i < n; i++) {
        if (z[i] == m) { cout << i - m - 1 << ' '; }
    }
    cout << endl;
}

int main() {
    string s("abcbdbcbcbwab");
    string p("bcb");
    patternMatching(s, p);
    return 0;
}
