#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[2003];
int dp[2003][2003];
int rec(int l,int r){
    if(l==r){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=1e14;
    // with l+1
    ans=min(ans,rec(l+1,r)+(a[r]-a[l]));

    // or r-1
    ans=min(ans,rec(l,r-1)+(a[r]-a[l]));

    return dp[l][r]= ans;


}
   
   
int32_t main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    sort(a,a+n);
    memset(dp,-1,sizeof(dp));
    //
    // Sort and the use LR DP ig
    //vector<vector<int>> dp(n,vector<int>(n,0));

    //dp[i][i]=0;

    cout<<rec(0,n-1);



    
   
   
 return 0;
}