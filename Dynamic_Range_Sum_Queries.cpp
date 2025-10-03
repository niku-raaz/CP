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

class BIT{
    vector<int> p;
    public:
    BIT(int n){
        p.resize(n+1);
        for(int i=0;i<=n;i++){
            p[i]=0;
        }
    }

    // BIT should be 1 based indexing
    // update
    void update(int ind,int diff){
        for(ind;ind<p.size();ind+=(ind&(-ind))){
            p[ind]+=diff;
        }
    }

    int query(int ind){
        int sum=0;
        for(ind;ind>0;ind-=(ind&(-ind))){
            sum+=p[ind];
        }
        return sum;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
};
   
   
int32_t main(){
    int n,q;
    cin>>n>>q;

    // lets do uing BIT

    BIT b(n);
    // build
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        b.update(i,x);
        arr[i]=x;
    }

    // query

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            // update
            int ind,val;
            cin>>ind>>val;
            int diff=val-arr[ind];
            arr[ind]=val;

            b.update(ind,diff);


        }else{
            int l,r;
            cin>>l>>r;

            cout<<b.query(l,r)<<endl;

        }
    }









    
    
   
   
 return 0;
}