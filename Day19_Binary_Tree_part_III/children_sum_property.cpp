/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
bool isLeaf(Node *node){
    return ((node -> left == NULL) && (node -> right == NULL));
}
bool isParentSum(Node *root){
    if(root == NULL){
        return true;
    }
    if(isLeaf(root)){
        return true;
    }
    int sum = 0;
    if(root -> left != NULL){
        sum += root -> left -> data;
    }
    if(root -> right != NULL){
        sum += root -> right -> data;
    }
    return ((root -> data == sum) && isParentSum(root -> left) && (isParentSum(root -> right)));
}
