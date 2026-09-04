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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int ans = 0;

        while (!q.empty()) {
            int n = q.size();

            long long offset = q.front().second;

            long long first = 0;
            long long last = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front().first;
                long long index = q.front().second - offset;
                q.pop();

                if (i == 0)
                    first = index;
                if (i == n - 1)
                    last = index;

                if (temp->left)
                    q.push({temp->left, 2 * index});

                if (temp->right)
                    q.push({temp->right, 2 * index + 1});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};