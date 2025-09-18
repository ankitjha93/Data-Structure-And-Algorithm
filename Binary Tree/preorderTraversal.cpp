/*#include<bits/stdc++.h>
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

    void dfs(TreeNode* root, vector<int> &result){
        if(root == NULL) return;

      result.push_back(root->data);
      dfs(root->left, result);
      dfs(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};


int main(){

     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.preorderTraversal(root);

    cout << "PreOrder Traversal : ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
  }


// TC - O(N)
// SC - O(N)*/


// iterative approach

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

    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> preorder;
         if(root == NULL) return preorder;

         stack<TreeNode*> st;
         st.push(root);
         while (!st.empty())
         {
          root = st.top();
          st.pop();
          preorder.push_back(root->data);
          if(root->right != NULL){
            st.push(root->right);
          }
          if(root->left != NULL){
            st.push(root->left);
          }
         }
         return preorder;
    }
};


int main(){

     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.preorderTraversal(root);

    cout << "PreOrder Traversal : ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
  }


// TC - O(N)
// SC - O(H)
