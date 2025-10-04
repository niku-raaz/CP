#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200002];

vector<int> g[200002];
int in[200002];
int out[200002];
int timer;

void dfs(int x,int p){
    in[x]=timer;
    for(auto y: g[x]){
        if(y!=p){
            timer++;
            dfs(y,x);
        } 
    }
    out[x]=timer;
}

class BIT{
    vector<int> pp;
    public:
    BIT(int n){
        pp.resize(n+1,0);
    }

    void update(int ind,int val){
        for(;ind<pp.size();ind+=(ind &(-ind))){
            pp[ind]+=val;
        }
    }
    int query(int ind){
    int sum = 0;
    for(; ind > 0; ind -= (ind & -ind)) {
        sum += pp[ind];
    }
    return sum;
}

};
   
int32_t main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    timer=1;

    dfs(1,-1);

    // for(int i=1;i<=n;i++){
    //     cout<<in[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<out[i]<<" ";
    // }cout<<endl;

    // done with setting time
    //
    

    

    BIT b(n);

    for(int i=1;i<=n;i++){
        //int ind=in[i];
        b.update(in[i],a[i]);
        b.update(out[i]+1,-a[i]);
    }

    while(q--){
        int tt;cin>>tt;
        if(tt==1){
           // update
           int node,val;
           cin>>node>>val;

           // update the whole range
           int diff=val-a[node];
           b.update(in[node],diff);
           b.update(out[node]+1,-diff);
           a[node]=val;
        }else{
            int node;
            cin>>node;

            int ind=in[node];

            cout<<b.query(ind)<<endl;


        }
    }


    
    



    


    
   
   
 return 0;
}