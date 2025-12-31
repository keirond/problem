#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    bool vs[9][2][1 << 10];
    int f[9][2][1 << 10];

    int dfs(int pos, bool leadingZero, int digits) {
        if (pos == n) { return 1; }
        if (vs[pos][leadingZero][digits]) {
            return f[pos][leadingZero][digits];
        }

        vs[pos][leadingZero][digits] = true;
        int &ans = f[pos][leadingZero][digits];
        ans = 0;

        for (int i = 0; i <= 9; i++) {
            if (leadingZero && i == 0) {
                ans += dfs(pos + 1, true, digits);
            } else if (!(digits & (1 << i))) {
                ans += dfs(pos + 1, false, digits | (1 << i));
            }
        }
        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        this->n = n;
        memset(vs, false, sizeof(vs));
        return dfs(0, true, 0);
    }
};

int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2) << endl;
    return 0;
}
