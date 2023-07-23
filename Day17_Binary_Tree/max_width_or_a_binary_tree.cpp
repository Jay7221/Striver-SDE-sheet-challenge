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

int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    queue<TreeNode<int>*> q;
    if(root != NULL){
        q.push(root);
    }
    while(!q.empty()){
        queue<TreeNode<int>*> nq;
        ans = max(ans, (int)q.size());
        while(!q.empty()){
            TreeNode<int>* cur = q.front();
            q.pop();
            if(cur -> left){
                nq.push(cur -> left);
            }
            if(cur -> right){
                nq.push(cur -> right);
            }
        }
        q = nq;
    }
    return ans;
}
