#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:

    Node * findNthNode(Node* temp, int k){
         int cnt = 1;
         while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
         }
         return temp;
    }

    Node* rotateLeft(Node* head, int k) {
       if(head == NULL || k == 0) return head;
       Node* tail = head;
       int len = 1;
       while(tail->next != NULL){
        len++;
        tail = tail->next;
       }

       if(k % len == 0) return head;
       k =  k % len;


       

       tail->next = head;
       Node * newLastNode = findNthNode(head, k);
       head = newLastNode->next;
       newLastNode->next = NULL;
       return head;

        
    }

    void printList(Node* head) {
        while (head) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Solution s;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    cout << "Original list: ";
    s.printList(head);

    head = s.rotateLeft(head, k);

    cout << "Left rotated list: ";
    s.printList(head);

    return 0;
}
