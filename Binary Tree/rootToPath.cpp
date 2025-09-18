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


   bool getPath(TreeNode* root, vector<int> &arr, int x){
      if(!root){
        return false;
      }

      arr.push_back(root->data);

      if(root->data == x){
        return true;
      }

      if(getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;

        arr.pop_back();
        return false;
    }

    vector<int>Paths(TreeNode* A, int B) {
        // code here
      vector<int> arr;
      if(A == NULL) return arr;

      getPath(A, arr,B );
      return arr;
        
    }
};

int main(){
  TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;

    int target = 4;  // Example: find path to node with value 4
    vector<int> ans = sol.Paths(root, target);  // ✅ pass target here
  
    for(auto x : ans){
        cout << x << " ";
    }

    return 0;
}

// TC - O(N)
// SC - O(H) ---- Height of the tree



/*

Compiler Version

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Helper recursive function
    void getPaths(Node* root, vector<int> &current, vector<vector<int>> &ans) {
        if (!root) return;

        current.push_back(root->data);

        // If it's a leaf node, save the path
        if (!root->left && !root->right) {
            ans.push_back(current);
        } else {
            getPaths(root->left, current, ans);
            getPaths(root->right, current, ans);
        }

        // Backtrack (remove last element before returning to previous call)
        current.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> current;
        getPaths(root, current, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> result = sol.Paths(root);

    cout << "All root-to-leaf paths:\n";
    for (auto path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}



*/