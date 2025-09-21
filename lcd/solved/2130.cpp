#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int pairSum(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *curr = head, *next = head->next;
        while (curr != slow) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        int ans = INT_MIN;
        while (slow && prev) {
            ans = max(ans, slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }
        return ans;
    }
};

