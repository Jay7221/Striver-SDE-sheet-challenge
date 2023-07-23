#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void util(TreeNode<int> *root, TreeNode<int>* parent, TreeNode<int>* leaf, bool &found, TreeNode<int> *&ans){
    if(root == NULL){
        return;
    }
    if(root -> data == leaf -> data){
        found = true;
        root -> left = parent;
        ans = root;
        return;
    }
    util(root -> left, root, leaf, found, ans);
    if(found){
        root -> left = parent;
        return;
    }
    util(root -> right, root, leaf, found, ans);
    if(found){
        root -> right = root -> left;
        root -> left = parent;
        return;
    }
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    bool found = false;
    TreeNode<int>* ans = NULL;
    util(root, NULL, leaf, found, ans);
    return ans;
}
