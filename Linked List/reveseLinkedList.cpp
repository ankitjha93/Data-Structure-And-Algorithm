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
    Node* reverseList(Node* head){
       Node* prev = nullptr;
       Node* temp = head;
       while(temp != nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
       }
       return prev;

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
  
    Solution s;
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
 
   cout<<"Original Linked List :";
   s.printLinkedList(head);

   head = s.reverseList(head);

    cout << "Reversed Linked List: ";
    s.printLinkedList(head);

    return 0;
   
    
}