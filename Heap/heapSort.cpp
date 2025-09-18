 #include<bits/stdc++.h>
 using namespace std;

 class Solution{
 
   public :

 void heapifyDown(vector<int> &nums,int ind){
        int n = nums.size();
         int smallest = ind;
         int lChild = 2 * ind + 1;
         int rChild = 2 * ind + 2;

         if(lChild < n && nums[lChild] > nums[smallest]){
            smallest = lChild;
         }

        if(rChild < n && nums[rChild] > nums[smallest]){

            smallest = rChild;
        }

            if(smallest != ind){
                swap(nums[ind], nums[smallest]);
                heapifyDown(nums, smallest);
            }
      }


    void buildMaxHeap(vector<int> &nums) {
         int n = nums.size();
         for(int i = n/2 - 1; i >= 0; i--){
            heapifyDown(nums, i);
         }
    }

    void heapify(vector<int> &nums, int last, int ind){
        // int n = nums.size();
        int lChild = 2 * ind + 1;
        int rChild = 2 * ind + 2;
          int largest = ind;

          if(lChild <= last && nums[lChild] > nums[largest]) largest = lChild;
          if(rChild <= last && nums[rChild] > nums[largest]) largest = rChild;

           if(largest != ind){
             swap(nums[ind], nums[largest]);
             heapify(nums, last, largest);
           }
    }

    vector<int> heapSort(vector<int>&nums) {
         buildMaxHeap(nums);
         int last = nums.size() - 1;
         while(last > 0){
            swap(nums[0], nums[last]);
            last = last - 1;
            heapify(nums, last, 0);
         }
        
         
         return nums;
    }


};

int main(){
    Solution sol;
   vector<int> v = {7, 4, 1, 5, 3};

   vector<int> res = sol.heapSort(v);
    for(auto x : res){
        cout<<x<<" ";
    }

      
}

// TC - O(NlogN)
// SC - O(1)