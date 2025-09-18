#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    private :

      TreeNode* first;
      TreeNode* prev;
      TreeNode* middle;
      TreeNode* last;


      private :

        void inorder(TreeNode* root){
            if(root == NULL) return;

            inorder(root->left);
            if(prev != NULL && (root->data < prev->data)){
                // if this is first violation, mark these two nodes as 
                // 'first' and 'middle'

                if(first == NULL){
                    first = prev;
                    middle = root;
                }
                // If this is second violation, mark this node as last
                else{
                    last = root;
                }
                // Mark this node as previous
            }
                prev = root;
                inorder(root->right);
            
        }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data, last->data);
        else if(first && middle) swap(first->data, middle->data);
    }
};

void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

// Example usage
int main() {
  // Build BST with swapped nodes
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(5);    // Suppose this should be 10
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(10); // Swapped with 5
    root->right->right = new TreeNode(25); // Swapped with 30

    cout << "In-order traversal before recovery:" << endl;
    inorderPrint(root);
    cout << endl;

    Solution solution;
    solution.recoverTree(root);

    cout << "In-order traversal after recovery:" << endl;
    inorderPrint(root);
    cout << endl;

    return 0;
}

// TC - O(N)
// SC - O(1)