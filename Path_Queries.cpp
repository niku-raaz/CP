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
    timer=0;

    dfs(1,-1);

    for(int i=1;i<=n;i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<out[i]<<" ";
    }


    


    
   
   
 return 0;
}