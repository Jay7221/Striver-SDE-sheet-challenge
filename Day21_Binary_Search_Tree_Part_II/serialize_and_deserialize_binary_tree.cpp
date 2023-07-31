#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root)
{
    string s;
    function<void(TreeNode<int>*)> dfs;
    dfs = [&](TreeNode<int>* root){
        if(!root){
            return;
        }
        s += to_string(root -> data);
        if(root -> left){
            s.push_back('s');
            dfs(root -> left);
            s.push_back('l');
        }
        if(root -> right){
            s.push_back('s');
            dfs(root -> right);
            s.push_back('r');
        }
    };
    dfs(root);
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    TreeNode<int> *cur = NULL;
    stack<TreeNode<int>*> st;
    for(char ch : serialized){
        if(ch == 's'){
            st.push(cur);
            cur = NULL;
        }
        else if(ch == 'l'){
            st.top() -> left = cur;
            cur = st.top();
            st.pop();
        }
        else if(ch == 'r'){
            st.top() -> right = cur;
            cur = st.top();
            st.pop();
        }
        else{
            if(cur == NULL){
                cur = new TreeNode<int>(0);
            }
            cur -> data *= 10;
            cur -> data += (ch - '0');
        }
    }
    return cur;
}




