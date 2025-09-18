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
   
   TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* successor = NULL;

    while (root != NULL)
    {
        /* code */
        if(p->data >= root->data){
            root = root->right;
        }else{
            successor = root;
            root = root->left;
        }
    }
    return successor;
    
   }
};

int main(){
     
     TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* p = root->left; // Node with value 10

    Solution solution;
    TreeNode* succ = solution.inorderSuccessor(root, p);

    if (succ != NULL) {
        cout << "Inorder Successor of " << p->data << " is " << succ->data << endl;
    } else {
        cout << "Inorder Successor of " << p->data << " does not exist." << endl;
    }

    return 0;
    
}

// TC - O(H) ---- Height of the tree 
// SC - O(1)