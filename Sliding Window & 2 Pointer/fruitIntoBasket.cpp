#include<bits/stdc++.h>
using namespace std;

int fruitIntoBasket(vector<int> &arr){
     int n = arr.size();
     int maxLen = 0;

     for(int i = 0; i < n; i++){
        set<int> st;
        for(int j = i; j < n;j++){
            st.insert(arr[j]);
            if(st.size() <= 2){
                int len = j-i+1;
                maxLen = max(maxLen,len);
            }else{
                break;
            }
        }
        
     }

     return maxLen;
    
    

    
}
     
int main(){
   vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
  
   
   int ans = fruitIntoBasket(arr);
   cout<<"length of  the longest subArray is :"<<ans<<endl;

}

// TC = O(N^2)
// SC = O(3)