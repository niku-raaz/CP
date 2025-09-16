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

    vector<vector<int>> dp(n+1,vector<int>(2,-1e9));
    
    // dp[i][0] => max matching without including i
    // dp[i][1] => max matching with including i

    auto dfs=[&](int node,int par,auto && dfs)->void{
             dp[node][0]=0;
              
             for(auto child: g[node]){
                if(child==par) continue;

                dfs(child,node,dfs);
                // if I dont wanna take
                // sum of all via childs
                dp[node][0]+=max(dp[child][0],dp[child][1]);
                // If I want to include 
                // node
                dp[node][1]=max(dp[node][1],min(0LL,dp[child][0]-dp[child][1])); // max extra we can get
             }
             dp[node][1]+=dp[node][0]; // overall addition
             dp[node][1]++;


    };


    dfs(1,-1,dfs);

    cout<<max(dp[1][0],dp[1][1]);

    

    

     
    
   
   
 return 0;
}