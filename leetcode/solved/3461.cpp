#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool hasSameDigits(string s) {
        int n = s.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) { nums[i] = s[i] - '0'; }
        while (n > 2) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--;
        }
        return nums[0] == nums[1];
    }
};

