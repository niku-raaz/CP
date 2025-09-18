#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,t;
    cin>>n>>t;

    map<int,int> mp;
    int sum=0;
    mp[0]++;
    int ans=0;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        sum+=x;
        int need=sum-t;
        ans+=mp[need];
        mp[sum]++;
    }

    cout<<ans;
    
   
   
 return 0;
}