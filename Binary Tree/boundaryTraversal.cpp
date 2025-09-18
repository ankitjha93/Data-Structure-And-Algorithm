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


  bool isLeaf(TreeNode* TreeTreeNode) {
    return (TreeTreeNode->left == NULL && TreeTreeNode->right == NULL);
}

  void addLeftBoundary(TreeNode* root, vector<int> &res){
     TreeNode* cur = root->left;
     while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
     }
  }

  void addRightBoundary(TreeNode* root, vector<int> &res){
     TreeNode* cur = root->right;
     vector<int> tmp;

     while(cur){
        if(!isLeaf(cur)) tmp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
     }

     for(int i = tmp.size() - 1; i >= 0; --i){
         res.push_back(tmp[i]);
     }
  }

  void addLeaves(TreeNode* root, vector<int> &res){
      if(isLeaf(root)){
        res.push_back(root->data);
        return;
      }
      if(root->left) addLeaves(root->left, res);
      if(root->right) addLeaves(root->right, res);
  }
    vector<int> boundaryTraversal(TreeNode* root) {
        // code here
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
        
    }
};

int main(){

 TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> ans = sol.boundaryTraversal(root);

    cout << "Boundary Traversal:\n";
    for(auto level : ans){
        
        cout<<level<<" ";
    }

    return 0;


}

// TC - O(H) + O(H) + O(N) which is equal to O(N)
// SC - O(N) at the worst case