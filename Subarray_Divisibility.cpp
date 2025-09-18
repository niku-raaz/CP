#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int ans=0;
    map<int,int> mp;
    mp[0]++;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        x%=n;
        x=(x+n);
        x%=n;
        sum+=x;
        sum%=n;
        ans+=mp[sum];
        mp[sum]++;
    }

    cout<<ans;

    
   
   
 return 0;
}