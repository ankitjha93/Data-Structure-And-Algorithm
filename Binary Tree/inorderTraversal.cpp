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
  
 void inOrder(TreeNode* root , vector<int> &result){
     if(root == nullptr) return;
     inOrder(root->left, result);
     result.push_back(root->data);
     inOrder(root->right, result);
 }

   vector<int> inorderTraversal(TreeNode* root) {
         vector<int> result;
         inOrder(root, result);
         return result;
    }
};


int main(){

     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);

    cout << "PreOrder Traversal : ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
  }


// TC - O(N)
// SC - O(N)*/

// Iterative Approach

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
  


   vector<int> inorderTraversal(TreeNode* root) {
      
      stack<TreeNode*> st;
      TreeNode* node = root;
      vector<int> inorder;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;

        }
    }
    return inorder;
    }
};


int main(){

     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);

    cout << "PreOrder Traversal : ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
  }


// TC - O(N)
// SC - O(N) == O(H)



