#include <bits/stdc++.h> 
/********************************************************************

    Following is the Binary Tree node structure:

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
    
********************************************************************/
bool isLeaf(BinaryTreeNode<int>* leaf){
    return ((leaf -> left == NULL) && (leaf -> right == NULL));
}
vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    string curPath;
    vector<string> paths;
    function<void(BinaryTreeNode<int>*)> dfs;
    dfs = [&](BinaryTreeNode<int>* root){
        curPath += to_string(root -> data);
        if(isLeaf(root)){
            paths.push_back(curPath);
        }else{
            curPath.push_back(' ');
            if(root -> left != NULL){
                dfs(root -> left);
            }
            if(root -> right != NULL){
                dfs(root -> right);
            }
            curPath.pop_back();
        }
        int sz = to_string(root -> data).size();
        while(sz--){
            curPath.pop_back();
        }
    };
    if(root != NULL){
        dfs(root);
    }
    return paths;
}
