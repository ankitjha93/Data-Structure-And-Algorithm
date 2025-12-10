#include<bits/stdc++.h>
using namespace std;

struct  Node
{
    /* data */
    Node* links[26];
    bool containKey(char ch){
         return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
         links[ch-'a'] = node;
    }

    Node * get(char ch){
         return links[ch - 'a'];
    }
};


int countDistinctSubstrings(string &word)
{
    //    Write your code here.
     int cnt = 0;
    Node * root = new Node();
    for(int i = 0; i < word.size(); i++){
          Node* node = root;
          for(int j = i;  j < word.size(); j++){
              if(!node->containKey(word[j])){
                 cnt++;
                 node->put(word[j], new Node());
              }

              node = node->get(word[j]);
          }
    }

    return cnt + 1 ;
}

int main(){
      
      
     string s = "ababa";
    cout << countDistinctSubstrings(s) << endl;
    

}

// TC -  O(n^2)
// SC - O(n^2)