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

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> leftView;
    queue<TreeNode<int>*> q;
    if(root != NULL){
        q.push(root);
    }
    while(!q.empty()){
        leftView.push_back(q.front() -> data);
        queue<TreeNode<int>*> nq;
        while(!q.empty()){
            TreeNode<int>* cur = q.front();
            q.pop();
            if(cur -> left != NULL){
                nq.push(cur -> left);
            }
            if(cur -> right != NULL){
                nq.push(cur -> right);
            }
        }
        q = nq;
    }
    return leftView;
}
