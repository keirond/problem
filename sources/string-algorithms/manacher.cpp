#include <bits/stdc++.h>
using namespace std;

void longestPalindromeSubstring(string &s) {
    string q("|");
    for (char c : s) {
        q.push_back(c);
        q.push_back('|');
    }
    int n = q.size();
    vector<int> ms(n);
    int c = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (i <= c + r) { ms[i] = min(ms[2 * c - i], c + r - i); }
        while (i - ms[i] >= 0 && i + ms[i] < n &&
               q[i - ms[i]] == q[i + ms[i]]) {
            ms[i]++;
        }
        ms[i]--;
        if (i + ms[i] > c + r) {
            c = i;
            r = ms[i];
        }
    }

    c = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            if (ms[i] > r) { c = i, r = ms[i]; }
        } else {
            if (ms[i] + 1 > r) { c = i, r = ms[i] + 1; }
        }
    }
    for (int i = c - ms[c]; i <= c + ms[c]; i++) {
        if (q[i] != '|') { cout << q[i]; }
    }
    cout << endl;
}

int main() {
    string s("abcbdkjcjkdbcd");
    longestPalindromeSubstring(s);
}
