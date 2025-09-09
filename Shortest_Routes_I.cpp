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

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int inf=1e18;
    vector<int> dist(n+1,inf);
    dist[1]=0;

    pq.push({0,1}); // dist ,node


    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;

        pq.pop();
        if(dist[node]<dis){
            continue;
        }

        dist[node]=dis;

        for(auto& child: g[node]){
            int chNode=child.first;
            int wt=child.second;
            if(dist[chNode]>dist[node]+wt){
                dist[chNode]=dist[node]+wt;
                pq.push({dist[chNode],chNode});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }

    

    
   
   
 return 0;
}