#include<bits/stdc++.h>
using namespace std;

// Make implementation for DLL
class Node{
    public:
    int key,val;
    // Two pointers
    Node* next;
    Node* prev;

    Node(int _key,int _val){
        key=_key;
        val=_val;
    }
};

class LRUCache{
    // Need both ways so take two
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    int cap; // capacity of LRU

    // Need map
    unordered_map<int,Node*> mp;

    public:
    // Constructor
    LRUCache(int size){
        cap=size;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newNode){
        Node* temp= head->next; 
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void deleteNode(Node* delNode){
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }


    // LRU functions
    int get(int _key){
        // find the val
        if(mp.find(_key)!=mp.end()){
            Node* resNode= mp[_key];
            int res=resNode->val
            mp.erase(_key);
            deleteNode(resNode);
            addNode(resNode);
            mp[_key]=head->next;
            return res;
        }

        return -1;
    }

    void put(int _key,int _val){
        if(mp.find(key)!=mp.end()){
            Node* existingNode= mp[_key];
            mp.erase(_key);
            deleteNode(existingNode);
        }

        if(mp.size()==cap){
            // delete tail
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(_key,_val));
        mp[_key]=head->next;
    }

};

   
   
int32_t main(){
    
   
   
 return 0;
}