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

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    map<int, int> ind;
    for(int i = 0; i < inorder.size(); ++i){
        ind[inorder[i]] = i;
    }
    function<TreeNode<int>*(int, int, int, int)> construct;
    construct = [&](int preStart, int preEnd, int inStart, int inEnd){
        TreeNode<int> *root = NULL;
        if((preStart > preEnd) || (inStart > inEnd)){
            return root;
        }
        int rootData = preorder[preStart];
        root = new TreeNode<int>(rootData);
        int leftSize = ind[rootData] - inStart;
        root -> left = construct(preStart + 1, preStart + leftSize, inStart, inStart + leftSize);
        root -> right = construct(preStart + leftSize + 1, preEnd, inStart + leftSize + 1, inEnd);
        return root;
    };
    return construct(0, preorder.size() - 1, 0, inorder.size() - 1);
}
