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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->data == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root != NULL){
            if(root->data > key){
                 if(root->left != NULL && root->left->data == key){
                    root->left = helper(root->left);
                    break;
                 } else{
                    root = root->left;
                 }
            }else{
                if(root->right != NULL && root->right->data == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
             return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
         if(root->right == NULL){
            return root;
         }
         return findLastRight(root->right);
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
    int key = 3;  // Change this to a node that exists to test deletion

    // Delete node with value 'key'
    root = sol.deleteNode(root, key);

    cout << "Inorder traversal after deleting " << key << ": ";
    printInorder(root);
    cout << endl;

    return 0;
}
// TC - O(logN) 
// SC - O(1)