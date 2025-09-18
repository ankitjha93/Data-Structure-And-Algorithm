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

class NodeValue{
    public:

      int maxNode, minNode, maxSize;

      NodeValue(int minNode, int maxNode, int maxSize){
         this->maxNode = maxNode;
         this->minNode = minNode;
         this->maxSize = maxSize;
      }
};


class Solution {

    private :

       NodeValue largestBSTSubtreeHelper(TreeNode* root){
        //   An empty tree is a BST of size 0

        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        // Get values from left and right subtree of current tree

        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right, it

        if(left.maxNode < root->data && root->data < right.minNode){
            // It is a BST
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }

        // otherwise, return [-inf, inf] so that parent can't be valid BST

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
       }
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(TreeNode *root) {
        // Your code here
        return largestBSTSubtreeHelper(root).maxSize;
        
    }
};

void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
   // Build a tree where some parts are BSTs
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);  // Not BST due to this node

    cout << "In-order traversal of the tree:" << endl;
    inorderPrint(root);
    cout << endl;

    Solution solution;
    int size = solution.largestBst(root);

    cout << "Size of largest BST in the tree: " << size << endl;

    return 0;
}

// TC - O(N)
// SC - O(1)