#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :
    int celebrity(vector<vector<int> >& mat) {
        // code here
       
        
        int top = 0;
        int down = mat.size() - 1;
        while(top < down){
            if(mat[top][down] == 1){
                top++;
            }else{
                 down--;
            }
        }

      int candidate = top;

        // Step 2: Verify the candidate
        for (int i = 0; i < mat.size(); i++) {
            if (i == candidate) continue;
            // Candidate should not know anyone, and everyone should know candidate
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }

        return candidate;
    }
   
    
};

int main()
{
  
    
    Solution s;
    vector<vector<int>> mat = {
        {1,1,0},
        {0,1,0},
        {0,1,1}
    };

int res = s.celebrity(mat);

cout<<res<<endl;
    
      return 0;
      
}