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

 int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);


        if(abs(rh - lh) > 1) return false;


        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;
        return true;
    }
};

int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << (sol.isBalanced(root) ? "True" : "False");

    return 0;
}

// TC - O(N^2)
// SC - O(N) at the worst case*/

// Optimal Solution

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




    bool isBalanced(TreeNode* root) {
      return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = dfsHeight(root->left);
        if(leftHeight == - 1) return -1;
        int rightHeight = dfsHeight(root->right);
        if(rightHeight == - 1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
    
};

int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << (sol.isBalanced(root) ? "True" : "False");

    return 0;
}

// TC - O(N)
// SC - O(N) at the worst case

