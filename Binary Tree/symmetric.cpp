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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }

    bool isSymmetricHelp(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }

        if(left->data != right->data) return false;

        return isSymmetricHelp(left->left, right->right)
             && isSymmetricHelp(left->right, right->left);
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

    bool ans = sol.isSymmetric(root);
  
    cout<<ans;
}

// TC - O(N)
// SC - O(N)