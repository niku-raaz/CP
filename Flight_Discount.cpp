#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1);

    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
    }


    // Kind OF GRAPH DUPLICATION
    // 
    int inf=1e18;
    vector<vector<int>> dist(n+1,vector<int>(2,inf));

    using State = tuple<int,int,int>; // {dist,node,used}
    priority_queue<State, vector<State>, greater<State>> q;

    dist[1][0]=0;

    q.push({0,1,0});

    while(!q.empty()){
        auto [d,node,used]= q.top();
        q.pop();

        if(d>dist[node][used]){
            continue;
        }

        // minimum wale hi relax krenge

        for(auto [child,wt]: g[node]){
            if(dist[child][used]>d+wt){
                dist[child][used]=d+wt;
                q.push({dist[child][used],child,used});
            }
            if(!used && d+wt/2 <dist[child][1]){
               dist[child][1]=d+wt/2;
               q.push({dist[child][1],child,1});
            }
        }

    }


    cout<<dist[n][1];
       






    
   
   
 return 0;
}