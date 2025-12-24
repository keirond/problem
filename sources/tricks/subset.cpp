#include <bits/stdc++.h>
using namespace std;

void Subsets_of_an_Array(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { cout << nums[j] << ' '; }
        }
        cout << endl;
    }
}

void Subsets_of_an_Array_without_Duplication(vector<int> &__) {}

void Unempty_Subsets_of_a_Subset(int binary_set) {
    int subset = binary_set;
    while (subset) {
        cout << bitset<10>(subset) << endl;
        subset = (subset - 1) & binary_set;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 4};
    // Subsets_of_an_Array(nums);
    // Subsets_of_an_Array_without_Duplication(nums)
    // Unempty_Subsets_of_a_Subset(6);
}

