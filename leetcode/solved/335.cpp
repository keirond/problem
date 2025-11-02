#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSelfCrossing(vector<int> &d) {
        int n = d.size();
        for (int i = 0; i < n; i++) {
            if (i >= 3 && d[i - 1] <= d[i - 3] && d[i] >= d[i - 2]) {
                return true;
            }
            if (i >= 4 && d[i - 1] == d[i - 3] && d[i] + d[i - 4] >= d[i - 2]) {
                return true;
            }
            if (i >= 5 && d[i - 2] >= d[i - 4] && d[i - 1] <= d[i - 3] &&
                d[i - 1] + d[i - 5] >= d[i - 3] &&
                d[i] + d[i - 4] >= d[i - 2]) {
                return true;
            }
        }
        return false;
    }
};

