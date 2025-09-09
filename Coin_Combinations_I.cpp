#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int f(vector<int>& c,int sum){
    int n=c.size();
    int x=sum;
    int dp[x+1]={0}; dp[0]=1;
   

    for(int i=0;i<=x;i++){
        for(int j=0;j<n && i+c[j]<=x;j++){
            dp[i+c[j]]=(dp[i+c[j]]+0LL+dp[i])%mod;
        }
    }

    return dp[x];
}

   
   
int main(){
    int n;cin>>n;
    int x;cin>>x;
    int dp[x+1]={0}; dp[0]=1;
    
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);

    for(int i=0;i<=x;i++){
        for(int j=0;j<n && i+c[j]<=x;j++){
            dp[i+c[j]]=(dp[i+c[j]]+0LL+dp[i])%mod;
        }
    }

    cout<<dp[x];

 return 0;
}