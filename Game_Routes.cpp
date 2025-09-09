#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
   int n,m;
   cin>>n>>m;

   vector<vector<int>> g(n+1);
   vector<int> inDegree(n+1,0);

   for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;

      g[x].push_back(y);
      inDegree[y]++;
   }

   vector<int> topo;
   queue<int> q;
   for(int i=1;i<=n;i++){
      if(inDegree[i]==0){
         q.push(i);
      }
   }

   
   while(!q.empty()){
      int node=q.front();
      q.pop();
      topo.push_back(node);
      for(auto& child: g[node]){
         inDegree[child]--;
         if(inDegree[child]==0){
            q.push(child);
         }
      }
   }

   vector<int> dp(n+1,0);

   dp[1]=1;
   int mod=1e9+7;

   for(auto& node: topo){
      for(auto& child: g[node]){
         dp[child]+=dp[node];
         dp[child]%=mod;
      }
   }

   cout<<dp[n];


    
   
   
 return 0;
}