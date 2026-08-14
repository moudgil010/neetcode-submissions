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
    int helper(TreeNode* root, int ans, int curr) {
        if(root == NULL) return 0;
        int currAns = 0;
        if(root->val >= curr) {
            currAns = 1;
            curr = root->val;
        }
        int lans = helper(root->left, ans, curr);
        int rans = helper(root->right, ans, curr);

        return currAns+lans+rans; 
    }
    int goodNodes(TreeNode* root) {
        int curr = INT_MIN;
        return helper(root, 0, curr);
    }
};
