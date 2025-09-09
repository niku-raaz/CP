#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100005];
int b[100005];

int dp[100005][3];

int rec(int ind,int last){
    if(ind==n){
        return 0;
    }

    if(dp[ind][last]!=-1){
        return dp[ind][last];
    }

    int ans=0;

    if(last!=1){
        // take from 1
        ans=max(ans,rec(ind+1,1)+a[ind]);
        ans=max(ans,rec(ind+1,last));
    }
    if(last!=2){
        ans=max(ans,rec(ind+1,2)+b[ind]);
        ans=max(ans,rec(ind+1,last));
    }

    return dp[ind][last]=ans;
    
}

   
   
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,0);
    
   
   
 return 0;
}