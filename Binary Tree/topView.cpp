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
    // Function to return a list of TreeNodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(TreeNode* root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mpp;

        queue<pair<TreeNode*,int>>  q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* TreeNode = it.first;

            int line = it.second;

            if(mpp.find(line) == mpp.end()) mpp[line] = TreeNode->data;

            if(TreeNode->left != NULL){
                q.push({TreeNode->left, line - 1});
            }
            if(TreeNode->right != NULL){
                q.push({TreeNode->right, line + 1});
            }
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);
    root->right->left = new TreeNode(90);
    root->right->right = new TreeNode(100);

    Solution sol;

    vector<int> ans = sol.topView(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
}

// TC - O(N)
// SC - O(N) 