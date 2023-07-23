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

int maxDepth(TreeNode<int> *root) {
    queue<pair<TreeNode<int>*, int>> q;
    if(root != NULL){
        q.push({root, 0});
    }
    int height = 0;
    while(!q.empty()){
        TreeNode<int>* cur;
        int level;
        tie(cur, level) = q.front();
        q.pop();
        if(level > height){
            height = level;
        }
        if(cur -> left != NULL){
            q.push({cur -> left, level + 1});
        }
        if(cur -> right != NULL){
            q.push({cur -> right, level + 1});
        }
    }
    return height;
}
