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
    TreeNode* solve(int low, int high, vector<int>& nums){
        if(low>high) return nullptr;
        int mid=(low+high)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left=solve(low,mid-1,nums);
        temp->right=solve(mid+1,high,nums);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};