/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {

class Node{
    public:
    Node* children[26];
    bool isEnd = false;
};
public:

    /** Initialize your data structure here. */
    Node *root;
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * cur = root;
        for(char ch : word){
            if(cur -> children[ch - 'a'] == NULL){
                cur -> children[ch - 'a'] = new Node();
            }
            cur = cur -> children[ch - 'a'];
        }
        cur -> isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * cur = root;
        for(char ch : word){
            cur = cur -> children[ch - 'a'];
            if(cur == NULL){
                return false;
            }
        }
        return cur -> isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * cur = root;
        for(char ch : prefix){
            cur = cur -> children[ch - 'a'];
            if(cur == NULL){
                return false;
            }
        }
        return true;
    }
};
