#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int sum;
    node(){
        sum=0;
    }
};

node a[4*200005];
int arr[200005];

// keeping everything 0 based indexed

int merge(node a,node b){
    return a.sum+b.sum;
}


void build(int id,int l,int r){
    if(l==r){
        a[id].sum=arr[l];
        return;
    }
    int mid=(l+r)/2;

    build(2*id+1,l,mid);
    build(2*id+2,mid+1,r);
    a[id].sum=merge(a[2*id+1],a[2*id+2]);
}

int update(int id, int l,int r, int pos, int diff){
    if(pos<l || pos>r){
        return 0;
    }
    if(l==r && l==pos){
        a[id].sum+=diff;
        return diff;
    }
    int mid=(l+r)/2;
    int lf=update(2*id+1,l,mid,pos,diff);
    int rh=update(2*id+2,mid+1,r,pos,diff);
    a[id].sum+=(lf+rh);
    return lf+rh;
}

int query(int id,int l,int r,int lq,int rq){
    if(lq>r || rq<l){
        return 0;
    }

    if(lq<=l && rq>=r){
        return a[id].sum;
    }

    int mid=(l+r)/2;
    int lf=query(2*id+1,l,mid,lq,rq);
    int rh=query(2*id+2,mid+1,r,lq,rq);

    return lf+rh;
}
   
   
int32_t main(){
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(0,0,n-1);


    while(q--){
        int ch;cin>>ch;
        if(ch==1){
            // update
            int pos,val;
            cin>>pos>>val;
            pos--;
            int diff=val-arr[pos];

            arr[pos]=val;

            update(0,0,n-1,pos,diff);

            // this diff needs to be added

            // less go for it

        }else{
            int lo,hi;
            cin>>lo>>hi;
            lo--;
            hi--;

            cout<<query(0,0,n-1,lo,hi)<<endl;

        }
    }
    
   
   
 return 0;
}