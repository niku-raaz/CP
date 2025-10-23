#include<bits/stdc++.h>
using namespace std;
#define int long long


vector<int> D;

void pre(){
    D.resize(1000001,1);
    
    for(int i=2;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i){
            D[j]++;
        }
    }
}

struct Node{
    int sum;
    int mx;
    Node(){
        sum=0;
        mx=0;
    }
};

// Everything is zero based indexed

class SGTree{
    vector<Node> tree;
    int n;
    vector<int> arr;

    public:
    SGTree(int n,vector<int>& a){
        tree.resize(4*n+3);
        this->n=n;
        arr=a;
        build(0,0,n-1);
    }


    void build(int id,int lo,int hi){
        if(lo==hi){
            tree[id].sum=arr[lo];
            tree[id].mx=arr[lo];
            return;
        }
        int mid=(lo+hi)/2;
        build(2*id+1,lo,mid);
        build(2*id+2,mid+1,hi);
        tree[id].mx=max(tree[2*id+1].mx ,tree[2*id+2].mx);
        tree[id].sum=(tree[2*id+1].sum+tree[2*id+2].sum);
    }
    
    int sumQuery(int id,int lo,int hi,int left,int right){
        if(hi<left || lo>right){
            return 0;
        }
        if(lo>=left && hi<=right){
            return tree[id].sum;
        }
        int mid=(lo+hi)/2;
        int x=sumQuery(2*id+1,lo,mid,left,right);
        int y=sumQuery(2*id+2,mid+1,hi,left,right);
        return x+y;
    }

    // I have to do range update
    // for L to R
    // I will keep splitting L, R till max of that range is>2 

    void update(int id,int lo,int hi,int left,int right){
        if(hi<left || lo>right){
            return;
        }
        if(tree[id].mx<=2){
            return;
        }
        if(lo==hi){
            arr[lo]=D[arr[lo]];
            tree[id].sum=arr[lo];
            tree[id].mx=arr[lo];
            return;
        }

        int mid=(lo+hi)/2;
        update(2*id+1,lo,mid,left,right);
        update(2*id+2,mid+1,hi,left,right);
        tree[id].mx=max(tree[2*id+1].mx ,tree[2*id+2].mx);
        tree[id].sum=(tree[2*id+1].sum+tree[2*id+2].sum);        
    }

};
   
   
int32_t main(){
    pre();
    // Implement
    // Segment tree
    // storing sum and max 
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    SGTree seg(n,arr);
    

    while(m--){
        int x,l,r;
        cin>>x>>l>>r;
        l--;
        r--;

        if(x==1){
            seg.update(0,0,n-1,l,r);
        }else{
            cout<<seg.sumQuery(0,0,n-1,l,r)<<endl;;

        }
    }


    
   
   
 return 0;
}