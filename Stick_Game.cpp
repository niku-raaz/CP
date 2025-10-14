#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> a(x);
    for(int i=0;i<x;i++){
        cin>>a[i];
    }

    vector<int> dp(n+1,-1);
    // 
    // dp[0]
    dp[0]=0; // losing state
    // Im storing answers 
    // for First Guy // Alice  
    // 1 means alice
    // 0 means bob

    auto dfs=[&](int node,auto && dfs)->int{
        // if all 
        if(node==0){
            return dp[node];
        }
        if(dp[node]!=-1){
            return dp[node];
        }
        int ct=0;
        int tot=0;
        for(auto p: a){
            if(node-p>=0){
               ct+=dfs(node-p,dfs);
               tot++;
            }
        }
        // if all are winning state
        if(ct==tot){
            return dp[node]=0;
            // i will lose
        }
        // at least one losing
        return dp[node]=1;
        
    };



    dfs(n,dfs);
    for(int i=1;i<=n;i++){
        if(dp[i]){
            cout<<"W";
        }else{
            cout<<"L";
        }
    }
    
   
   
 return 0;
}