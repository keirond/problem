#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    bool vs[9][1 << 10];
    int f[9][1 << 10];

    int dfs(int pos, int digits) {
        if (pos == n) { return 1; }
        if (vs[pos][digits]) { return f[pos][digits]; }

        vs[pos][digits] = true;
        int &ans = f[pos][digits];
        ans = 0;

        for (int i = 0; i <= 9; i++) {
            if (!(digits & (1 << i))) {
                ans += dfs(pos + 1, digits | (1 << i));
            }
        }
        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        this->n = n;
        memset(vs, false, sizeof(vs));
        return dfs(0, 0) + (n > 0);
    }
};

int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(0) << endl;
    return 0;
}
