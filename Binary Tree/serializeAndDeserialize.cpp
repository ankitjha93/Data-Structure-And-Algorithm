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


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNod = q.front();
            q.pop();

            if(curNod == NULL) s.append("#,");
            else s.append(to_string(curNod->data) + ',');
            if(curNod != NULL){
                q.push(curNod->left);
                q.push(curNod->right);
            }
        }

        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            /* code */
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

             getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* RightNode = new TreeNode(stoi(str));
                node->right = RightNode;
                q.push(RightNode);
            }

            
        }

        return root;
        
    }
};

// ✅ Helper: Print inorder traversal
void printInorder(TreeNode* node){
    if(!node) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main(){
      // Construct tree manually for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserializedRoot = codec.deserialize(serialized);

    cout << "Inorder of deserialized tree: ";
    printInorder(deserializedRoot);  // Expected: 9 3 15 20 7
    cout << endl;

}

// TC - O(N)
// SC - O(N)