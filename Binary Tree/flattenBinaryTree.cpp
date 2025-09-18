
//Morris Approach 

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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left != NULL){
                TreeNode* prev = cur->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                  cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

void printFlattened(TreeNode* root) {
    TreeNode* cur = root;
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->right;
    }
    cout << endl;
}

int main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree: ";
    printFlattened(root);  // Expected output: 1 2 3 4 5 6

    return 0;
}


// TC - O(N) 
// SC - O(1)


// Recursive Approach


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

     TreeNode* prev = NULL; 

public:
    void flatten(TreeNode* root) {
       if(root == NULL) {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;  
    }
};

void printFlattened(TreeNode* root) {
    TreeNode* cur = root;
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->right;
    }
    cout << endl;
}

int main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree: ";
    printFlattened(root);  // Expected output: 1 2 3 4 5 6

    return 0;
}


// TC - O(N) 
// SC - O(N)


// Iterative Approach


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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur->right){
                st.push(cur->right);
            }

            if(cur->left){
                st.push(cur->left);
            }

            if(!st.empty()){
                cur->right = st.top();
                cur->left = NULL;
            }
        }
        
    }
};

void printFlattened(TreeNode* root) {
    TreeNode* cur = root;
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->right;
    }
    cout << endl;
}

int main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree: ";
    printFlattened(root);  // Expected output: 1 2 3 4 5 6

    return 0;
}


// TC - O(N) 
// SC - O(N)
