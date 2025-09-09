#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n,m;cin>>n>>m;
    vector<string> g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }

    vector<vector<int>> dp(n,vector<int>(m,0));

    if(g[0][0]=='.'){
        dp[0][0]=1;
    }

    int mod=1e9+7;

    for(int i=1;i<n;i++){
        if(g[i][0]=='.') dp[i][0]=dp[i-1][0];
        if(g[0][i]=='.') dp[0][i]=dp[0][i-1];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int left=dp[i][j-1];
            int up=dp[i-1][j];
            if(g[i][j]=='.') dp[i][j]=(left+0LL+up)%mod;

        }
    }




    cout<<dp[n-1][m-1];




    
   
   
 return 0;
}