/*#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
     int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
         this->k = k;
         this->nums = nums;
         
    }
    
    int add(int val) {  
        nums.push_back(val);
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

int main(){
 
    
   vector<int> arr = {4, 5, 8, 2};
    KthLargest obj(3, arr);

    cout << obj.add(3) << endl;  // after adding 3 → 4,5,8 → 4
    cout << obj.add(5) << endl;  // after adding 5 → 5,5,8 → 5
    cout << obj.add(10) << endl; // after adding 10 → 5,8,10 → 8
    cout << obj.add(9) << endl;  // after adding 9 → 8,9,10 → 9
    cout << obj.add(4) << endl;  // after adding 4 → 8,9,10 → 8
}

// TC : O(NlogN)
// SC : O(N)*/


// Optimal


#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
     int k;
    vector<int> nums;

    priority_queue<int, vector<int>, greater<int>> pq;  //minHeap
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;    //O(N * logk)

        for(int i = 0;i < nums.size(); i++){
            if(pq.size() < k) pq.push(nums[i]);
            else if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {   //O(logk)
        
          if (pq.size() < k) {  // ✅ handle case when heap not full yet
            pq.push(val);
        } 
        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

int main(){
 
    
   vector<int> arr = {4, 5, 8, 2};
    KthLargest obj(3, arr);

    cout << obj.add(3) << endl;  // after adding 3 → 4,5,8 → 4
    cout << obj.add(5) << endl;  // after adding 5 → 5,5,8 → 5
    cout << obj.add(10) << endl; // after adding 10 → 5,8,10 → 8
    cout << obj.add(9) << endl;  // after adding 9 → 8,9,10 → 9
    cout << obj.add(4) << endl;  // after adding 4 → 8,9,10 → 8
}

// TC : O(N*logK) + O(logk)
// SC : O(k)


