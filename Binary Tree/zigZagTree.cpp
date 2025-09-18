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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> result;
         if(root == NULL){
            return result;
         }

         queue<TreeNode*> nodesQueue;
         nodesQueue.push(root);
         bool LeftToRight = true;

         while(!nodesQueue.empty()){
            int size = nodesQueue.size();

            vector<int> row(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value

                int index = (LeftToRight) ? i : (size - 1 - i);

                row[index] = node->data;
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }

            // after this level

            LeftToRight = !LeftToRight;
            result.push_back(row);
         }
         return result;
    }
};

int main(){

 TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";
    for(auto level : ans){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;


}

// TC - O(N)
// SC - O(N) at the worst case