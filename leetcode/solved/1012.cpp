#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string s;
    bool vs[10][2][2][1 << 10][2];
    int f[10][2][2][1 << 10][2];

    int dfs(int pos, bool tight, bool leadingZero, int digits, bool repeated) {
        if (pos == s.size()) { return repeated; }
        if (vs[pos][tight][leadingZero][digits][repeated]) {
            return f[pos][tight][leadingZero][digits][repeated];
        }

        vs[pos][tight][leadingZero][digits][repeated] = true;
        int &ans = f[pos][tight][leadingZero][digits][repeated];
        ans = 0;

        int limit = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= limit; i++) {
            if (leadingZero && i == 0) {
                ans += dfs(pos + 1, tight && i == limit, true, digits,
                           repeated);
            } else {
                if (digits & (1 << i)) {
                    ans += dfs(pos + 1, tight && i == limit, false, digits,
                               true);
                } else {
                    ans += dfs(pos + 1, tight && i == limit, false,
                               digits | (1 << i), repeated);
                }
            }
        }
        return ans;
    }

    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(vs, false, sizeof(vs));
        return dfs(0, true, true, 0, false);
    }
};

int main() {
    Solution s;
    cout << s.numDupDigitsAtMostN(20) << endl;
    cout << s.numDupDigitsAtMostN(100) << endl;
    cout << s.numDupDigitsAtMostN(1000) << endl;
    cout << s.numDupDigitsAtMostN(1e9) << endl;
    return 0;
}
