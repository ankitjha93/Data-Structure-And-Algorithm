#include <bits/stdc++.h>

using namespace std;

class StockSpanner{
   public :
   vector<int> nums;
 StockSpanner() {
        nums = {};
    }
    
    int next(int price) {
        nums.push_back(price);
        int cnt = 1;
        for(int i = nums.size() - 2; i >= 0 ; i--){
             if(nums[i] <= price) cnt++;
             else break;
        }

        return cnt;
    }
    
};

int main()
{
  
     StockSpanner* obj = new StockSpanner();

    vector<int> prices = {100,80, 60,70,60,75,85};
    vector<int> res;

    for (int price : prices) {
        res.push_back(obj->next(price));
    }

    cout << "Stock Spanner Output: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
      return 0;
      
}
