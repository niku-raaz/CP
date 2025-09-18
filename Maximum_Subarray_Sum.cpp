#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    // Max subarrya sum
    // also non empty

    int n;cin>>n;

    int ans=-1e18;

    int curr=0;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        curr+=x;
        ans=max(ans,curr);
        if(curr<0){
            curr=0;
        }
    }

    cout<<ans;
    
   
   
 return 0;
}