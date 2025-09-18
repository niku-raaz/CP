#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    // BS
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    sort(a.begin(),a.end());

    int x=a[(n/2)];

    for(int i=0;i<n;i++){
        ans+=abs(a[i]-x);
    }

    cout<<ans;
    



    
   
   
 return 0;
}