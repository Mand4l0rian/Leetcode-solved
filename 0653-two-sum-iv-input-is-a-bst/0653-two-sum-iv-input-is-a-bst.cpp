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
    bool ans=false;
    void solve(int& k,TreeNode* root,unordered_map<int,int>& mpp){
        if(!root || ans) return;
        int diff=k-root->val;
        if(mpp.find(diff)!=mpp.end()){
            ans=true;
        }else{
            mpp[root->val]++;
            solve(k,root->left,mpp);
            solve(k,root->right,mpp);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mpp;
        solve(k,root,mpp);
        return ans;
    }
};