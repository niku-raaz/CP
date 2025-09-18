#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[i]={y,x};
    }

    sort(v.begin(),v.end());

    // end time k base pe

    int ans=0;
    int curr=0;

    for(int i=0;i<n;i++){
        if(curr<=v[i].second){
            // watch it
            ans++;
            curr=v[i].first;
        }

    }

    cout<<ans;

    
   
   
 return 0;
}