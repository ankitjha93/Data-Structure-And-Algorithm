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
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool validate(TreeNode* root, long long minVal, long long maxVal) {
        if(root == nullptr) return true;
        if(root->data <= minVal || root->data >= maxVal) return false;
        return validate(root->left, minVal, root->data) &&
               validate(root->right, root->data, maxVal);
    }
};

void printInorder(TreeNode* root) {
    if(root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
      TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    if(sol.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    cout << "Inorder traversal of the tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

// TC - O(N) 
// SC - O(1)