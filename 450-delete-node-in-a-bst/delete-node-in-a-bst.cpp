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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        //search for node
        if(key < root->val)
            root->left = deleteNode(root->left,key);
        else if(key>root->val)
            root->right = deleteNode(root->right,key);
        else{
            //node found 
            //1. no child
            if(root->left == NULL && root->right == NULL){
                delete root ;
                return NULL;
            }
            //2.one child 
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
             if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            ///3. two child
            TreeNode* temp = root->right;
            //find inorder successor
            while(temp->left != NULL)
                temp=temp->left;

                root->val = temp->val;

                //delete successor
                root->right = deleteNode(root->right,temp->val);

        }
        return root;
    }
};