#include<bits/stdc++.h>
using namespace std;

   class Node{
     public :
        int key;
         int val;
         int cnt;
         Node*prev;
         Node*next;
   
    Node(int _key, int _val){
         key = _key;
         val = _val;
         prev = nullptr;
         next = nullptr;
         cnt = 1;
      }
};

class List{
  public :

   int size;
   Node* head;
   Node* tail;
   List(){
     head = new Node(0,0);
     tail = new Node(0,0);
     head->next = tail;
     tail->prev = head;
     size = 0;
   }

   void insertAfterHead(Node* node){
         Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
        size++;
     }

      void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        if(prevNode) prevNode->next = nextNode;
        if(nextNode) nextNode->prev = prevNode;
        size--;
     }
};

class LFUCache{
     
map<int, Node*> keyNode;
map<int, List*> freqListMap;

int maxSizeCache;
int minFreq;
int curSize;

public :

     LFUCache(int capacity) {
       
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }else {
    nextHigherFreqList = new List();
    freqListMap[node->cnt + 1] = nextHigherFreqList;
}
        node->cnt +=  1;
        nextHigherFreqList->insertAfterHead(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if(keyNode.find(key) ==  keyNode.end()) return -1;
        Node* node = keyNode[key];
         int val = node->val;
        updateFreqListMap(node);
        return val;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            
            updateFreqListMap(node);
        }else{
            if(curSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;

            minFreq = 1;

            List*  listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* newNode = new Node(key, value);
            listFreq->insertAfterHead(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = listFreq;
            }

        }
};


int main(){
    LFUCache lfu(2);

   lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl; // returns 1
    lfu.put(3, 3);              // evicts key 2
    cout << lfu.get(2) << endl; // returns -1 (not found)
    
 cout << lfu.get(3) << endl;
    lfu.put(4, 4);              // evicts key 1
    cout << lfu.get(1) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 3
    cout << lfu.get(4) << endl; // returns 4
    return 0;
}