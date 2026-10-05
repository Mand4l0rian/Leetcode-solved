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

    TreeNode* helper(TreeNode* root) {

        // No left child
        if (root->left == NULL)
            return root->right;

        // No right child
        if (root->right == NULL)
            return root->left;

        // Both children exist
        TreeNode* rightChild = root->right;
        TreeNode* leftmost = rightChild;

        while (leftmost->left != NULL) {
            leftmost = leftmost->left;
        }

        // Attach left subtree to leftmost node
        leftmost->left = root->left;

        return rightChild;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        // Deleting root itself
        if (root->val == key)
            return helper(root);

        TreeNode* curr = root;

        while (curr != NULL) {

            if (key < curr->val) {

                if (curr->left != NULL &&
                    curr->left->val == key) {

                    curr->left = helper(curr->left);
                    break;
                }

                curr = curr->left;
            }

            else {

                if (curr->right != NULL &&
                    curr->right->val == key) {

                    curr->right = helper(curr->right);
                    break;
                }

                curr = curr->right;
            }
        }

        return root;
    }
};