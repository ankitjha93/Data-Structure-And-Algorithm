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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          map<int, int> mpp;
          for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
          }

          TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);

          return root;
    }


    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, map<int, int> &mpp){
         if(preStart > preEnd || inStart > inEnd) return NULL;

         TreeNode* root = new TreeNode(preorder[preStart]);

         int inRoot = mpp[root->data];
         int numLeft = inRoot - inStart;

         root->left = buildTree(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mpp);

         root->right = buildTree(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mpp);

         return root;
    }
};

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);

      // ✅ Test: Print inorder traversal to verify
    function<void(TreeNode*)> printInorder = [&](TreeNode* node){
        if(!node) return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    };

    printInorder(root);  // Expected: 9 3 15 20 7

}

// TC - O(N)
// SC - O(N)