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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        TreeNode* Node=root;
        int level=1;
        while(!q.empty()){
            TreeNode* curnode=q.front().first;
            int curlevel=q.front().second;
            q.pop();
            if(curlevel!=level){
                ans.push_back(Node->val);
            }
            Node=curnode;
            level=curlevel;
            if(curnode->left!=nullptr) q.push({curnode->left,curlevel+1});
            if(curnode->right!=nullptr) q.push({curnode->right,curlevel+1});
        }
        ans.push_back(Node->val);
        return ans;
    }
};