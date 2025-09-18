#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int inv2=500000004;
int f(int start,int end){
               int res=(((end+start)%mod)*((end-start+1)%mod))%mod;;
               res%=mod;
               res*=inv2;
               res%=mod;
               return res;
}  
   
int32_t main(){

    int n;cin>>n;

    int ans=0;

    int i=1;
    while(i<=n){
        int ct=n/i;
        int nxt=n/ct;

        ans+=(ct*f(i,nxt));
        ans%=mod;

        i=nxt+1;
    }

    cout<<ans;

    
   
   
 return 0;
}