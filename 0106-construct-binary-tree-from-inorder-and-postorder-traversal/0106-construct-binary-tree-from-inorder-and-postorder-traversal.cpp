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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, inorder,
                                   0, inorder.size() - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& inMap) {

        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        // Root is the LAST element in postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // Find root in inorder
        int inRoot = inMap[root->val];

        // Number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = buildTree(postorder, postStart, postStart + numsLeft - 1,
                               inorder, inStart, inRoot - 1, inMap);

        // Build right subtree
        root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};