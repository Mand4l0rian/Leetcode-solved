/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        Node* temp=head;
        while(temp!=nullptr){
            Node* temp1=new Node(temp->val);
            temp1->next=temp->next;
            temp->next=temp1;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->random!=nullptr){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        Node* temp1=head;
        temp=head->next;
        Node* ans=temp;
        while(temp->next!=nullptr){
            temp1->next=temp1->next->next;
            temp->next=temp->next->next;
            temp1=temp1->next;
            temp=temp->next;
        }
        temp1->next=temp1->next->next;
        return ans;
    }
};