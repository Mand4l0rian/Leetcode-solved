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

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;

        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {

            // Find the kth node of the current group
            ListNode* kthNode = getKthNode(temp, k);

            // Less than k nodes remain
            if (kthNode == nullptr) {
                if (prevLast != nullptr)
                    prevLast->next = temp;
                break;
            }

            // Save the beginning of the next group
            ListNode* nextNode = kthNode->next;

            // Disconnect current group
            kthNode->next = nullptr;

            // Reverse current group
            reverseList(temp);

            // First group
            if (temp == head) {
                head = kthNode;
            }
            else {
                prevLast->next = kthNode;
            }

            // temp is now the last node of the reversed group
            prevLast = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};