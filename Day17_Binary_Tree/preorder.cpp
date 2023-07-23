#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* cur = st.top();
        st.pop();
        if(cur == NULL){
            continue;
        }

        preorder.push_back(cur -> data);
        st.push(cur -> right);
        st.push(cur -> left);
    }
    return preorder;
}
