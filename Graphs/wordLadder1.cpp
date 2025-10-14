#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        set<string> st(wordList.begin(), wordList.end());

        st.erase(startWord);

        while (!q.empty())
        {
            /* code */
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == targetWord) return steps;
            // word = hat

            for(int i = 0; i < word.size(); i++){
                 char original = word[i];
                  for(char ch = 'a'; ch <= 'z'; ch++){
                     word[i] = ch;
                    //  it exists in the set
                    if(st.find(word) != st.end()){
                         st.erase(word);
                         q.push({word, steps + 1});
                    }
                  }
                  word[i] =  original;
            }
        }

        return 0;
        

    }
};

int main() {
       string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution obj;
    cout << "Word Ladder Length = " 
         << obj.wordLadderLength(startWord, targetWord, wordList) << endl;

    return 0;
}


 
// TC - N*wordLenght*26 * logN --- logN because of set
// SC - O(N)