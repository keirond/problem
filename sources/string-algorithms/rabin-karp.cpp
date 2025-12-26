#include <bits/stdc++.h>
using namespace std;

void patternMatching(string &s, string &p) {
    int n = s.size(), m = p.size();
    int mod1 = 1e9 + 7;

    int hash1 = 0;
    for (int i = 1; i <= m; i++) {
        hash1 = (1LL * hash1 * 26 % mod1 + (p[i - 1] - 'a' + 1)) % mod1;
    }

    vector<int> base1(n + 1, 1);
    vector<int> sHashes1(n + 1);
    for (int i = 1; i <= n; i++) {
        base1[i] = 1LL * base1[i - 1] * 26 % mod1;
        sHashes1[i] =
                (1LL * sHashes1[i - 1] * 26 % mod1 + (s[i - 1] - 'a' + 1)) %
                mod1;
    }

    for (int i = 0; i + m <= n; i++) {
        int temp1 =
                (sHashes1[i + m] - 1LL * sHashes1[i] * base1[m] % mod1) % mod1;
        if (temp1 < 0) { temp1 = (temp1 + mod1) % mod1; }
        if (temp1 == hash1) { cout << i << ' '; }
    }
    cout << endl;
}

int main() {
    string s("abcbdbcbcbwab");
    string p("bcb");
    patternMatching(s, p);
    return 0;
}
