#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool hasSameDigits(string s) {
        int n = s.size();

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int a = n - 2, b = i;
            int t1 = 1;
            while (b) {
                int x = a % 2, y = b % 2;
                if (y > x) {
                    t1 = 0;
                    break;
                }
                a /= 2, b /= 2;
            }

            a = n - 2, b = i;
            vector<int> fact{1, 1, 2, 1, 4};
            int t2 = 1;
            while (b) {
                int x = a % 5, y = b % 5;
                if (y > x) {
                    t2 = 0;
                    break;
                }
                int t = 1LL * fact[x] * fact[y] * fact[y] * fact[y] *
                        fact[x - y] * fact[x - y] * fact[x - y] % 5;
                t2 = 1LL * t2 * t % 5;
                a /= 5, b /= 5;
            }

            int t3 = (t1 * 5 + t2 * 6) % 10;
            ans = (ans + t3 * (s[i] - s[i + 1])) % 10;
        }
        return !ans;
    }
};

