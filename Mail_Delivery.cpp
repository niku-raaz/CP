#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;
    cin>>n;
    int m;cin>>m;
    vector<int> deg(n+1,0);

    vector<set<int>> g(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
        deg[x]++;
        deg[y]++;
    }

    for(int i=1;i<=n;i++){
        if(deg[i]&1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    // 1 se dfs 

    int ct=0;
    vector<int> ans;

    auto dfs=[&](int node,auto &&dfs)->void{
             while (!g[node].empty()) {
                int child = *g[node].begin(); 
                g[node].erase(child);
                g[child].erase(node);
                dfs(child, dfs);
            }
            ans.push_back(node);
    };

    dfs(1,dfs);
    reverse(ans.begin(),ans.end());

    for(int i=1;i<=n;i++){
        if(g[i].size()){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    for(int x: ans){
        cout<<x<<" ";
    }




    
   
   
 return 0;
}