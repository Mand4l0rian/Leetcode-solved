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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                                   inorder.size() - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& inMap) {

        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // Root is the FIRST element in preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root in inorder
        int inRoot = inMap[root->val];

        // Number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inMap);

        // Build right subtree
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};