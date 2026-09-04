/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart,
                    int inEnd, int& postIndex, unordered_map<int, int>& mp) {

        if (inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        // Postorder is: left -> right -> root
        // Since we're going backwards, build right first.
        root->right = solve(inorder, postorder, mid + 1, inEnd, postIndex, mp);

        root->left = solve(inorder, postorder, inStart, mid - 1, postIndex, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int postIndex = postorder.size() - 1;

        return solve(inorder, postorder, 0, inorder.size() - 1, postIndex, mp);
    }
};