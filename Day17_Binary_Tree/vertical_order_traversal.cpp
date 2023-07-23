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

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int, vector<int>> mp;
    vector<int> verticalTraversal;
    queue<pair<TreeNode<int>*, int>> q;
    if(root != NULL){
        q.push({root, 0});
    }
    while(!q.empty()){
        queue<pair<TreeNode<int>*, int>> nq;
        while(!q.empty()){
            TreeNode<int>* cur;
            int level;
            tie(cur, level) = q.front();
            q.pop();
            mp[level].push_back(cur -> data);
            if(cur -> left != NULL){
                nq.push({cur -> left, level - 1});
            }
            if(cur -> right != NULL){
                nq.push({cur -> right, level + 1});
            }
        }
        q = nq;
    }
    for(auto p : mp){
        for(int elem : p.second){
            verticalTraversal.push_back(elem);
        }
    }
    return verticalTraversal;
}
