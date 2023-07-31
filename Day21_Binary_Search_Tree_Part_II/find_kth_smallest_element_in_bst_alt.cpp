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
const int INF = 1e9 + 7;
int kthSmallest(TreeNode<int> *root, int &k)
{
    if(root == NULL){
        return INF;
    }
    int l = kthSmallest(root -> left, k);
    if(l != INF){
        return l;
    }
    --k;
    if(k == 0){
        return (root -> data);
    }
    return kthSmallest(root -> right, k);
}
