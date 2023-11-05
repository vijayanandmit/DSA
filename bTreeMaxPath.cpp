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
    int maxSum=INT_MIN;
    int maxPath(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftGain = max(maxPath(root->left), 0);
        int rightGain = max(maxPath(root->right), 0);

        int newValue = leftGain + rightGain + root->val;
        maxSum = max(maxSum, newValue);

        return root->val + max(leftGain, rightGain);

    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }
};