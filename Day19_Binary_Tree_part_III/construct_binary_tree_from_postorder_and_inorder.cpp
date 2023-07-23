#include<bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     int n = postOrder.size();
     map<int, int> ind;
     for(int i = 0; i < n; ++i){
          ind[inOrder[i]] = i;
     }
     function<TreeNode<int>*(int, int, int, int)> construct;
     construct = [&](int postStart, int postEnd, int inStart, int inEnd){
          TreeNode<int> *root = NULL;
          if((postStart > postEnd) || (inStart > inEnd)){
               return root;
          }
          int rootData = postOrder[postEnd];
          root = new TreeNode<int>(rootData);
          int leftSize = ind[rootData] - inStart;
          root -> left = construct(postStart, postStart + leftSize - 1, inStart, inStart + leftSize - 1);
          root -> right = construct(postStart + leftSize, postEnd - 1, inStart + leftSize + 1, inEnd);
          return root;
     };
     return construct(0, n - 1, 0, n - 1);
}
