#include<bits/stdc++.h>
using namespace std;
#define int long long

// define the graph
const int N=100;
int tick=0;
vector<vector<int>> g(N+1);

// Write Two Algo Now

// First let me write Bridge Find
// so need in and lowest time to reaach this through back edges
// and visited array
vector<int> vis(N+1,0),in(N+1),lo(N+1);

vector<pair<int,int>> bridges;

void dfs(int node,int par){
    in[node]=lo[node]=tick;
    tick++;
    vis[node]=1;
    for(auto child: g[node]){
        if(child==par)continue;
        if(vis[child]){
            lo[node]=min(lo[node],in[child]); // through back edges
        }else{
            dfs(child,node);
            lo[node]=min(lo[node],lo[child]); // through all childs
            if(lo[node]>in[node]){
                // this is bridge
                bridges.push_back({node,child});
            }
        }
    }
}

int32_t main(){
    
   
   
 return 0;
}