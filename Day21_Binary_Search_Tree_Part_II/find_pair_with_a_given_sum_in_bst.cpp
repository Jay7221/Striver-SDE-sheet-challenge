#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> v;
    function<void(BinaryTreeNode<int>*)> fill;
    fill = [&](BinaryTreeNode<int> *root){
        if(root == NULL){
            return;
        }
        fill(root -> left);
        v.push_back(root -> data);
        fill(root -> right);
    };
    fill(root);
    int l = 0, r = v.size() - 1;
    while(l < r){
        if(v[l] + v[r] == k){
            return true;
        }
        if(v[l] + v[r] < k){
            ++l;
        }else{
            --r;
        }
    }
    return false;
}
