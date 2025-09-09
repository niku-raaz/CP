#include<bits/stdc++.h>
using namespace std;
   
   
int main(){

    int n;cin>>n;
    map<int,int> mp;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }

    int ans=1;
    int mod=1e9+7;

    for(auto& it: mp){
        ans=(ans*1LL*(it.second+1))%mod;
    }
    
     cout<<ans-1;
   
 return 0;
}