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
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    stack<TreeNode*> st;
    auto proc = [&](TreeNode* cur){
        while(cur != NULL){
            st.push(cur);
            cur = (cur -> left);
        }
    };
    proc(root);
    while(!st.empty()){
        TreeNode* cur = st.top();
        st.pop();

        inorder.push_back(cur -> data);
        proc(cur -> right);
    }
    return inorder;
}
