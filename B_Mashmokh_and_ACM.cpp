#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n,k;

int mod=1e9+7;

int dp[2003][2003];



int rec(int i, int ct){
    if(ct==k){
        return 1;
    }
    if(i>n){
        return 0;
    }

    if(dp[i][ct]!=-1){
        return dp[i][ct];
    }
    int ans=0;

    for(int j=1;j*i<=n;j++){
       
       // got to all multiples
       
        ans+=rec(i*j,ct+1);
        ans%=mod;

    }


    return dp[i][ct]=ans;


 
}
   
   
int32_t main(){
    cin>>n;
    cin>>k;
    memset(dp,-1,sizeof(dp));

    cout<<rec(1,0);




 return 0;
}