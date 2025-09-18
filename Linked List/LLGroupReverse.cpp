#include<bits/stdc++.h>
using namespace std;

     class Node{
        public :

        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }

     };

  Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
     Node* prev = NULL;
     Node* temp = head;
     while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
     }
     return prev;
  }

  Node* getKthNode(Node* temp, int k){
    k -= 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
  }

     Node* reverseKGroup(Node* head, int k){
         Node* temp = head;
         Node* prevNode = NULL;

         while(temp != NULL){
            Node* kthNode = getKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode) prevNode->next = reverseLL(temp);
                break;
            }
            Node* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp == head){
                head = kthNode;
            }else{
              prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
         }
         return head;
        
     }


      void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main(){
  Node*  head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
   head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;
    
    

    Node* newList = reverseKGroup(head, k);

    cout << "Merged sorted linked list: ";
    printLinkedList(newList);

    return 0;
}