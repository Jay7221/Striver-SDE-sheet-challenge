#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    queue<pair<TreeNode<int>*, int>> q;
    vector<bool> vis(6014);
    if(root != NULL){
        q.push({root, 3007});
    }
    deque<int> topView;
    int l = 3007, r = 3006;
    while(!q.empty()){
        queue<pair<TreeNode<int>*, int>> nq;
        while(!q.empty()){
            TreeNode<int> *cur;
            int level;
            tie(cur, level) = q.front();
            q.pop();
            if(level > r){
                topView.push_back(cur -> val);
                r = level;
            }
            if(level < l){
                topView.push_front(cur -> val);
                l = level;
            }
            if(cur -> left != NULL){
                nq.push({cur -> left, level - 1});
            }
            if(cur -> right != NULL){
                nq.push({cur -> right, level + 1});
            }
        }
        q = nq;
    }
    vector<int> ans;
    while(topView.size() > 0){
        ans.push_back(topView.front());
        topView.pop_front();
    }
    return ans;
}
