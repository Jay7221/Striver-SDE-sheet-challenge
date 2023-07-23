#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int>* root2){
    if((root1 == NULL) && (root2 == NULL)){
        return true;
    }
    if((root1 == NULL) || (root2 == NULL)){
        return false;
    }
    return ((root1 -> data == root2 -> data) && areMirror(root1 -> left, root2 -> right) && areMirror(root1 -> right, root2 -> left));
}
bool isSymmetric(BinaryTreeNode<int>* root) {
	if(root == NULL){
        return true;
    }
    return areMirror(root -> left, root -> right);
}
