#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    int mod=1e9+7;

    int ans=1;

    for(auto it: mp){
        ans*=(it.second+1);
        ans%=mod;
    }

    cout<<(ans-1+mod)%mod;
    
   
   
 return 0;
}