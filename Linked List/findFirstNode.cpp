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

class Solution{
  public :
    Node* findFirstNode(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
             slow = head;
             while(slow != fast){
                slow = slow->next;
                fast = fast->next;
             }
             return slow;
        }
    }
        return NULL;
        

    }
  
    void printLinkedList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
};

int main(){

  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

//    5->3
   head->next->next->next->next = head->next->next;

 
  
   Solution s;
    Node* loopStart = s.findFirstNode(head);
    if (loopStart != NULL) {
        cout << "Loop starts at node with value: " << loopStart->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }
    return 0;
   
    
}