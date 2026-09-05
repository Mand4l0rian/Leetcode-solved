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
    bool ans = true;

    void solve(long long lowerbound, long long upperbound, TreeNode* root) {
        if(root == nullptr) return;

        if(root->val > lowerbound && root->val < upperbound && ans) {
            solve(lowerbound, root->val, root->left);

            if(!ans) return;

            solve(root->val, upperbound, root->right);
        }
        else {
            ans = false;
        }
    }

    bool isValidBST(TreeNode* root) {
        solve(LLONG_MIN, LLONG_MAX, root);
        return ans;
    }
};