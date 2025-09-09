#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1),gR(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        gR[y].push_back(x);
    }

    // first DFS forward

    vector<int> vis(n+1,0);
    vector<int> comp(n+1,0);
    vector<int> v;

    auto dfs=[&](int node,auto &&dfs)->void{
        vis[node]=1;
        for(int child: g[node]){
            if(vis[child]==0){
                dfs(child,dfs);
            }
        }
        v.push_back(node); // jo sbse last mein finish hoga
        // wo first me push hoga

    };


    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,dfs);
        }
    }

    reverse(v.begin(),v.end());

    // for(auto x: v){
    //     cout<<x<<" ";
    // }

    int curr=1;

    auto dfsAssign=[&](int node,int curr,auto && dfsAssign)->void{
        comp[node]=curr;       
        for(auto child: gR[node]){
            if(comp[child]==0){
                dfsAssign(child,curr,dfsAssign);
            }
        }
    };

    vector<int> ans;

    for(int i=0;i<v.size();i++){
        if(comp[v[i]]==0){
            // fo DFS
            dfsAssign(v[i],curr,dfsAssign);
            curr++;
            ans.push_back(v[i]);
        }
    }

    if(curr==2){
        cout<<"YES";
        return 0;
        
    }

    cout<<"NO\n";

    cout<<ans[1]<<" "<<ans[0];

    




    
   
   
 return 0;
}