#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second)
     return p1.first < p2.first;

     return p1.second > p2.second;
}
// void printKFrequent(int arr[], int n, int k){
//     unordered_map<int, int> mpp;
//     for(int i = 0; i < n; i++){
//         mpp[arr[i]]++;
//     }
//     vector<pair<int,int>> v(mpp.begin(), mpp.end());

//     sort(v.begin(), v.end(), myCmp);

//     for(int i = 0; i < k; i++){
//        cout<<v[i].first<<" ";
//     }
// }    


// TC - O(nlogn)


struct myCmp{
   bool operator()(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
   }
};

// void printKFrequent(int arr[], int n, int k){
//     unordered_map<int, int> mpp;
//     for(int i = 0; i < n; i++){
//         mpp[arr[i]]++;
//     }
//   priority_queue<pair<int, int>, vector<pair<int,int>>

//    myCmp > pq(m.begin(), m.end());

//    for(int i = 0; i < k; i++){
//     cout<<pq.top().first;
//     pq.pop();
//    }

// }
    
// TC - O(nlogn)


/*k most Frequent in linear time */

void printKFrequent(int arr[], int n){
    unordered_map<int, int> mpp;

    for(int x : arr){
     mpp[x]++;
    }

}

    
    



int main(){

}