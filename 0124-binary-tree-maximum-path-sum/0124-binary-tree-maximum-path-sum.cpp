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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        if(root==nullptr) return -1;
        int left=solve(root->left);
        int right=solve(root->right);
        ans=max(ans,root->val+max(left,0)+max(right,0));
        return root->val+max(left,max(right,0));
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};