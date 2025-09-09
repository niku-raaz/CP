#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=1e9+7;

// prev=0 = black
// prev=1 = white

int dp[100002][3];

int dfs(int node,int par,int prev,vector<vector<int>>& g){

    if(dp[node][prev]!=-1){
        return dp[node][prev];
    }

    int way1=1;
    // put current color =W;

    for(auto& child: g[node]){
        if(child==par) continue;
        way1*=dfs(child,node,1,g);
        way1%=mod;
    }

    

    if(prev!=0){
        // put current color =B
        int way2=1;

        for(auto& child: g[node]){
            if(child==par)continue;
            way2*=dfs(child,node,0,g);
            way2%=mod;
        }

        way1+=way2;
        way1%=mod;
    }

    

    return dp[node][prev]= way1;
}
   
int32_t main(){
    int n;cin>>n;
    vector<vector<int>> g(n+1);

    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    memset(dp,-1,sizeof(dp));

    cout<<dfs(1,-1,3,g);

 return 0;
}