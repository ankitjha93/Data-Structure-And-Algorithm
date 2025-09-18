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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};

int main(){

     TreeNode* root = new TreeNode(3);
     root->left = new TreeNode(9);
     root->right = new TreeNode(20);
     root->right->left = new TreeNode(15);
     root->right->right = new TreeNode(7);

     Solution sol;

     int ans = sol.maxDepth(root);
     cout<<ans;


}

// TC - O(N)
// SC - O(N) at the worst case