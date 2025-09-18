
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
   public:
    vector<int> nums;  // heap array
    int cnt = 0;

    // Heapify down (min heap)
    void heapifyDown(vector<int> &nums, int ind) {
        int n = nums.size();
        int smallest = ind;
        int lChild = 2 * ind + 1;
        int rChild = 2 * ind + 2;

        if (lChild < n && nums[lChild] > nums[smallest]) {
            smallest = lChild;
        }
        if (rChild < n && nums[rChild] > nums[smallest]) {
            smallest = rChild;
        }

        if (smallest != ind) {
            swap(nums[ind], nums[smallest]);
            heapifyDown(nums, smallest);
        }
    }

    // Heapify up
    void heapifyUp(vector<int> & nums, int ind) {
        int parent = (ind - 1) / 2;

        if (ind > 0 && nums[ind] > nums[parent]) {
            swap(nums[ind], nums[parent]);
            heapifyUp(nums, parent);
        }
    }

    void initializeHeap() {
        nums.clear();
        cnt = 0;
    }

    void insert(int key) {
        nums.push_back(key);
        heapifyUp(nums,cnt);
        cnt = cnt + 1;
    }

    void changeKey(int index, int new_val) {
        
        if(nums[index] > new_val){
            nums[index] = new_val;

            heapifyUp(nums, index);
        }else{
            nums[index] = new_val;
            heapifyDown(nums, index);
        }
    }

    void extractMax() {
        int el = nums[0];
        swap(nums[0], nums[cnt - 1]);
        nums.pop_back();
        heapifyDown(nums,0);
        cnt = cnt - 1;
    }

    bool isEmpty() { return cnt == 0; }

    int getMin() { return nums[0]; }

    int heapSize() { return cnt; }
};


int main(){
    Solution heap;

    heap.initializeHeap();

    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);

    cout << "Max element: " << heap.getMin() << endl;

    // cout << "Extracted min: " << heap.extractMin() << endl;
    cout << "New max: " << heap.getMin() << endl;

    heap.changeKey(2, 1);
    cout << "Max after changeKey: " << heap.getMin() << endl;

    cout << "Heap elements: ";
    for (int x : heap.nums) cout << x << " ";
    cout << endl;

    return 0;


}