#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[101];
int dp[102][100001];

   
   
int32_t main(){

    int k;
    cin>>n>>k;
    int mod=1e9+7;

    memset(dp,0,sizeof(dp));

    int pfx[100001];

    memset(pfx,0,sizeof(pfx));

    for(int i=0;i<n;i++)cin>>a[i];


    for(int i=0;i<=a[0];i++){
       dp[0][i]=1;
    }

   pfx[0]=dp[0][0];
   for(int i=1;i<=k;i++){
    pfx[i]=pfx[i-1]+dp[0][i];
    pfx[i]%=mod;
   }


   for(int i=1;i<n;i++){
    // for(int j=0;j<=k;j++){
    //     cout<<pfx[j]<<" ";
    // }cout<<endl;
    for(int j=0;j<=k;j++){

        int ans=0;
        // ans= sum(dp[i-1][j-0.......j-a[i]])

        ans=pfx[j];
        
        if(j-a[i]>0){
            ans=(ans+mod-pfx[j-a[i]-1])%mod;
        }

        dp[i][j]=ans;


    }

    pfx[0]=dp[i][0];
    for(int j=1;j<=k;j++){
        pfx[j]=pfx[j-1]+dp[i][j];
        pfx[j]%=mod;
    }


   }

   cout<<dp[n-1][k]<<endl;


//    for(int i=0;i<n;i++){
//     for(int j=0;j<=k;j++){
//         cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
//    }



    
   
   
 return 0;
}