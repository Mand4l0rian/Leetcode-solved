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

 // MORRIS TRAVERSAL LIKE SOLUTION TC=O(N) SC=O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;

                // Find the rightmost node of left subtree
                while (prev->right) {
                    prev = prev->right;
                }

                // Connect it to the original right subtree
                prev->right = curr->right;

                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};