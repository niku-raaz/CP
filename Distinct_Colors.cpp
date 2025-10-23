#include<bits/stdc++.h>
using namespace std;
#define int long long
   
#define pb push_back
   
int32_t main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    // int root=0

    vector<set<int>> mp(n+1);
    vector<int> ans(n+1,0);

    for(int i=1;i<=n;i++){
        mp[i].insert(a[i]);
    }

    auto dfs=[&](int node,int par,auto && dfs)->void{
        // how to small to large merge ??
        // see some editorial

        int mx=0;// maximum size of its child
        int id=0;// the max size set id
        for(auto child: g[node]){
            if(child==par)continue;
            dfs(child,node,dfs);
            if(mp[child].size()>mx){
                mx=mp[child].size();
                id=child;
            }
        }

        if(id==0){
            // its a leaf
            ans[node]=1;
            return;
        }

        swap(mp[node],mp[id]); // bada wala is now my node

        // now start merging
        for(auto child: g[node]){
            if(child==par || child==id) continue;

            for(auto x: mp[child]){
                mp[node].insert(x);
            }
            mp[child].clear(); // for space optimisation
        }
        mp[node].insert(a[node]);
        ans[node]=mp[node].size();
              
    };

    dfs(1,-1,dfs);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    
   
   
 return 0;
}