#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long ans = 0;
        vector<deque<pair<int, int>>> f(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0, r = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    int cw = 0;
                    while (!f[j].empty()) {
                        auto [h, w] = f[j].back();
                        cw += w;
                        ans = max(ans, 1LL * h * cw);
                        f[j].pop_back();
                    }
                } else {
                    r = max(j, r);
                    while (r < m && matrix[i][r] == '1') { r++; }
                    int ch = r - j, cw = 0;
                    while (!f[j].empty() && f[j].back().first >= ch) {
                        auto [h, w] = f[j].back();
                        cw += w;
                        ans = max(ans, 1LL * h * cw);
                        f[j].pop_back();
                    }
                    f[j].push_back({ch, cw + 1});
                }
            }
        }

        for (int j = 0; j < m; j++) {
            int cw = 0;
            while (!f[j].empty()) {
                auto [h, w] = f[j].back();
                cw += w;
                ans = max(ans, 1LL * h * cw);
                f[j].pop_back();
            }
        }
        return ans;
    }
};

