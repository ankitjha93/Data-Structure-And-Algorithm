/*#include<bits/stdc++.h>
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


 void inorder(TreeNode* root, int &cnt){
     if(!root) return;
     cnt++;
     inorder(root->left, cnt);
     inorder(root->right, cnt);
 }
    int countNodes(TreeNode* root) {

         int cnt= 0;
         inorder(root,cnt);
         return cnt;
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

int ans = sol.countNodes(root);
   
cout<<ans;
    return 0;
}*/

// TC - O(N)
// SC - O(H) ----- Height of the tree


// Optimal Solution


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

    int countNodes(TreeNode* root) { 
          if(root == NULL) return 0;
          int lh = findHeightLeft(root);
          int rh = findHeightRight(root);

          if(lh == rh) return (1<<lh) - 1;
          
          return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findHeightLeft(TreeNode* node){
         int hght = 0;
         while(node){
            hght++;
            node = node->left;
         }
         return hght;
    }

    int findHeightRight(TreeNode* node){
               int hght = 0;
               while(node){
                hght++;
                node = node->right;

               }
               return hght;
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

int ans = sol.countNodes(root);
   
cout<<ans;
    return 0;
}

// TC - O(logN^2)
// SC - O(logN)
