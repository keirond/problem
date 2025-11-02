#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string getPermutation(int n, int k) {
        vector<bool> ds(n);
        int t = 1;
        for (int i = 1; i <= n; i++) { t *= i; }

        auto get = [&](int x) {
            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (!ds[i]) {
                    if (++idx == x) { return i + 1; }
                }
            }
            return 1;
        };

        int m = n;
        string ans;
        while (m) {
            t /= m--;
            int d = (k - 1) / t;
            int i = get(d + 1);
            ans.push_back(i + '0');
            ds[i - 1] = 1;
            k -= d * t;
        }
        return ans;
    }
};

