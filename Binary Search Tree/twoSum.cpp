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
    // reverse ->true -> before
    // reverse -> false -> next;

    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

    private : 

       void pushAll(TreeNode* node){
         for(; node != NULL;){
             myStack.push(node);
             if(reverse == true){
                node = node->right;
             }else{
                node = node->left;
             }
       }
}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        // next
        BSTIterator l (root, false);
        // before
        BSTIterator r (root, true);

        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            /* code */
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
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

    // Use Solution to check for target sum
    Solution solution;
    int target = 40;

    if(solution.findTarget(root, target)) {
        cout << "Target " << target << " found in BST!" << endl;
    } else {
        cout << "Target " << target << " not found in BST." << endl;
    }

    return 0;
}

// TC - O(N)
// SC - O(H) * 2   --- next and before