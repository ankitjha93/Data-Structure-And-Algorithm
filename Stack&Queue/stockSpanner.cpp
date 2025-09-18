#include <bits/stdc++.h>

using namespace std;

class StockSpanner{
   public :
   stack<pair<int, int>> st;
   int ind = -1;
 StockSpanner() {
        ind = -1;
         while(!st.empty()) st.pop();
    }
    
    int next(int val) {
        ind = ind + 1;
        while (!st.empty() && st.top().first <= val) {
            st.pop();
        }

        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({val, ind});
        return ans;
        
    }
    
};

int main()
{
  
     StockSpanner* obj = new StockSpanner();

    vector<int> val = {100,80, 60,70,60,75,85};
    vector<int> res;

    for (int price : val) {
        res.push_back(obj->next(price));
    }

    cout << "Stock Spanner Output: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
      return 0;
      
}
