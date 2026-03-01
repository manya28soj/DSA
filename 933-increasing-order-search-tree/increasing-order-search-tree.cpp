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
//inorder
void inorder(TreeNode *root , vector<int> &in){
    if(root == NULL)
        return;
    inorder(root->left , in);
    in.push_back(root->val);
    inorder(root->right,in);
}


    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorderVal;
        inorder(root,inorderVal);
        int n = inorderVal.size();

        TreeNode* newRoot= new TreeNode(inorderVal[0]);
        TreeNode* curr = newRoot;
        //2nd step
        for(int i=1; i < n; i++){
            TreeNode* temp = new TreeNode(inorderVal[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        //3rd step
        curr->left= NULL;
        curr->right=NULL;

        return newRoot;
    }
};