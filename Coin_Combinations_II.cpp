#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n,x;
    cin>>n>>x;

    int dp[x+1]={0};
    int c[n];

    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);
    
    dp[0]=1;
    int mod=1e9+7;

    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            if(j-c[i]>=0){
               dp[j]=(dp[j]+0LL+dp[j-c[i]])%mod;
            }
        }
    }

    cout<<dp[x];
    
   
   
 return 0;
}