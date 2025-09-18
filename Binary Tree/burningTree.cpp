#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int data;
    TreeNode * left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
     
};

class Solution {
  public:

   int findMaxDistance( map<TreeNode*, TreeNode*> &mpp, TreeNode* target){
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,int> vis;
        vis[target] = 1;
        int maxi = 0;
        while(!q.empty()){
             int size = q.size();
             int fl = 0;
             for(int i = 0; i < size; i++){
                  auto node = q.front();
                  q.pop();
                  if(node->left && !vis[node->left]){
                     fl = 1;
                     vis[node->left] = 1;
                     q.push(node->left);
                  }

                    if(node->right && !vis[node->right]){
                     fl = 1;
                     vis[node->right] = 1;
                     q.push(node->right);
                  }

                  if(mpp[node] && !vis[mpp[node]]){
                     fl = 1;
                     vis[mpp[node]] = 1;
                     q.push(mpp[node]);
                  }
             }
             if(fl) maxi++;
        }
        return maxi;
   }

  TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*> &mpp, int start){
            queue<TreeNode*> q;
             q.push(root);
             TreeNode * res;

             while(!q.empty()){
                 TreeNode* node = q.front();
                 if(node->data == start) res = node;
                 q.pop();
                  if(node->left){
                    mpp[node->left] = node;
                    q.push(node->left);
                  }

                  if(node->right){
                    mpp[node->right] = node;
                    q.push(node->right);
                  }
             }
             return res;
  }


    int minTime(TreeNode* root, int start) {
        // code here
           map<TreeNode*, TreeNode*> mpp;
           TreeNode* target = bfsToMapParents(root, mpp, start);
           int maxi = findMaxDistance(mpp, target);
           return maxi;
        
    }
};

int main(){
  TreeNode* root = new TreeNode(35);
    root->left = new TreeNode(20);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

  
    Solution sol;


   
    int start = 20;

int ans = sol.minTime(root, start);
   
cout<<ans;
    return 0;
}

// TC - O(N)
// SC - O(N) 