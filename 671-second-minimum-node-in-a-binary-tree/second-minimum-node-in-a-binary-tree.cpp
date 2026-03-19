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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        long minVal = root->val;
        return dfs(root,minVal);
            }
        long dfs(TreeNode* node, long minVal){
            if(!node)
                return-1;
            if(node->val > minVal){
                return node->val;
            }
            long left = dfs(node->left,minVal);
            long right = dfs(node->right,minVal);

            if(left == -1)
                return right;
            if(right == -1)
                return left;

            return min(left,right);
        }
};