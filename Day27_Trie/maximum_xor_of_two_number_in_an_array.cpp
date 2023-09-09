struct Node{
    bool isEnd = false;
    Node *children[26];
};
void insert(int num, Node *root){
    for(int k = 30; k >= 0; --k){
        int ch = (1 & (num >> k));
        if(root -> children[ch] == NULL){
            root -> children[ch] = new Node();
        }
        root = root -> children[ch];
    }
}
int getMaxXor(int x, Node *root){
    int ans = 0;
    for(int k = 30; k >= 0; --k){
        int ch = (1 & (x >> k));
        ch = (1 - ch);
        if(root -> children[ch]){
            ans ^= (1 << k);
        }else{
            ch = (1 - ch);
        }
        root = root -> children[ch];
    }
    return ans;
}
int maximumXor(vector<int> A)
{
    Node *root = new Node();
    for(int a : A){
        insert(a, root);
    }
    int ans = 0;
    for(int a : A){
        ans = max(ans, getMaxXor(a, root));
    }
    return ans;
}
