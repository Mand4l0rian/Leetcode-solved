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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        while (root) {

            // No left subtree
            if (!root->left) {

                // Check inorder violation
                if (prev && prev->val > root->val) {
                    if (!first)
                        first = prev;

                    second = root;
                }

                prev = root;
                root = root->right;
            }

            // Left subtree exists
            else {
                TreeNode* predecessor = root->left;

                // Find inorder predecessor
                while (predecessor->right &&
                       predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // First time: create thread
                if (!predecessor->right) {
                    predecessor->right = root;
                    root = root->left;
                }

                // Second time: remove thread and visit root
                else {
                    predecessor->right = nullptr;

                    // Check inorder violation
                    if (prev && prev->val > root->val) {
                        if (!first)
                            first = prev;

                        second = root;
                    }

                    prev = root;
                    root = root->right;
                }
            }
        }

        swap(first->val, second->val);
    }
};