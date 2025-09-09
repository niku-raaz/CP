#include<bits/stdc++.h>
using namespace std;

int binpow(int a, int b, int mod){
    int ans=1;
    int prod=a;

    for(int i=0;i<=31;i++){

        if(b&(1<<i)){

            ans=(ans*1LL*prod)%mod;
            
           // cout<<prod<<" ";

        }
        prod=(prod*1LL*prod)%mod;
        

    }

    return ans;



}
   
   
int main(){

    int tt;cin>>tt;
    while(tt--){
        int a,b,c;
        cin>>a>>b>>c;

        int mod=1e9+7;

        
        cout<<binpow(a,binpow(b,c,mod-1),mod)<<endl;



    }

    
   
   
 return 0;
}