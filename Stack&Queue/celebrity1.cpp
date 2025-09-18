#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        vector<int> knowMe (n,0);
        vector<int> iKnow (n,0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }

        for(int i = 0 ; i < n; i++){
            if(knowMe[i] == n-1 && iKnow[i] == 0){
                return i;
            }
        }

        return -1;
        
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