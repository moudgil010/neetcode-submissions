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
    bool isIdentical(TreeNode* r, TreeNode* s) {
        if(s==NULL && r==NULL) return true;
        if(s==NULL || r==NULL) return false;
        return (r->val == s->val) && isIdentical(r->left, s->left)&& isIdentical(r->right, s->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root->val == subRoot->val && isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
