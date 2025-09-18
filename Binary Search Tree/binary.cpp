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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->data != val){
            root = val < root->data ? root->left : root->right;
        }
        return root;
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
    int val = 2;
    TreeNode* result = sol.searchBST(root, val);

    if(result != nullptr) {
        cout << "Subtree rooted at node " << val << " (Inorder Traversal): ";
        printInorder(result);
        cout << endl;
    } else {
        cout << "Value " << val << " not found in the BST." << endl;
    }

    return 0;
}
// TC - O(logN) 
// SC - O(1)