#include<bits/stdc++.h>
using namespace std;
#define int long long

class Node{
    public:
    Node* child[26];
    int cntPrefix=0;
    int cntEndswith=0;
    bool containsKey(char ch){
        int idx=ch-'a';
        return (child[idx]!=NULL)
    }

    void putKey(char ch){
        int idx=ch-'a';
        child[idx]=new Node();
    }
    Node* getKey(char ch){
        int idx=ch-'a';
        return child[idx];
    }
    void increaseEnd(){
        cntEndswith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndswith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }

};

class Trie{
    
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string& word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                // need to create this key
                node->putKey(word[i]);
            }
            node=node->getKey(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWords(string& word){
        Node* node=root;

        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->getKey(word[i]);
            }else{
                return 0;
            }
        }
        return node->cntEndswith;
    }
    int countPrefix(string& word){
        Node* node=root;

        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->getKey(word[i]);
            }else{
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void eraseWord(string& word){
        Node* node=root;

        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->getKey(word[i]);
                node->reducePrefix();
            }else{
                return ;
            }
        }
        node->deleteEnd();

    }

};
   
   
int32_t main(){
    
   
   
 return 0;
}