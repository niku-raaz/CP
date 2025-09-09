#include<bits/stdc++.h>
using namespace std;

struct Node{

       Node *links[26];
       bool flag=false;   

       bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
       }

       void put(char ch){
        links[ch-'a']= new Node();
       }

       Node* get(char ch){
        return links[ch-'a'];
       }

       void setEnd(){
        flag=true;
       }

       bool isEnd(){
        return flag;
       }


};

class Trie{
    private:

    Node* root;

    public:

    Trie(){
        root=new Node();
    }

    void insert(string word){
        int n=word.size();

        Node* curr=root;

        for(int i=0;i<n;i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i]);
            }
            curr=curr->get(word[i]);
        }
        
        curr->setEnd();

    }

    bool searchWord(string word){
        int n=word.size();
        Node* curr=root;

        for(int i=0;i<n;i++){
            if(curr->containsKey(word[i])){
                curr=curr->get(word[i]);
            }else{
                return 0;
            }
        }

        return curr->isEnd();
    }

    bool startsWith(string word){
        int n=word.size();
        Node* curr=root;

        for(int i=0;i<n;i++){
            if(curr->containsKey(word[i])){
                curr=curr->get(word[i]);
            }else{
                return 0;
            }
        }
        return 1;
    }




};
   
   
int main(){
    
   
   
 return 0;
}