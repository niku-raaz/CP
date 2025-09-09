#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[101];

int dp[100001];


   
   
int32_t main(){
    cin>>n;

    int k;cin>>k;

    
    for(int i=0;i<n;i++) cin>>a[i];

    memset(dp,0,sizeof(dp));

    dp[0]=0; //losing state

    for(int i=1;i<=k;i++){
        int ans=0; // im losing
        // I can win only if I can find a losing state

        int ct=0;
        for(int j=0;j<n;j++){
            int prev=i-a[j];
            if(prev>=0){
               // a valid prev state;
               ct++;
               if(dp[prev]==0){
                ans=1; // I can win
               }
            }
        }

       
        dp[i]=ans;
    }

    cout<<(dp[k]?"First":"Second")<<endl;

    



    
   
   
 return 0;
}