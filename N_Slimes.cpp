#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[401];
int p[401];
int sum(int l,int r){
    return p[r]-p[l-1];
}

int dp[401][401];

int rec(int l,int r){
    if(l==r){
        return 0;
    }
    if(dp[l][r]!=-1) return dp[l][r];
    
    int ans=1e18;

    for(int mid=l;mid<r;mid++){
        ans=min(ans,(sum(l,r)+rec(l,mid)+rec(mid+1,r)));
    }
    return dp[l][r]= ans;
}


   
   
int32_t main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    p[0]=0;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    memset(dp,-1,sizeof(dp));

    cout<<rec(1,n);



    
   
   
 return 0;
}