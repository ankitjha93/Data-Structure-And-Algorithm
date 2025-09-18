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

int count = 0;
int result = -1;


  void reverseInorder(TreeNode* root, int k) {
        if(root == nullptr) return;
        reverseInorder(root->right, k);
        count++;
        if(count == k) {
            result = root->data;
            return;
        }
        reverseInorder(root->left, k);
    }

    int kthLargest(TreeNode* root, int k) {
        count = 0;
        result = -1;
        reverseInorder(root, k);
        return result;
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
    int k = 3;  // Find the 3rd smallest element

    int result = sol.kthLargest(root, k);

    cout << "The " << k << "rd smallest element is: " << result << endl;

    cout << "Inorder traversal of the tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
// TC - O(logN) 
// SC - O(1)