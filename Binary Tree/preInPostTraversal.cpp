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

class Solution{
   public :
    vector<vector<int>> preInPostTraversal(TreeNode* root){

        stack<pair<TreeNode*, int>> st;
       st.push({root, 1});

       vector<int> pre, in, post;
       if(root == NULL) return {};
       while(!st.empty()){
        auto it = st.top();
        st.pop();

        // this is a part of pre
        // increment 1 to 2
        // push the left side of the tree

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }
    // this is a part of in
    // increment 2 to 3
    // push right

    else if(it.second == 2){
        in.push_back(it.first->data);
        it.second++;
        st.push(it);

        if(it.first->right != NULL){
            st.push({it.first->right,1});
        }

    }
    // don't push it back again
    else{
    post.push_back(it.first->data);
          }
       }
        return {pre, in, post};
    }
};

int main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    auto res = sol.preInPostTraversal(root);

    cout << "Preorder: ";
    for (int x : res[0]) cout << x << " ";
    cout << "\nInorder: ";
    for (int x : res[1]) cout << x << " ";
    cout << "\nPostorder: ";
    for (int x : res[2]) cout << x << " ";
    cout << endl;

    return 0;
}

// TC - (3N)
// SC - (4N)