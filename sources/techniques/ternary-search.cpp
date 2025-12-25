#include <bits/stdc++.h>
using namespace std;

int ternarySearch(vector<int> &nums) {
    int n = nums.size(), l = 0, r = n - 1;
    while (r - l > 1) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (nums[m1] < nums[m2]) {
            l = m1 + 1;
        } else {
            r = m2 - 1;
        }
    }
    int best = l;
    for (int i = l; i <= r; i++) {
        if (nums[i] > nums[best]) { best = i; }
    }
    return nums[best];
}

int binaryPeakSearch(vector<int> &nums) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (nums[m] < nums[m + 1]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return nums[l];
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 6};
    // cout << ternarySearch(nums) << endl;
    // cout << binaryPeakSearch(nums) << endl;
}
