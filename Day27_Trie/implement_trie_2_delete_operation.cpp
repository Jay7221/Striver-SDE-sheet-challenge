#include <bits/stdc++.h> 

/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};*/

TrieNode* solution::deleteWord(TrieNode* root, string word) {
  TrieNode* prev = NULL;
  TrieNode* cur = root;
  for(char ch : word){
    if(cur -> children[ch - 'a'] == NULL){
      return root;
    }
    prev = cur;
    cur = (cur -> children[ch - 'a']);
  }
  if(prev != NULL){
    prev -> children[word.back() - 'a'] = NULL;
  }
  delete cur;
  return root;
}


