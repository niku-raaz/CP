#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;


long long particlect(long long n,long long k,vector<vector<long long>>&dp,long long &l){
    if(k<=0) return 0;
    if(n==0) return 1;
    if(dp[n][k]!=-1) return dp[n][k];

    return dp[n][k]=(particlect(n-1,k,dp,l)+particlect(l-n,k-1,dp,l))%mod;
}




int main()
{
 ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
long int t;
cin>>t;
 while(t--){
    long long n,k;
     cin>>n>>k;

     vector<vector<long long>>dp(1002,vector<long long>(1002,-1));
     cout<<particlect(n,k,dp,n)%mod<<endl;
    }
    return 0;
}