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
class Solution {
public:
    int ans=0;
    int maxleftnoderight(TreeNode* root){
        if(root==nullptr) return 0;
        int left=maxleftnoderight(root->left);
        int right=maxleftnoderight(root->right);
        ans=max(ans,right+left);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxleftnoderight(root);
        return ans;
    }
};