#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    vector<vector<int>> g(n+1);

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans=0;

    bool good=1;
    int root=0;

    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            root=i;
            break;
        }
    }

    vector<int> vis(n+1,0);

    auto dfs=[&](int node,int lo,auto &&dfs)->void{
            vis[node]=1;

            for(auto child: g[node]){
                if(!vis[child]){
                    if(lo){
                        ans++;
                        lo=0;
                        dfs(child,0,dfs);
                    }else{
                        dfs(child,1,dfs);
                    }
                    
                }
            }
    };

    dfs(root,1,dfs);
    cout<<ans;

     
    
   
   
 return 0;
}