#include <bits/stdc++.h> 

using namespace std;

void heapify(vector<int> &arr, int n, int i){
   int smallest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;
   if(left < n && arr[smallest] > arr[left]){
    smallest = left;
   }
   if(right < n && arr[smallest] > arr[right]){
     smallest = right;
   }

   if(smallest != i){
    swap(arr[smallest], arr[i]);
    heapify(arr, n, smallest);
   }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    return arr;
}

int main(){
    
    vector<int> arr = {54, 53, 55, 52, 50};

    cout << "Original array:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    buildMinHeap(arr);

    cout << "Min Heap:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n";



    // priority queue implementation

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    cout << "Top: " << minHeap.top() << endl; // 5

    minHeap.pop(); // removes 5
    cout << "Top after pop: " << minHeap.top() << endl; // 10


    return 0;
}

// TC : O(N)