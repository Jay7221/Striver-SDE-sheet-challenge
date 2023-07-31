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
TreeNode<int>* construct(vector<int> &arr, int l, int r){
    TreeNode<int> *root = NULL;
    if(l > r){
        return root;
    }
    int mid = (l + r) / 2;
    root = new TreeNode<int>(arr[mid]);
    root -> left = construct(arr, l, mid - 1);
    root -> right = construct(arr, mid + 1, r);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return construct(arr, 0, n - 1);
}
