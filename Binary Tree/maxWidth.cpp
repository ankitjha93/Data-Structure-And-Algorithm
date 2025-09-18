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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;  // to make the id starting from zero
            int first, last;
            for(int i = 0; i < size; i++){
                 long long cur_id = q.front().second - mmin;
                 TreeNode * node = q.front().first;
                 q.pop();
                 if(i == 0) first = cur_id;
                 if(i == size-1) last = cur_id;
                 if(node->left)
                   q.push({node->left, cur_id*2+1});

                 if(node->right)
                   q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;

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

    int ans = sol.widthOfBinaryTree(root);
    cout<<ans;
    return 0;
}

// TC - O(N)
// SC - O(N) ---- as we are using queue