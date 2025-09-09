#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int>& pasangers,vector<vector<int>>& g,vector<int>& dp){

    dp[node]=pasangers[node-1];

    for(auto child: g[node]){
        if(child==par) continue;
        
        dfs(child,node,pasangers,g,dp);
        dp[node]+=dp[child];
    }


    if(pasangers[node-1]==0){

        // do nothing

    }else{
        if(dp[node]!=pasangers[node-1]){
            dp[node]-=1;
    
        }


    }
    



}

int fun(int n,vector<vector<int>>& edges,vector<int>& pasangers){

    vector<vector<int>> g(10);

    for(int i=0;i<n-1;i++){
        int x=edges[i][0];
        int y=edges[i][1];
        g[x].push_back(y);
        g[y].push_back(x);
        

    }

    int root=1;

    vector<int> dp(n+1,0);

    dfs(1,-1,pasangers,g,dp);


   return dp[1];




}
   
int main(){

    int n;
     cin>>n;

     vector<vector<int>> edges(n-1,vector<int>(2));
     vector<int> p(n);
     for(int i=0;i<n;i++){
        cin>>p[i];
     }

     for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[i][0]=x;
        edges[i][1]=y;;

     }

     cout<<fun(n,edges,p);

   
   
 return 0;
}