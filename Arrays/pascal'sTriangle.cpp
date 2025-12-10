#include<bits/stdc++.h>
using namespace std;


// variation 1


// given r & c , tel the element at that place  r = 5, c = 3;

// int NcR(n, r){
//      int res = 1;
//      for(int i = 0; i < r; i++){
//          res = res * (n-i);
//          res = res/ (i+1);
//      }
//      return res;
// }

// int PasCal(){
//      return NcR(r-1, c-1);
// }

// TC - O(r)
// SC - O(1)


// variation 2


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
       vector<int> row(rowIndex + 1);
        long long ans = 1;
        row[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            ans = ans * (rowIndex - i + 1) / i;
            row[i] = ans;
        }

        return row;
    }
};



int main(){
      Solution s;
    int rowIndex;
    cin >> rowIndex;

    vector<int> ans = s.getRow(rowIndex);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

// TC - O(n)
// SC - O(1)


// variation 3 (IMP)

    class Solution {
        
         vector<int> generateRow(int row) {
        
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1; col < row; col++){
             ans = ans * (row - col);
             ans = ans / (col);
             ansRow.push_back(ans);
        }
        return ansRow;
    }
        
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
              ans.push_back(generateRow(i));
        }
        return ans;
    }
};


int main(){
      Solution s;
    int numRows;
    cin >> numRows;

    vector<vector<int>> result = s.generate(numRows);

    for (auto &row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
    
}

// TC - O(n * n) ~ O(n^2)
// SC - O(n^2)
