#include<bits/stdc++.h>
using namespace std;


  int largestRectangleArea(vector<int>& heights) {

        // Stack to store indices of histogram bars
        stack<int> st;

        // Variable to store the max area
        int maxArea = 0;

        // Add a sentinel zero height at the end
        heights.push_back(0);

        // Iterate through all bars
        for (int i = 0; i < heights.size(); i++) {

            // While current bar is smaller than the bar at stack top
            while (!st.empty() && heights[i] < heights[st.top()]) {

                // Pop the top height
                int height = heights[st.top()];
                st.pop();

                // Calculate width
                int width = st.empty() ? i : i - st.top() - 1;

                // Update max area
                maxArea = max(maxArea, height * width);
            }

            // Push current index
            st.push(i);
        }

        return maxArea;
    }


int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
    int maxArea = 0;
    vector<int> height(m, 0);
    for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
              if(mat[i][j] == 1) height[j]++;
              else height[j] = 0;
         }
         int area = largestRectangleArea(height);
         maxArea = max(area, maxArea);
    }
    return maxArea;

}

int main(){
    
     int n = 4, m = 5;

    vector<vector<int>> mat = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1}
    };

    cout << maximalAreaOfSubMatrixOfAll1(mat, n, m) << "\n";

    return 0;
    
    
}


// TC - O(n * (m+n))
// SC - O(n)
