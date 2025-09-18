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
	public:
		vector<int> preorder(TreeNode* root){
	       //your code goes here
           vector<int> preorder;
           TreeNode* cur = root;
           while(cur != NULL){
            if(cur->left == NULL){
                preorder.push_back(cur->data);
                cur = cur->right;
            }else{
                
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                 prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = cur;
                 preorder.push_back(cur->data);
                cur = cur->left;
            }else{
                prev->right = NULL;
            //    inorder.push_back(cur->data); ------ one line change
               cur = cur->right;
            }
            }
           }
           return preorder;
		}
};

void printpreorder(TreeNode* root) {
    Solution s;
    vector<int> result = s.preorder(root);
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    
    
      // Construct tree manually for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Preorder traversal: ";
    printpreorder(root);  // Expected: 3 9 20 15 7

    return 0;
   
    

}

// TC - O(N) --- amortized
// SC - O(1)