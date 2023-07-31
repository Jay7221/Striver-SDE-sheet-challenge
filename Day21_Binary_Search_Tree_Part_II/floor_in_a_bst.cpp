#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    while(root != NULL){
        if(root -> val <= X){
            ans = root -> val;
            root = root -> right;
        }else{
            root = root -> left;
        }
    }
    return ans;
}
