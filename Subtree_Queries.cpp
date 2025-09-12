#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int val;
    node(){
        val=0;
    }
};

node seg[800005];
int a[200005];

void build(int id,int l,int r,vector<int>& v){
    if(l==r){
        seg[id].val=v[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id+1,l,mid,v);
    build(2*id+2,mid+1,r,v);
    seg[id].val=seg[2*id+1].val+seg[2*id+2].val;
}

void update(int id,int l,int r, int ind,int x){
    if(l>ind || r<ind){
        return;
    }
     if(l==r){
        seg[id].val+=x;
        return;
     }

     int mid=(l+r)/2;

     update(2*id+1,l,mid,ind,x);
     update(2*id+2,mid+1,r,ind,x);
     seg[id].val=seg[2*id+1].val+seg[2*id+2].val;
}

int query(int id,int l,int r,int ql,int qr){
    if(r<ql || qr<l){
        return 0;
    }

    if(l>=ql && r<=qr ){
        return seg[id].val;
    }
    int mid=(l+r)/2;

    int left=query(2*id+1,l,mid,ql,qr);
    int right=query(2*id+2,mid+1,r,ql,qr);


    return left+right;

}

   
   
int32_t main(){
    int n;cin>>n;
    int q;cin>>q;
    vector<vector<int>> g(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> v(n),in(n),out(n);
    int tick=0;


    auto dfs=[&](int node,int par,auto &&dfs)->void{
        v[tick]=a[node];
        in[node]=tick;
        for(auto& child: g[node]){
            if(child==par) continue;
            tick++;
            dfs(child,node,dfs);
        }
        out[node]=tick;    
    };

    dfs(0,-1,dfs);

    build(0,0,n-1,v);

    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }cout<<endl;

    // for(int i=0;i<n;i++){
    //     cout<<in[i]<<" ";
    // }cout<<endl;

    // for(int i=0;i<n;i++){
    //     cout<<out[i]<<" ";
    // }cout<<endl;

    while(q--){
        int qq;cin>>qq;

        if(qq==1){

            int node;cin>>node;
            int val;cin>>val;

            node--;
            int diff=val-v[in[node]];

            update(0,0,n-1,in[node],diff);

            v[in[node]]=val;

        }else{
            int node;cin>>node;
            node--;

            cout<<query(0,0,n-1,in[node],out[node])<<endl;

        }
    }







    
    
   
   
 return 0;
}