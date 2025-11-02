#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> lcp(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && nums[i] != nums[j]) { j = ans[j - 1]; }
            if (nums[i] == nums[j]) { j++; }
            ans[i] = j;
        }
        return ans;
    }

    using ll = long long;
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int n = nums.size();
        int m = groups.size();
        int ci = 0;
        for (int i = 0; i < m; i++) {
            int cm = groups[i].size();
            vector<int> lcp_arr = lcp(groups[i]);
            bool can = false;
            for (int j = 0; ci < n; ci++) {
                while (j > 0 && nums[ci] != groups[i][j]) {
                    j = lcp_arr[j - 1];
                }
                if (nums[ci] == groups[i][j]) { j++; }
                if (j == cm) {
                    ci++;
                    can = 1;
                    break;
                }
            }
            if (!can) { return false; }
        }
        return true;
    }
};

