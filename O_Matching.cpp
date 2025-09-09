#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[22][22];
int dp[22][1<<22];

int mod=1e9+7;

int rec(int ind,int mask){
    if(ind==n){
        if(mask==(1<<n)-1){
            return 1;
        }
        return 0;
    }
    if(dp[ind][mask]!=-1){
        return dp[ind][mask];
    }
    int ways=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0 && a[ind][i]==1){
            ways+=rec(ind+1,mask|(1<<i));
            ways%=mod;
        }
    }
    return dp[ind][mask]=ways;

}
   


   
int32_t main(){

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    return 0;
}