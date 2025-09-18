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
    int countSmall = 0;
    int resultSmall = -1;
    
    int countLarge = 0;
    int resultLarge = -1;

    // Inorder traversal to find K-th smallest
    void inorder(TreeNode* root, int k) {
        if (!root) return;
        
        inorder(root->left, k);
        
        countSmall++;
        if (countSmall == k) {
            resultSmall = root->data;
            return;
        }
        
        inorder(root->right, k);
    }
    
    // Reverse inorder traversal to find K-th largest
    void reverseInorder(TreeNode* root, int k) {
        if (!root) return;
        
        reverseInorder(root->right, k);
        
        countLarge++;
        if (countLarge == k) {
            resultLarge = root->data;
            return;
        }
        
        reverseInorder(root->left, k);
    }
    
    vector<int> kLargesSmall(TreeNode* root, int k) {
        countSmall = 0;
        resultSmall = -1;
        inorder(root, k);  // Find k-th smallest
        
        countLarge = 0;
        resultLarge = -1;
        reverseInorder(root, k);  // Find k-th largest
        
        return {resultSmall, resultLarge};
    }
};


int main(){
       // Create BST manually
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;
    int k = 3;

    vector<int> result = sol.kLargesSmall(root, k);

    cout << "K-th Smallest element is: " << result[0] << endl;
    cout << "K-th Largest element is: " << result[1] << endl;

    return 0;
}