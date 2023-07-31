#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
struct info{
    public:
    int mini;
    int maxi;
    bool is_bst;
    int size;
};
info solve(TreeNode<int> *root, int &ans){
    if(!root){
        return {INT_MAX, INT_MIN, true, 0};
    }

    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);

    info cur;
    cur.mini = min(root -> data, left.mini);
    cur.maxi = max(root -> data, right.maxi);
    cur.size = 1 + left.size + right.size;

    if(left.is_bst && right.is_bst && (root -> data > left.maxi) && (root -> data < right.mini)){
        cur.is_bst = true;
    }else{
        cur.is_bst = false;
    }
    if(cur.is_bst){
        ans = max(ans, cur.size);
    }
    return cur;
}
int largestBST(TreeNode<int>* root) 
{
    int ans = 0;
    solve(root, ans);
    return ans;
}

