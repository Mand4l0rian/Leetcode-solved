/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// RECURSIVE TC=O(N) SC=O(N)
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& ans){
//         if(root==nullptr) return;
//         ans.push_back(root->val);
//         inorder(root->left,ans);
//         inorder(root->right,ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inorder(root,ans);
//         return ans;
//     }
// };

// MORRIS PREORDER SOLUTION TC=O(N) SC=O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    ans.push_back(curr->val);
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};