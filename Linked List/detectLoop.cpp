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
    bool detectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
        

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
  head->next->next->next->next = new Node(5);

//    5->3
   head->next->next->next->next = head->next->next;

 
  
   if(s.detectLoop(head)){
      cout<<"loop dectected in the linkedList"<<endl;

   }else{
    cout<<"Loop not detected in the linkedList"<<endl;
   }

    return 0;
   
    
}