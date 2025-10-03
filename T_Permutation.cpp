#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;

    string s;cin>>s; // of n-1 size
    s="##"+s;

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    // dp[i][j] = # ways till ith index such that # of elements  
    //             smaller than last taken elemenet
    //             in not-taken element set is j

    int mod=1e9+7;

    for(int j=0;j<n;j++){
        dp[1][j]=1; 
    }

    for(int i=2;i<=n;i++){

        if(s[i]=='<'){
            // increasing
            int sum=0;
            for(int j=0;j<=n-i;j++){
                sum+=dp[i-1][j];
                sum%=mod;
                dp[i][j]=sum;
            }
        }else{
            // decresing
            int sum=dp[i-1][n-i+1];

            for(int j=(n-i);j>=0;j--){
               dp[i][j]=sum;
               sum+=dp[i-1][j];
               sum%=mod;
            }
        }

    }

    cout<<dp[n][0];

    
   
   
 return 0;
}