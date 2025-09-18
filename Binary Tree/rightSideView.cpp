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
    vector<int> rightSideView(TreeNode* root) {
         vector<int> res;
         recursion(root, 0, res);
         return res;
    }
     
    private:

    void recursion(TreeNode* root, int level, vector<int> &res){
           if(root == NULL) return;
           if(res.size() == level) res.push_back(root->data);
           recursion(root->right, level + 1, res);
           recursion(root->left, level + 1, res);
    }
};

int main(){
     TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);
    // root->right->left = new TreeNode(90);
    // root->right->right = new TreeNode(100);

    Solution sol;

    vector<int> ans = sol.rightSideView(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}

// TC - O(N)
// SC - O(H) --- Height of the tree



/*

Note :- 1.For the left side view just do the reverse.
        2.Time and Space Complexity will be same.

*/