#include<bits/stdc++.h>
using namespace std;
   
#define int long long
   
int32_t main(){

    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]={a,b};
    }

    sort(v.begin(),v.end());


    int ans=0;
    int t=0;
    for(int i=0;i<n;i++){
        t+=v[i].first;
        ans+=(v[i].second-t);
        //cout<<ans<<" ";

    }

    cout<<ans;
    
   
   
 return 0;
}