#include<bits/stdc++.h>
using namespace std;


void dfs(int node,vector<vector<int>>& g,vector<int>& dp){
    //cout<<node<<" ";
    if(dp[node]>=0){
        return ;
    }
    if(node==dp.size()-1){
        return;
    }

    for(auto& child: g[node]){
        dfs(child,g,dp);
        if(dp[child]==-1) continue;
        dp[node]=max(dp[node],dp[child]+1);
    }
}


void DFS(int node,vector<vector<int>>& g,vector<int>& dp,vector<int>& ans){

    ans.push_back(node);
    int need=dp[node]-1;
    if(node==dp.size()-1){
        return;
    }
    for(auto& child: g[node]){
        if(dp[child]==need){
            DFS(child,g,dp,ans);
            break;
        }
    }
}


   
int32_t main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> inDegree(n+1,0);

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        inDegree[y]++;

        g[x].push_back(y);
    }

    // I dont need DFS

    // 
    // 

    queue<int> q;

    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;

   

    vector<int> ans;

    int d=0;

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



    // Lets calculte Distance 
    // and also the parent to retrace the path
    vector<int> dp(n+1,-1e9);
    vector<int> par(n+1,0);

    dp[1]=0;

    for(auto& u: topo){
        if(dp[u]==(-1e9)) continue;
        for(auto& v: g[u]){
            if(dp[v]<dp[u]+1){
                dp[v]=dp[u]+1;
                par[v]=u;
            }
        }
    }

     
    if(dp[n]==(-1e9)){
        cout<<"IMPOSSIBLE";
    }else{

        cout<<dp[n]+1<<endl;
        vector<int> v;
        int curr=n;

        while(par[curr]!=0){
            v.push_back(curr);
            curr=par[curr];
        }
        v.push_back(1);
        reverse(v.begin(),v.end());

        for(auto& x: v){
            cout<<x<<" ";
        }
    }


    


    




   





    
   
   
 return 0;
}