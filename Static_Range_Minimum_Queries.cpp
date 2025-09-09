#include<bits/stdc++.h>
using namespace std;
#define int long long


struct node{
    int val;
    node(){
       val=INT_MAX;
    }
};

int merge(node a,node b){
    return min(a.val,b.val);
}

node a[4*200050];

int arr[200005];

void build(int id, int l, int r){
    if(l==r){
        a[id].val=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    a[id].val=merge(a[2*id],a[2*id+1]);
}

int query(int id, int l,int r, int lq, int rq){
    if(lq>r || rq<l){
        // no intersection
       // cout<<l<<" "<<r<<" "<<INT_MAX<<endl;
        return INT_MAX;
    }

    if(l>=lq && r<=rq){
        // complete overlap
        //cout<<l<<" "<<r<<" "<<a[id].val<<endl;
        return a[id].val;
    }

    int mid=(l+r)/2;

    int lf=query(2*id,l,mid,lq,rq);
    int rh=query(2*id+1,mid+1,r,lq,rq);

    return min(lf,rh);
}
   
int32_t main(){
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(1,0,n-1);

    // for(int id=1;id<16;id++){
    //     cout<<a[id].val<<" ";
    // }
    // cout<<endl;

    while(q--){
        int lq,rq;
        cin>>lq>>rq;
        lq--;
        rq--;

        cout<<query(1,0,n-1,lq,rq)<<endl;
    }



    
    
   
 return 0;
}