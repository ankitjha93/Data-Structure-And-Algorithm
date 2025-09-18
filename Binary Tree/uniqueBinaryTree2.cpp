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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
          return NULL;

          map<int, int> hm;

          for(int i = 0; i < inorder.size(); ++i)
             hm[inorder[i]] = i;

             return buildTreePostIn(inorder, 0, inorder.size() - 1, 
              postorder, 0,postorder.size() - 1, hm);
    }

    TreeNode* buildTreePostIn(vector<int> inorder, int is, int ie, vector<int> &postorder, int ps, int pe,map<int, int> &hm){
        if(ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = hm[postorder[pe]];
        int numsLeft = inRoot - is;

        root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);

        root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);

        return root;
    }
};

int main(){
      vector<int> inorder   = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);

    // ✅ Test: Print inorder traversal to verify correctness
    function<void(TreeNode*)> printInorder = [&](TreeNode* node){
        if(!node) return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    };

    printInorder(root);

}

// TC - O(N)
// SC - O(N)