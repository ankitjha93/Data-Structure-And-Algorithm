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

class BSTIterator {
    stack<TreeNode* > myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->data;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

    private : 

       void pushAll(TreeNode* node){
         for(; node != NULL; myStack.push(node), node = node->left);
       }
};

// Example usage
int main() {
      // Build BST
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Use BSTIterator to traverse the tree in-order
    BSTIterator it(root);

    cout << "In-order traversal of BST:" << endl;
    while(it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}

// TC - O(H) ---- Height of the tree 
// SC - O(1)