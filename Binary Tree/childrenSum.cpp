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
    int isSumProperty(TreeNode *root) {
        if (!root || (!root->left && !root->right)) return 1; // leaf or null is valid

        int child = 0;
        if (root->left) child += root->left->data;
        if (root->right) child += root->right->data;

        if (root->data != child) return 0;

        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};


/*class Solution {
  public:
    void changeTree(TreeNode *root) {
        // code here
        if(!root) return;
        int child = 0;
        if(root->left){
            child += root->left->data;
        }
        if(root->right){
            child += root->right->data;
        }

        if(child >= root->data) root->data = child;
        else{
            if(root->left) root->left->data = root->data;
            else if(root->right) root->right->data = root->data;
        }
        
        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;

        if(root->left) tot += root->left->data;
        if(root->right) tot += root->right->data;
        if(root->left or root->right) root->data = tot;
        
    }
};*/

int main(){
  TreeNode* root = new TreeNode(35);
    root->left = new TreeNode(20);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

  
    Solution sol;

    int ans = sol.isSumProperty(root);
    cout<<ans;
    return 0;
}

// TC - O(N)
// SC - O(H) ---- height of the tree , which boils down to O(N)