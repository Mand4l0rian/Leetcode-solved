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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root= new TreeNode(val);
            return root;
        }
        TreeNode* roottrav= root;
        while(roottrav){
            if(val>roottrav->val && roottrav->right!=NULL){
                roottrav=roottrav->right;
            }else if(val<roottrav->val && roottrav->left!=NULL){
                roottrav=roottrav->left;
            }else{
                break;
            }
        }
        TreeNode* curr= new TreeNode(val);
        if(val>roottrav->val){
            roottrav->right= curr;
        }else{
            roottrav->left= curr;
        }
        return root;
    }
};