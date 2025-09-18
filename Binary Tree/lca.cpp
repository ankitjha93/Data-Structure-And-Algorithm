#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int data;
    TreeNode * left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
     
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //  base case
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left =  lowestCommonAncestor(root->left, p,q);
        TreeNode * right = lowestCommonAncestor(root->right, p , q);

        // result

        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{ //both left and right are not null, we found result
           return root;
        }
    }
};

int main(){
  TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

  
    Solution sol;

    // Example: Find LCA of nodes 4 and 5
    TreeNode* p = root->left->left;   // node 4
    TreeNode* q = root->left->right;  // node 5

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
  
   if (lca != NULL)
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data 
             << " is: " << lca->data << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}

// TC - O(N)
// SC - O(N) ---- at the worst case