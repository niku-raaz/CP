#include<bits/stdc++.h>
using namespace std;
#define int long long
   

void solve(){

    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // Can do BS definately
    int mx=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            int diff=a[i-1]-a[i];
            int ct=0;
            while(diff){
                ct++;
                diff/=2;
            }
            a[i]=a[i-1];
            mx=max(mx,ct);
        }
    }

    cout<<mx<<"\n";

}
   
int32_t main(){

    int tt;cin>>tt;

    while(tt--){
        solve();
    }
    
   
   
 return 0;
}