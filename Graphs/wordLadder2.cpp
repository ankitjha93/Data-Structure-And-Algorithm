#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;

          q.push({beginWord}); 
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()){
             vector<string> vec = q.front();
             q.pop();

            //  erase all words that has been used in the previous levels to transform
            if(vec.size() > level){
                 level++;
                 for(auto it : usedOnLevel){
                     st.erase(it);
                 }
                 usedOnLevel.clear();
            }

            string word = vec.back();
            // store the answers
            if(word == endWord){
                // the first sequence where we reached end
                if(ans.size() == 0){
                     ans.push_back(vec);
                }else if(ans[0].size() == vec.size()){
                     ans.push_back(vec);
                }
            }

            for(int i = 0; i < word.size(); i++){
                 char original = word[i];
                 for(char c = 'a'; c <= 'z'; c++){
                     word[i] = c;
                     if(st.count(word) > 0){
                         vec.push_back(word);
                                q.push(vec);  
                                
                                // mark as visited on the level
                                usedOnLevel.push_back(word);
                                vec.pop_back();
                        }
                 }
                 word[i] = original;
            }
        }
        return ans;
    }
};

int main() {
       string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution obj;
    vector<vector<string>> sequences = obj.findSequences(startWord, targetWord, wordList);

    cout << "All shortest transformation sequences:\n";
    for(auto &seq : sequences){
        for(auto &word : seq){
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC - N*wordLenght*26 * logN --- logN because of set
// SC - O(N)