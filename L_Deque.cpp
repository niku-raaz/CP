#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[3001];


   
   
int32_t main(){

    // 
    //
    int n;cin>>n;
    
    for(int i=0;i<n;i++)cin>>a[i];

    int dp1[n][n]; // stores max X+Y
    //int dp2[n][n]; // stores min X-Y

    memset(dp1,0,sizeof(dp1));
   // memset(dp2,0,sizeof(dp2));

    for(int i=0;i<n;i++){
        dp1[i][i]=a[i];
    }

    for(int r=1;r<n;r++){
        for(int l=r-1;l>=0;l--){
           // 
           // I want to calculate min X-Y from a[L,R]

           // I have two options
           // 1. Take a[L] and add it to the result
           dp1[l][r]=max(a[l]-dp1[l+1][r],a[r]-dp1[l][r-1]);
           // 2. Take a[R] and add it to the result
           //dp2[l][r]=min(a[l]-dp2[l+1][r],a[r]-dp2[l][r-1]);
        }
    }

    cout<<dp1[0][n-1]<<endl;;
    // cout<<dp2[0][n-1]<<endl;;

    // cout<<rec(0,n-1,0)<<endl;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    
   
   
 return 0;
}