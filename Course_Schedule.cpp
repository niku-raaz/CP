#include<bits/stdc++.h>
using namespace std;
#define int long long

bool dfs(int node,vector<vector<int>>& g,vector<int>& vis,vector<int>& a){
    vis[node]=1; // visiting
    bool ans=0;
    for(auto& child: g[node]){
        if(vis[child]==1){
            return 1;
        }
        if(vis[child]==0){
            ans|=dfs(child,g,vis,a);
            if(ans){
                return 1;
            }
        }
    }

    a.push_back(node);
    vis[node]=2;

    
    return ans;
}
   
   
int32_t main(){

    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> g(n+1);

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[y].push_back(x);
    }

    vector<int> vis(n+1,0);
    vector<int> ans;

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,g,vis,ans)){
               cout<<"IMPOSSIBLE";
               return 0;
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
   
   
 return 0;
}