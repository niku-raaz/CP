#include<bits/stdc++.h>
using namespace std;
#define int long long
 

void solve(){
    int n,k;
    cin>>n>>k;
    int diff=n-k;
    if(diff<=0){
        cout<<0<<endl;
        return;
    }

    // diff> 2*(y+z)
    // even wale hi possible hain

    if(diff&1){
        diff/=2;
    }else{
        diff/=2;
        diff-=1;
    }

    // find the max sum we can create using pair (x,y)
    // such that sum<=diff 
    
    // that sum is diff
    // find the number of ways
    



}
   
int32_t main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
   
   
 return 0;
}