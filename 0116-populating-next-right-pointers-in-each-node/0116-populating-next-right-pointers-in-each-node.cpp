/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// LEVEL ORDER TRAVERSAL/ BFS TC=O(N) SC=O(N)
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root==nullptr) return root;
//         queue<Node*> q;
//         q.push(root);
//         while(!q.empty()){
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 Node* temp=q.front();
//                 q.pop();
//                 if(i==n-1) temp->next=nullptr;
//                 else temp->next=q.front();
//                 if(temp->left) q.push(temp->left);
//                 if(temp->right) q.push(temp->right);
//             }
//         }
//         return root;
//     }
// };

// OPTIMAL APPROACH TC=O(N) SC=O(1) EXPLOIT PERFECT BINARY TREE STRUCTURE
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        Node* leftmost = root;
        while (leftmost->left != nullptr) {
            Node* curr = leftmost;
            while (curr != nullptr) {
                curr->left->next = curr->right;
                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};