#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MX=100000;
vector<int> fac[MX+1];

void solve(){

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> ans(n,-1);

    vector<int> mp(MX+1,-1);

    // mp[x] => what is the max index where this x 
    // is presenct as a factor
    
    for(int i=0;i<n;i++){
        int x=a[i];

        int mx=-1;
        for(auto div: fac[x]){
            mx=max(mx,mp[div]);
            mp[div]=max(mp[div],i);
        }

        ans[i]=mx;
    }

    // lmao
    // I calc. previous no-coprime element
    // I need previous coprime
    

    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;




}
   
   
int32_t main(){
    int tt;
    cin>>tt;

    for(int i=2;i<=MX;i++){
        for(int j=i;j<=MX;j+=i){
            fac[j].push_back(i);
        }
    }

    while(tt--){
        solve();
    }
    
   
   
 return 0;
}