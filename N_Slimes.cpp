#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    
   
   int n;
   cin >> n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];

   int dp[n+1][n+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=n;j++){
           dp[i][j] = 1e16;
       }
   }
   for(int i=0;i<n;i++){
       dp[i][i] = 0;
   }

   int s[n];
   s[0] = a[0];
   for(int i=1;i<n;i++) s[i] = s[i-1]+a[i];

   auto sum=[&](int l,int r)->int{
       return s[r] - (l > 0 ? s[l-1] : 0);
   };
   

   for(int r=1;r<n;r++){
    for(int l=r-1;l>=0;l--){
        int mn=1e18+3;

        for(int mid=l;mid<r;mid++){
            mn = min(mn, dp[l][mid] + dp[mid+1][r] +sum(l,r));
        }

        dp[l][r] = mn;


    }
   }

   cout<<dp[0][n-1] << endl;




}