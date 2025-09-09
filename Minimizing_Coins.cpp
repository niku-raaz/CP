#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n; int x;
    cin>>n>>x;
    int mx=1e9;
    int dp[x+1];
    for(int i=1;i<=x;i++) dp[i]=mx;

    
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]<=x) dp[c[i]]=1;
    }
    
    for(int i=1;i<=x;i++){
        for(auto& j: c){
            if(i-j>=1)dp[i]=min(dp[i],1+dp[i-j]);
        }
    }
    if(dp[x]==mx){
        dp[x]=-1;
    }
    cout<<dp[x];
   
 return 0;
}