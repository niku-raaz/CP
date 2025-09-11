#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001][3];

int vis[100001][3];
int inf=-4e18;

int rec(int ind,int j,vector<int>& a,vector<int>& t){
    int n=a.size();
    if(j==3){
        return 0;
    }
    if(ind==n){
       if(j==3){
        return 0;
       }
       return inf;
    }
   



    // take
    

    if(vis[ind][j]!=0){
        return  dp[ind][j];
    }


    int ans=inf;
    

    ans=max(ans,rec(ind,j+1,a,t)+(a[ind]*t[j]));
    ans=max(ans,rec(ind+1,j,a,t));
    vis[ind][j]=1;
    return dp[ind][j]=ans;
}
   
   
int32_t main(){
    int n;cin>>n;
    int p,q,r;
    cin>>p>>q>>r;

    vector<int> a(n);
    vector<int> t={p,q,r};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    memset(vis,0,sizeof(vis));

    

   cout<<rec(0,0,a,t);

   



    
   
   
 return 0;
}