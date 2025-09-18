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
    int floor(TreeNode* root, int key) {
        // Code here
        int floor = -1;
        while(root){
            if(root->data == key){
                floor = root->data;
                return floor;
            }
            if(key > root->data){
                floor = root->data;
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return floor;
    }
};

void printInorder(TreeNode* root) {
    if(root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
     TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

     Solution sol;
    int key = 5;
    int floorValue = sol.floor(root, key);

    cout << "Floor of " << key << " is: " << floorValue << endl;

    return 0;
}
// TC - O(logN) 
// SC - O(1)