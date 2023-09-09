struct Node{
    int num = 0;
    Node* children[26];
};
void insert(string s, Node *root){
    for(char ch : s){
        if(root -> children[ch - 'a'] == NULL){
            root -> children[ch - 'a'] = new Node();
        }
        root = root -> children[ch - 'a'];
    }
    root -> num = 1;
}
int numStrings(Node *root){
    if(!root){
        return 0;
    }
    int ans = root -> num;
    for(int i = 0; i < 26; ++i){
        ans += numStrings(root -> children[i]);
    }
    return ans;
}
int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int n = s.size();
    insert("", root);
    for(int l = 0; l < n; ++l){
        for(int r = l; r < n; ++r){
            string sub;
            for(int i = l; i <= r; ++i){
                sub.push_back(s[i]);
            }
            insert(sub, root);
        }
    }
    return numStrings(root);
}
