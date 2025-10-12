#include<bits/stdc++.h>
using namespace std;

#define int long long
   
int32_t main(){
    int n;cin>>n;
    vector<int> a(n);
    int mx=0;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        sum+=a[i];
    }

    int ans=max(sum,2*mx);

    

    


    

    cout<<ans;

    

    


    

 
 return 0;
}