#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for (int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assume word will be in capital letter
        int index = word[0] - 'A';
        TrieNode *child;

        if(root -> children[index] != NULL){
          // the char is present
          child = root->children[index];
        }else{
            // the char isn't present and we have to create one.
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insert(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word){
        // base case
        if (word.length() == 0) {
          return root->isTerminal;
        }

        // assume word will be in capital letter
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL) {
          // the char is present
          child = root->children[index];
        } else {
          // the char isn't present and we should return false.
          return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root, word);
    }
};

int main(){
    Trie *t = new Trie();

    t->insert("TIME");
    t->insert("IS");
    t->insert("PRECIOUS");

    if (t->search("IS")) {
      cout << "The word is present" << endl;
    } else {
      cout << "The word isn't present" << endl;
    }

    return 0;
}