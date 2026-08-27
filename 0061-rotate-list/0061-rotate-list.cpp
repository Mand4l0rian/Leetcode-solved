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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        int count=1;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
            count++;
        }
        temp->next=head;
        int rotate=k%count;
        rotate=count-rotate;
        while(rotate!=0){
            temp=temp->next;
            rotate--;
        }
        ListNode* ans=temp->next;
        temp->next=nullptr;
        return ans;
    }
};