#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int> *node){
    return ((node -> left == NULL) && (node -> right == NULL));
}
void addLeft(TreeNode<int> *root, vector<int> &res){
    TreeNode<int>*cur = root -> left;
    while(cur != NULL){
        if(!isLeaf(cur)){
            res.push_back(cur -> data);
        }
        if(cur -> left){
            cur = cur -> left;
        }else{
            cur = cur -> right;
        }
    }
}
void addRight(TreeNode<int> *root, vector<int> &res){
    int sz = res.size();
    TreeNode<int> *cur = root -> right;
    while(cur){
        if(!isLeaf(cur)){
            res.push_back(cur -> data);
        }
        if(cur -> right){
            cur = cur -> right;
        }else{
            cur = cur -> left;
        }
    }
    reverse(res.begin() + sz, res.end());
}
void addLeaf(TreeNode<int> *root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root -> data);
    }else{
        if(root -> left){
            addLeaf(root -> left, res);
        }
        if(root -> right){
            addLeaf(root -> right, res);
        }
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    if(!isLeaf(root)){
        res.push_back(root -> data);
    }
    addLeft(root, res);
    addLeaf(root, res);
    addRight(root, res);

    return res;
}
