#include<bits/stdc++.h>
using namespace std;

 struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
 };

class Solution {
public:
    Node* middleNode(Node* head) {
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        int midNode = cnt/2 + 1;

        temp = head;
        while(temp != NULL){
            midNode = midNode - 1;
            if(midNode == 0) break;
            temp = temp->next;
        }
        return temp;
    }
};

int main(){
    // Create Linked List: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution sol;
    Node* mid = sol.middleNode(head);

    cout << "Middle Node Value: " << mid->data << endl;

    return 0;
    
}