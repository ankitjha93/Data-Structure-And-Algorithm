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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return (p == q);
        }

        return (p->data == q->data)
          &&  isSameTree(p->left, q->left)
          && isSameTree(p->right, q->right);
    }
};

int main(){

TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Tree 3 (different structure)
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);

    Solution sol;

    cout << (sol.isSameTree(p, q) ? "Same\n" : "Not Same\n");  // ✅ Same
    cout << (sol.isSameTree(p, r) ? "Same\n" : "Not Same\n");  // ❌ Not Same

    return 0;

}

// TC - O(N)
// SC - O(N) at the worst case