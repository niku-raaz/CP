#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans=0;

    int mx=a[0];

    for(int i=0;i<n;i++){
        mx=max(mx,a[i]);

        if(mx!=a[i]){
            ans++;
        }
    }

    cout<<ans;
    
   
   
 return 0;
}