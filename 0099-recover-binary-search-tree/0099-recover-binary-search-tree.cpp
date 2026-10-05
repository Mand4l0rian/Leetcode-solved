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
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root) {

        if (root == NULL)
            return;

        inorder(root->left);

        // Violation found
        if (root->val < prev->val) {

            // First violation
            if (first == NULL) {
                first = prev;
                middle = root;
            }

            // Second violation
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {

        first = middle = last = NULL;

        // Smallest possible value
        prev = new TreeNode(INT_MIN);

        inorder(root);

        // Non-adjacent nodes were swapped
        if (first != NULL && last != NULL)
            swap(first->val, last->val);

        // Adjacent nodes were swapped
        else if (first != NULL && middle != NULL)
            swap(first->val, middle->val);
    }
};