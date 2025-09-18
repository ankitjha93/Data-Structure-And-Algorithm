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
public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* predecessor = NULL;

        while (root != NULL) {
            if (p->data <= root->data) {
                // Move to left subtree if current node is >= p
                root = root->left;
            } else {
                // Current node is a potential predecessor
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* p = root->left; // Node with value 10

    Solution solution;
    TreeNode* pred = solution.inorderPredecessor(root, p);

    if (pred != NULL) {
        cout << "Inorder Predecessor of " << p->data << " is " << pred->data << endl;
    } else {
        cout << "Inorder Predecessor of " << p->data << " does not exist." << endl;
    }

    return 0;
}

// TC - O(H) ---- Height of the tree 
// SC - O(1)
