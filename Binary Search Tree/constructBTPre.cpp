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
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int> &A, int &i, int bound){
         if(i == A.size() || A[i] > bound) return NULL;
         TreeNode* root = new TreeNode(A[i++]);
         root->left = build(A, i, root->data);
         root->right = build(A, i, bound);
         return root;
    }
};

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if(root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
      // Build BST
       Solution sol;

    // Example preorder traversal
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    
    // Build BST from preorder
    TreeNode* root = sol.bstFromPreorder(preorder);

    // Print inorder traversal to confirm the tree is built correctly
    cout << "Inorder traversal of the BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}

// TC - O(3N) --- which is equal to O(N) 
// SC - O(1)