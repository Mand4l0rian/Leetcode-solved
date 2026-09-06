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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        stack<TreeNode*> s1, s2;
        TreeNode* cur1 = root;
        TreeNode* cur2 = root;

        // Initialize iterator for smallest values
        while (cur1) {
            s1.push(cur1);
            cur1 = cur1->left;
        }

        // Initialize iterator for largest values
        while (cur2) {
            s2.push(cur2);
            cur2 = cur2->right;
        }

        while (!s1.empty() && !s2.empty() && s1.top() != s2.top()) {
            TreeNode* smallest = s1.top();
            TreeNode* largest = s2.top();

            int sum = smallest->val + largest->val;

            if (sum == k)
                return true;

            if (sum < k) {
                // Move to next larger value
                TreeNode* node = s1.top();
                s1.pop();

                node = node->right;
                while (node) {
                    s1.push(node);
                    node = node->left;
                }
            } 
            else {
                // Move to next smaller value
                TreeNode* node = s2.top();
                s2.pop();

                node = node->left;
                while (node) {
                    s2.push(node);
                    node = node->right;
                }
            }
        }

        return false;
    }
};