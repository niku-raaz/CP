#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
     int val;
     node(){
        val=1e9+7;
     }
};

int merge(node a,node b){
    return max(a.val,b.val);
}

int arr[200005];
node a[4*200005];

void build(int id,int lo,int hi){
    if(lo==hi){
        a[id].val=arr[lo];
        return;
    }
    int mid=(lo+hi)/2;

    build(2*id+1,lo,mid);
    build(2*id+2,mid+1,hi);

    a[id].val=merge(a[2*id+1],a[2*id+2]);
}

void update(int id,int lo,int hi,int pos, int val){
    if(lo>pos || hi<pos){
        return;
    }
    if(lo==hi){
        a[id].val=val;
        return;
    }
    int mid=(lo+hi)/2;
    update(2*id+1,lo,mid,pos,val);
    update(2*id+2,mid+1,hi,pos,val);
    
    a[id].val=merge(a[2*id+1],a[2*id+2]);
}

int query(int id,int lo,int hi, int x){
    // find interval (l,l)>=x
    if(a[id].val<x){
        return -1;
    }
    
    if(lo==hi){
        return lo;
    }

    int left=2*id+1;
    int right=2*id+2;
    int mid=(lo+hi)/2;

    if(a[left].val>=x){
        return query(left,lo,mid,x);
    }else{
        return query(right,mid+1,hi,x);
    }

}
   
int32_t main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(0,0,n-1);


    while(m--){
        int x;cin>>x;

        int ans=query(0,0,n-1,x);
        if(ans==-1){
            cout<<0<<" ";
        }else{
            cout<<ans+1<<" ";
            // update
            int prev=arr[ans];
            
            update(0,0,n-1,ans,prev-x);
            arr[ans]=(prev-x);
        }

    }


    
    
   
   
 return 0;
}