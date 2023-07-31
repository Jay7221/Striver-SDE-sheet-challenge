#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    TreeNode<int> *root = new TreeNode<int>(preOrder[0]);
    stack<TreeNode<int>*> st;
    TreeNode<int> *cur = root;
    for(int i = 1; i < preOrder.size(); ++i){
        while((st.size() > 0) && (st.top() -> data < preOrder[i])){
            cur = st.top();
            st.pop();
        }
        if((cur -> data) > preOrder[i]){
            cur -> left = new TreeNode<int>(preOrder[i]);
            st.push(cur);
            cur = cur -> left;
        }else{
            cur -> right = new TreeNode<int>(preOrder[i]);
            cur = cur -> right;
        }
    }
    return root;
}
