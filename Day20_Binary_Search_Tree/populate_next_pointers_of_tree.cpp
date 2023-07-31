#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*> q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        int sz = q.size();
        BinaryTreeNode<int> * prev = NULL;
        while(sz--){
            if(prev){
                prev -> next = q.front();
            }
            prev = q.front();
            q.pop();
            if(prev ->left){
                q.push(prev -> left);
            }
            if(prev -> right){
                q.push(prev -> right);
            }
        }
    }
}
