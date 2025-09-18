/*#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
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

   void heapifyUp(vector<int> & nums, int ind){
      int n = nums.size();
  int parent = (ind - 1) / 2;


     if(ind > 0){
        if(nums[ind] > nums[parent]){
            swap(nums[ind], nums[parent]);
            heapifyUp(nums, parent);
        }
     }
   }

    void heapify(vector<int> &nums, int ind, int val) {
         if(nums[ind] < val){
            nums[ind] = val;
            heapifyUp(nums, ind);
         }else{
            nums[ind] = val;
            heapifyDown(nums, ind);
         }
    }
};



int main(){
   Solution sol;

    // Example max heap
    vector<int> heap = {1,4,5, 5 ,7, 6};

    cout << "Original heap: ";
    for (int num : heap) cout << num << " ";
    cout << endl;

    sol.heapify(heap, 5,2); // Update index 3 to value 60

    cout << "After update: ";
    for (int num : heap) cout << num << " ";
    cout << endl;

    return 0;
}*/

// min Heap


#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
      void heapifyDown(vector<int> &nums,int ind){
        int n = nums.size();
         int smallest = ind;
         int lChild = 2 * ind + 1;
         int rChild = 2 * ind + 2;

         if(lChild < n && nums[lChild] < nums[smallest]){
            smallest = lChild;
         }

        if(rChild < n && nums[rChild] < nums[smallest]){

            smallest = rChild;
        }

            if(smallest != ind){
                swap(nums[ind], nums[smallest]);
                heapifyDown(nums, smallest);
            }
      }

   void heapifyUp(vector<int> & nums, int ind){
      int n = nums.size();
  int parent = (ind - 1) / 2;


     if(ind > 0){
        if(nums[ind] < nums[parent]){
            swap(nums[ind], nums[parent]);
            heapifyUp(nums, parent);
        }
     }
   }

    void heapify(vector<int> &nums, int ind, int val) {
         if(nums[ind] > val){
            nums[ind] = val;
            heapifyUp(nums, ind);
         }else{
            nums[ind] = val;
            heapifyDown(nums, ind);
         }
    }
};



int main(){
   Solution sol;

    // Example max heap
    vector<int> heap = {1,4,5, 5 ,7, 6};

    cout << "Original heap: ";
    for (int num : heap) cout << num << " ";
    cout << endl;

    sol.heapify(heap, 5,2); // Update index 3 to value 60

    cout << "After update: ";
    for (int num : heap) cout << num << " ";
    cout << endl;

    return 0;
}


// TC - O(logN)
// SC - O(1)