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
    bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // 1. Find middle using slow/fast
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is now the last node of the first half (or the middle for odd length)

    // 2. Reverse the second half
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    while (curr != nullptr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    // 3. Compare first half with reversed second half
    ListNode* p1 = head;
    ListNode* p2 = prev;
    bool result = true;
    while (p2 != nullptr) {
        if (p1->val != p2->val) { result = false; break; }
        p1 = p1->next;
        p2 = p2->next;
    }

    return result; // (optionally re-reverse the second half here to restore the list)
}
};