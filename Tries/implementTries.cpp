#include<bits/stdc++.h>
using namespace std;

struct Node{
     Node* links[26];
     bool flag  = false;
     bool containsKey(char ch){
          return (links[ch - 'a'] != NULL);
     }

     void put(char ch, Node * node){
          links[ch - 'a'] = node;
     }

     Node* get(char ch){
          return links[ch - 'a'];
     }

    //  bool setEnd(){
    //      flag = true;
    //  }


     void setEnd(){
    flag = true;
}

     bool isEnd(){
         return flag;
     }
};


class Trie
{

    private : Node* root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
           root = new Node();
    }

    /** Inserts a word into the trie. */

    //  TC - O(len)
    void insert(string word)
    {
         Node * node = root;
         for(int i = 0; i < word.length(); i++){
              if(!node->containsKey(word[i])){
                  node->put(word[i], new Node());
              }

            //   moves to the reference trie
            // node->get(word[i]);
            node = node->get(word[i]);

         }

         node->setEnd();
    }

    /** Returns if the word is in the trie. */

    //  TC - O(len)
    bool search(string word)
    {
        Node * node = root;
        for(int i = 0; i < word.length(); i++){
               if(!node->containsKey(word[i])){
                  return false;
               }

               node = node->get(word[i]);
        }

        return node->isEnd();

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */

    //  TC - O(len)

    bool startsWith(string prefix)
    {
         Node * node = root;
         for(int i = 0; i < prefix.length(); i++){
             if(!node->containsKey(prefix[i])){
                 return false;
             }

             node = node->get(prefix[i]);
         }
         return true;
    }
};

int main(){
       Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    // Search test
    cout << trie.search("apple") << endl;   // 1
    cout << trie.search("app") << endl;     // 1
    cout << trie.search("appl") << endl;    // 0
    cout << trie.search("bat") << endl;     // 1
    cout << trie.search("ba") << endl;      // 0

    // Prefix test
    cout << trie.startsWith("app") << endl; // 1
    cout << trie.startsWith("bal") << endl; // 1
    cout << trie.startsWith("cat") << endl; // 0

    return 0;
}