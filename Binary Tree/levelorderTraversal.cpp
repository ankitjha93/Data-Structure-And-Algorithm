#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
     int data;
     TreeNode* left;
     TreeNode* right;

     TreeNode(int val){
        data = val;
        left = right = NULL;
     }
};

class Solution {
public:
  
 vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
         if(root == nullptr) return ans;
         queue<TreeNode*> q;
         q.push(root);
         while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                 TreeNode* node = q.front();
                 q.pop();
                 if(node->left != NULL) q.push(node->left);
                 if(node->right != NULL) q.push(node->right);
                 level.push_back(node->data);
            }
            ans.push_back(level);
         }
         return ans;


    }
};


int main(){
    // Solution sol;
TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<vector<int>> ans = sol.levelOrder(root);

    cout << "Level Order Traversal : ";
    for (auto level : ans) {
        for (auto x : level) {
            cout << x << " ";
        }
    }
    cout << endl;

    return 0;
  }


// TC - O(N)
// SC - O(N)