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
    vector<int> succPredBST(TreeNode* root, int key) {
        TreeNode* predecessor = NULL;
        TreeNode* successor = NULL;
        TreeNode* node = root;

        // Find the node with value 'key' and mark potential predecessor and successor
        while (node != NULL) {
            if (key < node->data) {
                successor = node;
                node = node->left;
            } else if (key > node->data) {
                predecessor = node;
                node = node->right;
            } else {
                // Node with key found, find predecessor in left subtree
                if (node->left != NULL) {
                    TreeNode* tmp = node->left;
                    while (tmp->right != NULL) {
                        tmp = tmp->right;
                    }
                    predecessor = tmp;
                }
                // Find successor in right subtree
                if (node->right != NULL) {
                    TreeNode* tmp = node->right;
                    while (tmp->left != NULL) {
                        tmp = tmp->left;
                    }
                    successor = tmp;
                }
                break;
            }
        }

        int pred_val = (predecessor != NULL) ? predecessor->data : -1;
        int succ_val = (successor != NULL) ? successor->data : -1;

        return {pred_val, succ_val};
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    Solution solution;
    int key = 10;
    vector<int> result = solution.succPredBST(root, key);

    cout << "Predecessor of " << key << " is " << result[0] << endl;
    cout << "Successor of " << key << " is " << result[1] << endl;

    return 0;
}

// TC - O(H) ---- Height of the tree 
// SC - O(1)