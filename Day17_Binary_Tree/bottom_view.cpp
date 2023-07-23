#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    int rootLevel, minLevel, maxLevel;
    rootLevel = minLevel = maxLevel = 0;
    function<void(BinaryTreeNode<int>*, int)> dfs1;
    dfs1 = [&](BinaryTreeNode<int>* node, int level){
        if(node == NULL){
            return;
        }
        minLevel = min(minLevel, level);
        maxLevel = max(maxLevel, level);
        dfs1(node -> left, level - 1);
        dfs1(node -> right, level + 1);
    };
    dfs1(root, rootLevel);
    rootLevel -= minLevel;
    maxLevel -= minLevel;
    minLevel -= minLevel;
    
    vector<int> bView(maxLevel + 1);
    queue<pair<BinaryTreeNode<int>*, int>> q;
    if(root != NULL){
        q.push({root, rootLevel});
    }
    while(!q.empty()){
        queue<pair<BinaryTreeNode<int>*, int>> nq;
        while(!q.empty()){
            int level;
            BinaryTreeNode<int> *cur;
            tie(cur, level) = q.front();
            q.pop();
            bView[level] = cur -> data;
            if(cur -> left != NULL){
                nq.push({cur -> left, level - 1});
            }
            if(cur -> right != NULL){
                nq.push({cur -> right, level + 1});
            }
        }
        q = nq;
    }
    return bView;
}
