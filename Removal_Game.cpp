#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5001];

int p[5001];

int dp[5001][5001];

int pfx(int l,int r){
  if(l){
    return p[r]-p[l-1];
  }
  return p[r];
}

int rec(int l,int r){
  if(l==r){
    return a[l];
  }
  if(dp[l][r]!=-1e18){
    return dp[l][r];
  }
  return dp[l][r]=max(a[l]-rec(l+1,r)+pfx(l+1,r), a[r]-rec(l,r-1)+pfx(l,r-1));
}


int32_t main(){
  int n;cin>>n;
  
  for(int i=0;i<n;i++)cin>>a[i];

  p[0]=a[0];
  for(int i=1;i<n;i++){
    p[i]=p[i-1]+a[i]; 
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dp[i][j]=-1e18;
    }
  }

  cout<<rec(0,n-1)<<endl;


    
   
   
 return 0;
}