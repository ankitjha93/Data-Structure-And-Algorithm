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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int cur = root->data;
        if(cur < p->data && cur < q->data){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(cur > p->data && cur > q->data){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};


int main(){
      // Build BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    TreeNode* p = root->left;        // Node with value 2
    TreeNode* q = root->left->right; // Node with value 3

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;

    return 0;
}

// TC - O(H) ---- Height of the tree 
// SC - O(1)