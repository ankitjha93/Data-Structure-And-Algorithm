#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node * links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;


    bool containsKey(char ch){
         return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
         return links[ch - 'a'];
    }

    void put(char ch, Node* node){
          links[ch - 'a'] = node;
    }

    void increaseEnd(){
         cntEndWith++;
    }

    void increasePrefix(){
          cntPrefix++;
    }

    void deleteEnd(){
          cntEndWith--;
    }

    void reducePrefix(){
          cntPrefix--;
    }

    int getEnd(){
         return cntEndWith;
    }
    
    int getPrefix(){
          return cntPrefix;
    }
};


class Trie{


      private : Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node * node = root;
        for(int i = 0; i < word.size(); i++){
              if(!node->containsKey(word[i])){
                  node->put(word[i], new Node());
              }

              node = node->get(word[i]);
              node->increasePrefix();
        }

        node->increaseEnd();

    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node * node = root;
        for(int i = 0; i < word.size(); i++){
              if(node->containsKey(word[i])){
                  node = node->get(word[i]);
              }else{
                  return 0;
              }

            //  return node->getEnd();

        }
         return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node * node = root;

        for(int i = 0; i < word.size(); i++){
               if(node->containsKey(word[i])){
                  node = node->get(word[i]);
               }
               else return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;

        for(int i  = 0; i < word.size(); i++){
                if(node->containsKey(word[i])){
                     node = node->get(word[i]);
                     node->reducePrefix();
                }else{
                     return;
                }
        }

        node->deleteEnd();
    }
};

int main(){
      
        Trie trie;

    string w1 = "apple";
    string w2 = "app";
    string w3 = "apple";

    // Insert words
    trie.insert(w1);
    trie.insert(w2);
    trie.insert(w3);

    // Count exact
    cout << trie.countWordsEqualTo(w1) << endl; // 2
    cout << trie.countWordsEqualTo(w2) << endl; // 1

    // Prefix count
    string p = "app";
    cout << trie.countWordsStartingWith(p) << endl; // 3

    // Erase one word
    trie.erase(w1);

    cout << trie.countWordsEqualTo(w1) << endl; // 1
    cout << trie.countWordsStartingWith(p) << endl; // 2

    return 0;

}

// TC - O(len)
// SC - O(n * len)