#include<bits/stdc++.h>

using namespace std;



class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution{
    public:
class compare{
    public:
    bool operator() (Node* a, Node* b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    int k = listArray.size();
    if(k == 0) return NULL;
    for(int i = 0; i < k; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }
 
      Node* head = NULL;
      Node* tail = NULL;
    while(minHeap.size() > 0){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
        //  answer LL is empty 
            head = top;
            tail = top;
        }else{

            // insert at Linked List
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

     


  

// Helper to create a linked list from a vector
Node* createLinkedList(vector<int> vals) {
    if (vals.empty()) return NULL;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper to print a linked list
void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

};
int main() {
    // Creating sample sorted linked lists
    Solution sol;

    

    Node* l1 = sol.createLinkedList({1, 4, 5});
    Node* l2 = sol.createLinkedList({1, 3, 4});
    Node* l3 = sol.createLinkedList({2, 6});

    vector<Node*> lists = {l1, l2, l3};

    cout << "Merged Sorted Linked List:" << endl;
    Node* merged = sol.mergeKLists(lists);
    sol.printLinkedList(merged);

    return 0;
}

// TC : O(nlogk)
// SC : O(k)