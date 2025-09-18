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

 void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
      }
 }
 
 vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent

            markParents(root, parent_track, target);

            unordered_map<TreeNode*, bool> visited;
            queue<TreeNode*> q;
            q.push(target);
            visited[target] = true;
            int curr_level = 0;
            while(!q.empty()){ /*Second BFS to go upto k level from target node and using our hashtable info*/
                int size = q.size();
                if(curr_level++ == k) break;
                for(int i = 0; i < size; i++){
                      TreeNode* current = q.front(); q.pop();
                       if(current->left && !visited[current->left]){
                         q.push(current->left);
                         visited[current->left] = true;
                       }

                       if(current->right && !visited[current->right]){
                          q.push(current->right);
                          visited[current->right] = true;
                       }
                       
                       if(parent_track[current] && !visited[parent_track[current]]){
                        q.push(parent_track[current]);
                        visited[parent_track[current]] = true;
                       }
                }
            }

            vector<int> result;
            while(!q.empty()){
                TreeNode* current = q.front(); q.pop(); 
                result.push_back(current->data);           
            
            }
            return result;
    }
};

int main(){
  TreeNode* root = new TreeNode(35);
    root->left = new TreeNode(20);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

  
    Solution sol;


    TreeNode* target = root->left->right;
    int k = 2;
vector<int> ans = sol.distanceK(root, target, k);
    for(auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}

// TC - O(N)
// SC - O(N) 