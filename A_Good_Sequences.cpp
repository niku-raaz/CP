#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,kk;
int mod=1e9+7;

int dp[2003][2003];


int rec(int ind,int k){
    if(k==1){
        if(ind<=n){
            return 1;
        }
        return 0;
    }

    if(dp[ind][k]!=-1){
        return  dp[ind][k];
    }

    // 
    int ans=0;
    for(int m=1;m<=n;m++){

        //cout<<m<<" "<<m*ind<<endl;
         
       // cout<<m*ind<<" ";
       if(m*(ind)<=n){
         ans+=rec(m*ind,k-1);
         ans%=mod;
       }
       else{
        break;
       }
    }

    return dp[ind][k]=ans;

}
   
   
int32_t main(){

    

    cin>>n;
    cin>>kk;

    memset(dp,-1,sizeof(dp));

   

   

    int ans=0;

    for(int s=1;s<=n;s++){
        int res=rec(s,kk);
        ans+=res;
        ans%=mod;

    }





    cout<<ans;


    //
    
   
   
 return 0;
}