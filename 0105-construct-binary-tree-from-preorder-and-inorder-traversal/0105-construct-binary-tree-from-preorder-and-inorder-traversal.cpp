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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inStart,
                    int inEnd, int& preIndex, unordered_map<int, int>& mp) {

        if (inStart > inEnd)
            return nullptr;

        // First element in preorder is the root
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int mid = mp[rootVal];

        // Preorder: root -> left -> right
        root->left = solve(preorder, inorder, inStart, mid - 1, preIndex, mp);

        root->right = solve(preorder, inorder, mid + 1, inEnd, preIndex, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int preIndex = 0;

        return solve(preorder, inorder, 0, inorder.size() - 1, preIndex, mp);
    }
};