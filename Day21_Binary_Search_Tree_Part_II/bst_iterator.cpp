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

class BSTiterator
{
    public:
    stack<TreeNode<int>*> st;
    TreeNode<int>* cur;
    BSTiterator(TreeNode<int> *root)
    {
        while(root != NULL){
            st.push(root);
            root = root -> left;
        }
    }

    int next()
    {
        int ans = (st.top() -> data);
        TreeNode<int> *next = st.top() -> right;
        st.pop();
        while(next != NULL){
            st.push(next);
            next = next -> left;
        }
        return ans;
    }

    bool hasNext()
    {
        return (st.size() > 0);
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
