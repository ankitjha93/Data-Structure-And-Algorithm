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


     Node* addTwoNumbers(Node* list1, Node* list2){
         Node* temp1 = list1;
         Node* temp2 = list2;
         Node* dummyNode = new Node(-1);

         Node* temp = dummyNode;
         int carr = 0;

         while(temp1 != NULL || temp2 != NULL){
            int sum = carr;
            if(temp1) sum += temp1->data;
            if(temp2) sum += temp2->data;

            Node* newNode = new Node(sum % 10);
            carr = sum/10;
            temp->next = newNode;
            temp = temp->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
         }
         if(carr){
            Node* newNode = new Node(carr);
            temp->next = newNode;
         }
       return dummyNode->next;
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
  Node* list1 = new Node(2);
    list1->next = new Node(4);
    list1->next->next = new Node(3);

    Node* list2 = new Node(5);
    list2->next = new Node(6);
    list2->next->next = new Node(4);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = addTwoNumbers(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}