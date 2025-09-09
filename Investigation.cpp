#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int n;
    cin>>n;
    int m;cin>>m;

    vector<vector<pair<int,int>>> g(n+1);
    vector<vector<pair<int,int>>> g2(n+1);

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g2[y].push_back({x,w});
    }

    // 
    int inf=1e15;
    vector<int> dist(n+1,inf);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    dist[1]=0;

    q.push({0,1}); // dis,node
    while(!q.empty()){
        int node=q.top().second;
        int dis=q.top().first;
        q.pop();
        if(dist[node]<inf && dist[node]!=dis){
            continue;
        }
        if(node==n){
            break;
        }

        for(auto& ch: g[node]){
            int child=ch.first;
            int wt=ch.second;
            if(dist[node]<inf && dist[child]>dist[node]+wt){
                dist[child]=dist[node]+wt;
                q.push({dist[child],child});
            }

        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }

    cout<<dist[n]<<" ";

    // want to calculte no of ways?
    // dfs
    int mod=1e9+7;

    // Counts

    vector<int> cDP(n+1,-1),minDP(n+1,-1),mxDP(n+1,-1);

    auto dfsCount=[&](int node,auto &&dfsCount)->int{

        if(node==1){
            return 1;
        }

        if(cDP[node]!=-1){
            return cDP[node];
        }

        int ans=0;

        for(auto& ch: g2[node]){
            int child=ch.first;
            int wt=ch.second;
            if(dist[child]+wt==dist[node]){
                ans+=dfsCount(child,dfsCount);
                ans%=mod;
            }
        }
        return cDP[node]=ans;
    };


    cout<<dfsCount(n,dfsCount)<<" ";

    auto dfsMin=[&](int node,auto &&dfsMin)->int{

        if(node==1){
            return 0;
        }
        if(minDP[node]!=-1){
            return minDP[node];
        }

        int ans=1e15;

        for(auto& ch: g2[node]){
            int child=ch.first;
            int wt=ch.second;
            if(dist[child]+wt==dist[node]){
                ans=min(ans,1+dfsMin(child,dfsMin));
            }
        }
        return minDP[node]= ans;
    };

    cout<<dfsMin(n,dfsMin)<<" ";

    auto dfsMax=[&](int node,auto &&dfsMax)->int{

        if(node==1){
            return 0;
        }
        if(mxDP[node]!=-1){
            return mxDP[node];
        }

        int ans=0;

        for(auto& ch: g2[node]){
            int child=ch.first;
            int wt=ch.second;
            if(dist[child]+wt==dist[node]){
                ans=max(ans,1+dfsMax(child,dfsMax));
            }
        }
        return mxDP[node]=ans;
    };


    cout<<dfsMax(n,dfsMax);










     
   
   
 return 0;
}