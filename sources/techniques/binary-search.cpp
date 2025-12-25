#include <bits/stdc++.h>
using namespace std;

// nums is sorted

int firstIndex(vector<int> &nums, int target) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return nums[l] == target ? l : -1;
}

int lastIndex(vector<int> &nums, int target) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l + 1 >> 1);
        if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    return nums[r] == target ? r : -1;
}

int lowerBound(vector<int> &nums, int target) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int upperBound(vector<int> &nums, int target) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l + 1 >> 1);
        if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    return r;
}

// for decreasing array, swap < and >

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5,
                        5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7};
    // cout << firstIndex(nums, 6) << endl;
    // cout << lastIndex(nums, 2) << endl;
    // cout << lowerBound(nums, 6) << endl;
    // cout << upperBound(nums, 6) << endl;
}
