#include <bits/stdc++.h>

using namespace std;

class Solution {
    public :

     vector<int> sumTriangles(const vector<vector<int>> & mat){
         int n = mat.size();
         int upperSum = 0;
         int lowerSum = 0;
         for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j >= i) upperSum += mat[i][j];
                if(i >= j) lowerSum += mat[i][j];

            }
         }
         return {upperSum, lowerSum};
     }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{6,5,4},{1,2,5},{7,9,7}};
    vector<int> res = s.sumTriangles(mat);

    cout<<"Upper sumTriangles are :"<<res[0]<<endl;
    cout<<"Lower sumTriangles are :"<<res[1]<<endl;

    return 0;
}