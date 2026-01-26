#include<bits/stdc++.h>
using namespace std;
#define int long long
int MX=100000;
vector<int> phi(MX+1);

void pre(){

    for(int i=1;i<=MX;i++){
        phi[i]=i;
    }
    for(int i=2;i<=MX;i++){
        if(phi[i]==i){
            for(int j=i;j<=MX;j+=i){
                phi[j]-=phi[j]/i;  
            }
        }
    }

}
int mod=1e9+7;
void solve(){

    int n;cin>>n;

    // for(int i=1;i<=n;i++){
    //     cout<<phi[i]<<" ";
    // }
    
    int pfx=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        pfx+=phi[i];
        pfx%=mod;
        ans+=pfx*phi[i];
        ans%=mod;
    }
    cout<<ans<<endl;



}
   
int32_t main(){
    int tt;
    cin>>tt;
    pre();
    while(tt--){
        solve();
    }
    
   
   
 return 0;
}