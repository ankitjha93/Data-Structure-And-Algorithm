#include <bits/stdc++.h>
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
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN;
       maxPathDown(root, maxi);
       return maxi;
    }

    int maxPathDown(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int left = max(0, maxPathDown(root->left, maxi));
        int right = max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, left + right + root->data);
        return max(left,right) + root->data;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Diameter: " << sol.maxPathSum(root);

    return 0;
}

// TC - O(N)
// SC - O(N)