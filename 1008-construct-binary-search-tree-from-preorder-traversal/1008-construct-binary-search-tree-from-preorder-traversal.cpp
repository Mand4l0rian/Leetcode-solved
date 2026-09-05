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
    TreeNode* solve(int start, int end, vector<int>& preorder){
        if(start>end) return nullptr;
        int root=preorder[start];
        TreeNode* temp=new TreeNode(root);
        int mid=start+1;
        while(mid<=end && preorder[mid]<preorder[start]){
            mid++;
        }
        temp->left=solve(start+1,mid-1,preorder);
        temp->right=solve(mid,end,preorder);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(0,preorder.size()-1,preorder);
    }
};