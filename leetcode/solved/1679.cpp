#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxOperations(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (mp[k - nums[i]]) {
                mp[k - nums[i]]--;
                ans++;
            } else {
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};

