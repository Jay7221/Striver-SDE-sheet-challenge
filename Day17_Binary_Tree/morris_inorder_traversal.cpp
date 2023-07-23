#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    TreeNode* cur = root;
    vector<int> inorder;
    while(cur != NULL){
        if(cur -> left == NULL){
            inorder.push_back(cur -> data);
            cur = cur -> right;
        }else{
            TreeNode *prev = cur -> left;
            while((prev -> right != NULL) && (prev -> right != cur)){
                prev = prev -> right;
            }
            if(prev -> right == cur){
                prev -> right = NULL;
                inorder.push_back(cur -> data);
                cur = cur -> right;
            }else{
                prev -> right = cur;
                cur = cur -> left;
            }
        }
    }
    return inorder;
}
