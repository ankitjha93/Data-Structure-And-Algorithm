
#include<bits/stdc++.h>

using namespace std;



class LRUCache {
        
       public :
       
   class Node{
     public :
        int key;
         int val;
         Node*prev;
         Node*next;
   
     
   
    Node(int _key, int _val){
         key = _key;
         val = _val;
         prev = nullptr;
         next = nullptr;
      }
    
};

    Node * head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

     int cap;
     unordered_map<int, Node*> mpp;


     LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }


     void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        if(prevNode) prevNode->next = nextNode;
        if(nextNode) nextNode->prev = prevNode;
     }
     void insertAfterHead(Node* node){
         Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
     }

    int get(int key) {
        if(mpp.find(key) ==  mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            if(mpp.size() == cap){
               Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mpp[key] = newNode;
            }

        }
    
};

int main(){
    LRUCache lru(2);

    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // returns 1
    lru.put(3, 3);              // evicts key 2
    cout << lru.get(2) << endl; // returns -1 (not found)
    lru.put(4, 4);              // evicts key 1
    cout << lru.get(1) << endl; // returns -1 (not found)
    cout << lru.get(3) << endl; // returns 3
    cout << lru.get(4) << endl; // returns 4
    return 0;
}