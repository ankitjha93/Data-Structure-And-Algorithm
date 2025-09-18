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
  
 void postOrder(TreeNode* root , vector<int> &result){
     if(root == nullptr) return;

     postOrder(root->left, result);
     postOrder(root->right, result);
      result.push_back(root->data);
 }

   vector<int> postorderTraversal(TreeNode* root) {
         vector<int> result;
         postOrder(root, result);
         return result;
    }
};


int main(){

     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);

    cout << "PostOrder Traversal : ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
  }


// TC - O(N)
// SC - O(N)*/


// Iterative approach using 2 stack

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



   vector<int> postorderTraversal(TreeNode* root) {
      vector<int> postorder;
      if(root == NULL) return postorder;
      stack<TreeNode*> st1, st2;
      st1.push(root);

      while(!st1.empty()){
          root = st1.top();
          st1.pop();

          st2.push(root);

          if(root->left != NULL){
            st1.push(root->left);
          }

          if(root->right != NULL){
            st1.push(root->right);
          }

      }

      while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
      }
    return postorder;
    }
};


int main(){

     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);

    cout << "PostOrder Traversal : ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
  }


// TC - O(N)
// SC - O(2N)*/


// using 1 stack


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



   vector<int> postorderTraversal(TreeNode* root) {
    
       vector<int> postorder;
       if(root == NULL) return postorder;
       TreeNode * cur = root;
         TreeNode* temp = NULL;
       stack<TreeNode*> st;
       while(cur != NULL || !st.empty()){
        if(cur != NULL){
           st.push(cur);
           cur = cur->left;
        }
           else{  
//    TreeNode* temp = NULL;
            temp = st.top()->right;
            if(temp == NULL){
              temp = st.top();
               st.pop();
                postorder.push_back(temp->data);
                
                 while(!st.empty() && temp == st.top()->right){
                   temp = st.top(), st.pop();
                    postorder.push_back(temp->data);
                 }
            }else{
                       cur = temp;
                    }
            }
    
    }
    return postorder;
}
};


int main(){

     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);

    cout << "PostOrder Traversal : ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
  }

  // TC - O(2N)
// SC - O(N)