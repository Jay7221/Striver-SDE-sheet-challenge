#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    vector<int> zigzagTraversal;
    queue<TreeNode<int>*> q;
    if(root != NULL){
        q.push(root);
    }
    bool flag = false;
    while(!q.empty()){
        queue<TreeNode<int>*> nq;
        int s = zigzagTraversal.size();
        while(!q.empty()){
            TreeNode<int> *cur = q.front();
            q.pop();
            zigzagTraversal.push_back(cur -> data);

            if(cur -> left != NULL){
                nq.push(cur -> left);
            }
            if(cur -> right != NULL){
                nq.push(cur -> right);
            }
        }
        if(flag){
            reverse(zigzagTraversal.begin() + s, zigzagTraversal.end());
        }
        flag ^= 1;
        q = nq;
    }
    return zigzagTraversal;
}
