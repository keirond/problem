#include <bits/stdc++.h>

using namespace std;

int min_non_zero_xor_subset(vector<int> &nums) {
    vector<int> basis(31);
    for (int d : nums) {
        int cur = d;
        for (int i = 30; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = cur;
                    break;
                }
                cur ^= basis[i];
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 31; i++) {
        if (basis[i]) { ans = min(ans, ans ^ basis[i]); }
    }
    return ans;
}

bool check_if_a_number_can_be_formed_by_subset(vector<int> &nums, int target) {
    vector<int> basis(31);
    for (int d : nums) {
        int cur = d;
        for (int i = 30; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = cur;
                    break;
                }
                cur ^= basis[i];
            }
        }
    }

    for (int i = 30; i >= 0; i--) {
        if (target & (1 << i)) { target ^= basis[i]; }
    }
    return !target;
}

int main() { return 0; }
