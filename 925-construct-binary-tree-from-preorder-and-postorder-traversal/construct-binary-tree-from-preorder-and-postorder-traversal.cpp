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
    unordered_map<int,int> postIndex;

    TreeNode* build(vector<int>& preorder, vector<int>& postorder,
                    int preStart, int preEnd,
                    int postStart, int postEnd) {

        if(preStart > preEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        if(preStart == preEnd)
            return root;

        // Next preorder element is left child
        int leftRootVal = preorder[preStart + 1];

        // Find left subtree size using postorder
        int index = postIndex[leftRootVal];
        int leftSize = index - postStart + 1;

        root->left = build(preorder, postorder,
                           preStart + 1,
                           preStart + leftSize,
                           postStart,
                           index);

        root->right = build(preorder, postorder,
                            preStart + leftSize + 1,
                            preEnd,
                            index + 1,
                            postEnd - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int n = preorder.size();

        // create mapping of postorder value → index
        for(int i = 0; i < n; i++) {
            postIndex[postorder[i]] = i;
        }

        return build(preorder, postorder, 0, n-1, 0, n-1);
    }
};