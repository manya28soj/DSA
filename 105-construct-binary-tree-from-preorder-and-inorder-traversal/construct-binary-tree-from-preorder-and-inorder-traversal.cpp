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

int findPosition(vector<int>& inorder,int element , int inorderStart, int inorderEnd){
    for(int i=inorderStart; i<=inorderEnd; i++){
        if(inorder[i] == element)
        return i;
    }
    return -1;
}

TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int &preindex, int inorderStart,int inorderEnd,int n){
    //base case
    if(preindex >= n || inorderStart > inorderEnd){
        return NULL;
    }
    int element = preorder[preindex++];
    TreeNode* root= new TreeNode(element);
    int position = findPosition(inorder,element,inorderStart,inorderEnd);

    //recursiva call
    root->left = solve(preorder,inorder,preindex,inorderStart,position-1,n);
    root->right = solve(preorder,inorder,preindex,position+1,inorderEnd,n);
    return root;
}


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preOrderIndex = 0;
        TreeNode* ans  = solve(preorder,inorder,preOrderIndex,0,n-1,n);
        return ans;
    }
};